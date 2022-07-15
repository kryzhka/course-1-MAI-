#!/bin/bash
if [ "$1" == ? ]
	then
	echo "Please enter ./generatefiles.sh [syffix] [count of test] [count of days] "
	exit
elif [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]
	then
	echo "Not all parameters are entered"
	echo "Please enter ./generatefiles.sh [syffix] [count of test] [count of days] "
else
	c=$2
	date_today=$(date +%s)
	date=$(( $date_today - $3*86400 ))
	date=$(date +%F -d "@$date")
	while [[ $c -gt 0 ]]
		do touch $c.$1
		touch -ad  "$date" $c.$1 
		c=$(( $c - 1 ))
	done
fi