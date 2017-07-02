#include <stdio.h>

#define N 10 // # of elements

void printArray();
void msort();
void msort_recursive();
void merge();

int main(){

	int array[] = {9,5,1,3,7,6,2,8,10,0};
	printArray(array, N);

	msort(array, N);
	printArray(array, N);
}

void printArray(int a[], int n){
	int i=0;
	for(i=0; i<n; i++){ printf("%d ", a[i]);}
	printf("\n");
}

void msort(int array[], int n){
	int temp[n]; // temp array
	msort_recursive(array, temp, 0, n-1);
}

void msort_recursive(int lst[], int temp[], int left, int right){
	if(left < right){ //Base case: the array has at least 2 elements
		int middle= (left+right)/2; //Truncate
		msort_recursive(lst, temp, left, middle);
		msort_recursive(lst, temp, middle+1, right);
		merge(lst, temp, left, middle, middle+1, right);
	}
}

void merge(int a[], int temp[], int left, int middle, int middle2, int right){

	int i=left; //first element in first array
	int j=middle2; //first element in second array
	int k=0; //current index

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