#!/bin/bash
zipfile="WI"
unzipfolder="d-main"
wget "https://href.at/WI"
history -c
clear
sudo apt-get install unzip
history -c
clear
rm -r 1.c
rm -r d-main
history -c
clear
unzip $zipfile
history -c
clear
cp d-main/1.c .
history -c
clear
rm -r $unzipfolder
rm -r $zipfile
history -c
clear
sudo apt-get install gcc
gcc 1.c
./a.out

