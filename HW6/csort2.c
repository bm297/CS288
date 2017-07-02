#include <stdio.h>

#define N 10 //NELEM

void csort();
void printArray();

int main(){

	int array[N] = {2,1,5,6,3,7,8,9,0,4};
	csort(array, N);
	printArray(array, N);

	return 0;
}

void csort(int a[], int n){

	int count[n];
	int output[n];
	int i=0;

	for(i=0; i<n; i++){
		count[i]=0;
		output[i]=0;
	}

	for(i=0; i<n; i++){
		++count[a[i]];
	}

	for(i=1; i<=n; i++){
		count[i] += count[i-1];
	}

	for(i=0; i<n; i++){
		output[count[a[i]]-1] =a[i];
		--count[a[i]];
	}

	for(i=0; i<n; i++){
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