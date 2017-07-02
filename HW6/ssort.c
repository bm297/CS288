#include <stdio.h>

#define N 10 // NELEM

void selectionSort();
void print_lst();

int main(){
	
	int array[] = {9,1,5,2,4,8,3,10,25,19};
	int temp[N];
	selectionSort(array,N);
	print_lst(array,N);
	printf("\n");

}

// BUG array[j] < array[i] IS WRONG
void selectionSort(int array[], int n){
	
	int i=0;
	int j=0;
	int minIndex=0;
	int tempElement=0;

	for(i=0; i<n-1; i++){
		minIndex = i;
		for(j=i+1; j<n; j++){
			if(array[j] < array[minIndex]) minIndex=j;
		}

		// Swap minIndex with proper position
		if(minIndex != i){ // Avoid copying itself if no smaller element encountered
			tempElement=array[i];
			array[i]=array[minIndex];
			array[minIndex]=tempElement;
		}
	}
}

void print_lst(int array[], int n){
	int i=0;
	for(i=0; i<n; i++){
		printf("%d ", array[i]);
	}

}