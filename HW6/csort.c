/*
For simplicity, consider the data in the range 0 to 9. 
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index 
  stores the sum of previous counts. 
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in 
the output sequence.
 
  3) Output each object from the input sequence followed by 
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place 
  next data 1 at an index 1 smaller than this index.
*/

#include <stdio.h>

#define N 10 //NELEM

void countSort();
void printArray();

int main(){

	int array[N] = {4,1,1,4,9,6,8,7,5,3};
	countSort(array, N);
	printArray(array, N);

	return 0;
}

void countSort(int a[], int n){

	int count[n]; //Count array to store individual elements
	int output[n]; //Store sorted items
	int i=0;

    // ALWAYS INITIALIZE YOUR ARRAYS
	for(i=0; i<n; i++){
		count[i]=0;
		output[i]=0;
	}

	for(i=0; i<n; i++){ //Store count of each character
		++count[a[i]];
	}

	for(i=1; i<=n; i++){ //Update connt[i] to store actual position of this int in the output array
		count[i] += count[i-1];
	}

	for(i=0; i<n; i++){ //Build output array
		output[count[a[i]]-1] = a[i];
		--count[a[i]]; //Decrease count by 1 
	}

	for(i=0; i<n; i++){ //Copy output(sorted array) array to a[]
		a[i]=output[i];
	}
}

void printArray(int a[], int n){
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}