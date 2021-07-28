#!/bin/sh
# change to working directory to location of command file: http://hints.macworld.com/article.php?story=20041217111834902
here="`dirname \"$0\"`"
cd "$here" || exit 1

APP_NAME=gui
#customize the next three lines and comment out the "exit 1"
CODE_SIGN_SIGNATURE="Developer ID Application: Your Name"
APPLE_ID_USER=youremail@google.com
APP_SPECIFIC_PASSWORD=your-apps-pass-word
echo Edit the variables CODE_SIGN_SIGNATURE APPLE_ID_USER APP_SPECIFIC_PASSWORD and remove this line!; exit 1

#cleanup
rm -rf backup
rm -rf lib

#build X86
lazbuild -B --cpu=x86_64 --ws=cocoa gui.lpr
strip ./gui
mv ./gui ./guiX86

#build ARM64
lazbuild -B --cpu=aarch64 --ws=cocoa gui.lpr
strip ./gui
mv ./gui ./guiARM

#create universal executable
lipo -create -output ./gui ./guiARM ./guiX86 
# you could now run "file ./gui" to confirm universal binary

#clean up
wait
rm guiARM
rm guiX86
rm -rf backup
rm -rf lib

#create the application package
mkdir -p distro
cp -a ./gui.app ./distro
rm -f ./distro/gui.app/Contents/MacOS/gui
cp -f ./gui ./distro/gui.app/Contents/MacOS/gui
ln -s /Applications/ ./distro/Applications

cd distro

#https://stackoverflow.com/questions/2870992/automatic-exit-from-bash-shell-script-on-error
# terminate on error
set -e

xattr -cr ${APP_NAME}.app


echo "Code signing ${APP_NAME}..."
codesign -vvv --force --deep --strict --options=runtime --timestamp  -s "Developer ID Application: Christopher Rorden" ${APP_NAME}.app
codesign -vvvv --deep --strict ${APP_NAME}.app
codesign -dv --verbose=4 ${APP_NAME}.app

cd ..
# Clean up temporary files
rm -f ${APP_NAME}_macOS.dmg
rm -f upload_log_file.txt
rm -f request_log_file.txt
rm -f log_file.txt

hdiutil create -volname ${APP_NAME} -srcfolder ./distro -ov -format UDZO -layout SPUD -fs HFS+J  ${APP_NAME}_macOS.dmg


codesign -s "$CODE_SIGN_SIGNATURE" ${APP_NAME}_macOS.dmg
# Notarizing with Apple...

echo "Uploading..."
xcrun altool --notarize-app -t osx --file ${APP_NAME}_macOS.dmg --primary-bundle-id com.mricro.${APP_NAME} -u $APPLE_ID_USER -p $APP_SPECIFIC_PASSWORD --output-format xml > upload_log_file.txt

# WARNING: if there is a 'product-errors' key in upload_log_file.txt something went wrong
# we could parse it here and bail but not sure how to check for keys existing with PListBuddy
# /usr/libexec/PlistBuddy -c "Print :product-errors:0:message" upload_log_file.txt

# now we need to query apple's server to the status of notarization
# when the "xcrun altool --notarize-app" command is finished the output plist
# will contain a notarization-upload->RequestUUID key which we can use to check status
echo "Checking status..."
sleep 20
REQUEST_UUID=`/usr/libexec/PlistBuddy -c "Print :notarization-upload:RequestUUID" upload_log_file.txt`
while true; do
  xcrun altool --notarization-info $REQUEST_UUID -u $APPLE_ID_USER -p $APP_SPECIFIC_PASSWORD --output-format xml > request_log_file.txt
  # parse the request plist for the notarization-info->Status Code key which will
  # be set to "success" if the package was notarized
  STATUS=`/usr/libexec/PlistBuddy -c "Print :notarization-info:Status" request_log_file.txt`
  if [ "$STATUS" != "in progress" ]; then
    break
  fi
  # echo $STATUS
  echo "$STATUS"
  sleep 10
done

# download the log file to view any issues
/usr/bin/curl -o log_file.txt `/usr/libexec/PlistBuddy -c "Print :notarization-info:LogFileURL" request_log_file.txt`

# staple
echo "Stapling..."
xcrun stapler staple ${APP_NAME}_macOS.dmg
xcrun stapler validate ${APP_NAME}_macOS.dmg

open log_file.txt
