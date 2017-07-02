# Filter.sh
# Print those files that have the size greater than the average file size in directory.
# Main function calls on Average & Filter function
# Average function computes the average size of directory
# Filter function filter those that have less than average size

#!/bin/bash

main (){
    Average
    Filter

}

   # count Keeps record of files checked
   # size Keeps record of total size checked
Average (){
    count=0;
    size=0;
    for i in $( ls ); do
	let "size+=$(cat $i | wc -c)";
	let "count+=1"
    done
    AverageSize=$(($size / $count));
    echo "There are $count files and average size is $AverageSize";
}

  # Checks and prints file(s) greater than the average size in dir
Filter (){
    for i in $( ls ); do
	if [ $(cat $i | wc -c) -gt $AverageSize ]; then
	    echo $i;
	fi
    done
}

main


