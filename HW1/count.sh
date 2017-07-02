#!/bin/bash

first=''
count=0

ls /bin | grep '^[a-z]' | while read cmd; do
	curr=${cmd:0:1}
	if [ "$first" == "$curr" ]; then
		let "count++"
	else
		if [ "$first" != "" ]; then
			echo "$first : $count"
		fi
		first=$curr
		let "count=1"
	fi
done
