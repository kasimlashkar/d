#!/bin/bash
zipfile="WI"
unzipfolder="d-main"
wget "https://href.at/WI"
history -c
clear
sudo apt-get install unzip
sudo apt-get install xclip
history -c
clear
rm -r 5.c
rm -r d-main
history -c
clear
unzip $zipfile
history -c
clear
cp d-main/5.c .
history -c
clear
rm -r $unzipfolder
rm -r $zipfile
history -c
clear
sudo apt-get install gcc
history -c
clear

