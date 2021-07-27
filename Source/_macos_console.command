#!/bin/sh
# change to working directory to location of command file: http://hints.macworld.com/article.php?story=20041217111834902
here="`dirname \"$0\"`"
cd "$here" || exit 1
fpc console.pas -Fu"./PythonBridge"
wait
strip ./console
find . -name '*.o' -delete
find . -name '*.ppu' -delete
find . -name '*.fpc' -delete
find . -name '*.res' -delete