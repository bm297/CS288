#!/bin/bash

ls | {
	while read item; do
		items+=($item)
	done

	len=${#items[@]}
	echo $len
	while [ $len -gt 0 ]; do
		((len--))
		echo ${items[len]}
	done
}
