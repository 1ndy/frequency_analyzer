#!/bin/sh
#untested but hopefully works
#if it doesn't then consider this the install guide
if ! [ $(id -u) = 0 ]; then
	echo "Must be run as root. Exiting"
	exit 1
fi

make
mv frequencyanalyzer /bin
mv frequencycrack /bin

