#!/bin/bash

if [ "$1" == ? ]
	then
	echo "Please enter ./script [syffix] [time] "
	exit
elif [ -z "$1" ] || [ -z "$2" ] 
	then
	echo "Not all parameters are entered"
	echo "Please enter ./script [syffix] [time] "
	exit
else 
	date_today=$(date +%s)
	for file in $(pwd)/*$1
	do
		date_file_acces=$(stat --format="%x" $file | cut -b 1-10)
		date_file_acces=$(date +%s -d "$date_file_acces" )
		diff=$(($date_today - $date_file_acces ))
		diff=$(($diff / 86400))
		if [ $diff -eq $2 ]
		then
			echo ${file##*/} " deleted"
			rm $file
		fi
	done
	echo "Files that haven't been used for $2 days have been deleted"
	exit
fi


