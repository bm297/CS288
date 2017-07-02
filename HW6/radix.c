#include <stdio.h>

#define N 10 //NELEM

int getMax();
void ccsort();
void rsort();
void printArray();

int main(){

	int array[N] = {100, 20, 1, 5, 0, 45, 99, 0, 6, 2};
	rsort(array, N);
	printArray(array, N);

	return 0;
}

void rsort(int a[], int n){

	int max = getMax(a, n);
	
	for(int exp = 1; max/exp>0; exp *= 10){	
		ccsort(a, n, exp);
	}
}

int getMax(int a[], int n){
	int max = a[0];
	int i=0;
	for(i=0; i<n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}

	return max;
}

void ccsort(int a[], int n, int exp){

	int count[n];
	int output[n];
	int i=0;

	for(i=0; i<n; i++){
		count[i]=0;
		output[i]=0;
	}

	for(i=0; i<n; i++){
		++count[ (a[i]/exp)%10 ];
	}

	for(i=1; i<=n; i++){
		count[i] += count[i-1];
	}

	for(i=n-1; i>=0; i--){
		output[ count [(a[i]/exp) %10] -1] = a[i];
		--count[ (a[i]/exp) %10];
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