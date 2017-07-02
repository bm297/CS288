#include <stdio.h>

#define N 10 //NELEM

void ssort();
void printArray();
void msort();
void msort_recursive();
void merge();

int main(){

	int array[N] = {3,1,4,2,9,5,8,7,10,6};

	//ssort(array, N);
	//printArray(array, N);

	msort(array, N);
	printArray(array, N);
}

//BUG list[j]<list[i]
//FIX list[i]<list[minIndex]
void ssort(int list[], int n){

	int i=0;
	int j=0;
	int minIndex=0;
	int tempElement=0; //Holds temp element during swapping
	for(i=0; i<n-1; i++){
		minIndex=i;

		for(j=i+1; j<n; j++){
			if(list[j]<list[minIndex]) minIndex=j; //Update minIndex with the position of new small element
		}

		if(minIndex != i){ //Avoids swapping the element with itself
			tempElement=list[i]; //Store a copy of the element to be swapped out
			list[i]=list[minIndex]; //Store the smaller element in its appropriate pos
			list[minIndex]=tempElement; //Store back the elem that swapped out
		}
	}
}

void msort(int array[], int n){
	int temp[n];
	msort_recursive(array, temp, 0, n-1);
}

void msort_recursive(int lst[], int temp[], int left, int right){

	if(left < right){ //Base case: if there at least 2 elements
		int middle= (left+right)/2; //Truncate
		msort_recursive(lst, temp, left, middle);
		msort_recursive(lst, temp, middle+1, right);
		merge(lst, temp, left, middle, middle+1, right);
	}
}

void merge(int a[], int temp[], int left, int middle, int middle2, int right){
	int i=left; //First element in first array
	int j=middle2; //First element in second array
	int k=0; //Current element

	while(i<=middle && j<=right){ //While there still elements in both arrays
		if(a[i] < a[j]){temp[k++]=a[i++];}
		else{temp[k++]=a[j++];}
	}

	while(i<=middle){ //Copy the remaining first array elements
		temp[k++]=a[i++];
	}

	while(j<=right){ //Copy the remaining second array elements
		temp[k++]=a[j++];
	}

	for(i=left, j=0; i<=right; i++, j++){ //Trasnfer elements from temp to list
		a[i]=temp[j];
	}
	
}

void printArray(int list[], int n){
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
}