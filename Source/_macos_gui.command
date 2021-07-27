#!/bin/sh
# change to working directory to location of command file: http://hints.macworld.com/article.php?story=20041217111834902
here="`dirname \"$0\"`"
cd "$here" || exit 1
#lazbuild -B gui.lpi --ws=cocoa

#lazbuild -B --cpu=x86_64  --ws=cocoa PyBridge.lpr
lazbuild -B --cpu=x86_64 --ws=cocoa gui.lpr
strip ./gui
mv ./gui ./guiX86
lazbuild -B --cpu=aarch64 --ws=cocoa gui.lpr
strip ./gui
mv ./gui ./guiARM

lipo -create -output ./gui ./guiARM ./guiX86 

wait
strip ./gui
rm -rf backup
rm -rf lib