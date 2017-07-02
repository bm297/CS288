#!/bin/bash

vals=()

for param in $@; do
	cursor=0
	for value in ${vals[@]}; do
		if [ $param -le $value ]; then
			temp=${vals[$cursor]}
			vals[$cursor]=$param
			param=$temp
		fi
		let cursor++
	done
	vals+=($param)
done

echo ${vals[@]}
