/* HW6 read cafefully and follow all the instructions/comments
   this program compiles and runs as is although it's not doing much.
   DO NOT CHANGE THE SEED. Changing seed gives a different sequence of
   numbers but we want the same numbers for comparison purposes.

   FLOATING point radix sort requires some substantial changes to this code
   float n, lst[N],tmp[N];	
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define OK 1
#define NOK 0
#define NELM 100		/* default 100 elements */
//#define N 1048576		/* OLD SEED 1048576 2^30 or 1 meg elements  */
//#define N 2097152
//#define N 4194304
//#define N 8388608
//#define N 16777216
#define N 335544320

void selection_sort();
//void swap();

void merge_sort();
void msort_recursive();

void int_radix_sort();
void float_radix_sort();
//void swap();
void self_check();
void merge();
int findLargestNum();
void gettimeofday();

//int rand(void);
//void srand();
//int rand_r();
void init_lst();
void print_lst();

int n, lst[N],tmp[N];

int main(int argc,char **argv) {

  long int del_sec,del_msec;
  struct timeval tv_s,tv_e;

  if (argc>1) n = atoi(argv[1]); // Check if there is an arugment passed and take integer rep of 1st arg
  else n = NELM;  // Else set n=100

  printf("n=%d\n",n); // Print the size of the lst

  init_lst(lst,n); // Generates random numbers into the lst

  //print_lst(lst,n); // Traverse and prints each lst element
/*
  gettimeofday(&tv_s, NULL); 
    selection_sort(lst,n); //DONE
  gettimeofday(&tv_e, NULL); 
  printf("Selection Sort Time Elapsed: %ld.", (tv_e.tv_sec - tv_s.tv_sec)  );
  printf("%ld\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec) / 1000)) );

  gettimeofday(&tv_s, NULL); 
    merge_sort(lst,tmp,n);
  gettimeofday(&tv_e, NULL); 
  printf("Merge Sort Time Elapsed: %ld.", (tv_e.tv_sec - tv_s.tv_sec)  );
  printf("%ld\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec) / 1000)) );
*/
  gettimeofday(&tv_s, NULL); 
    int_radix_sort(lst,n);  
  gettimeofday(&tv_e, NULL); 
  printf("Radix Sort Time Elapsed: %ld.", (tv_e.tv_sec - tv_s.tv_sec)  );
  printf("%ld\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec) / 1000)) );
  //  float_radix_sort(lst,tmp,n);
  //gettimeofday(&tv_e, NULL); 

  //print_lst(lst,n); // Traverse and prints each lst element

  /****
    PRINT elapsed time in sec and milli secs
  ****/

  //  print_lst(lst,n);
  self_check();
  return 0;
}

void selection_sort(int list[],int n){

  /* 

  list=[4,9,5,7,0]

  For i=minIndex=0 => lst[0] = 4
  1) When j=1 => lst[j] < lst[minIndex] => lst[9] < lst[4] => NO
  2) When j=2 => lst[j] < lst[minIndex] => lst[5] < lst[4] => NO
  3) When j=3 => lst[j] < lst[minIndex] => lst[7] < lst[4] => NO
  4) When j=4 => lst[j] < lst[minIndex] => lst[0] < lst[4] => YES
      minIndex = j
  5) tempElement=lst[i] => tempElement = 4
  6) lst[i] = lst[minIndex] => lst[0] = lst[4]
  7) lst[minIndex] = tempElement => lst[4] = 4 

  SKIP i=1

  list=[0,4,5,7,9]
  For i=minIndex=2 => lst[2] = 5
  1) When j=1 => lst[j] < lst[minIndex] => lst[0] < lst[5] => YES WRONG 
    j=1 BUG
    j=i+1 BUG FIX


  */


    int i=0;
    int j=0;
    int minIndex=0;
    int tempElement=0;

    // Traverse the lst and mark 1st element as smallest element
    for(i=0; i<n-1; i++){
      minIndex= i;

    // Traverse the lst and check each element if it is smaller than marked element i.e minIndex
    for(j=i+1; j<n; j++){
      if(list[j] < list[minIndex]){
        minIndex=j;
      }
    }
    
    // Swap the new smallest element to its appropriate location list[i] 
      if(minIndex != i){ // To avoid swapping with itself if no greater element found
      tempElement=list[i];
      list[i]=list[minIndex];
      list[minIndex]=tempElement;
      }
    }
}

void merge_sort(int list[], int temp[], int n){

  /*
  Step 1 − if it is only one element in the list it is already sorted, return.
  Step 2 − divide the list recursively into two halves until it can no more be divided.
  Step 3 − merge the smaller lists into new list in sorted order.
  */

  msort_recursive(list, temp, 0, n-1);
}

void msort_recursive(int list[], int temp[], int left, int right){
 
  if(left < right){   // Base case: Checks if there is more than 1 element 

  // Find the middle point to divide the listay into two halves: middle m = (l+r)/2
  int middle= (left+right) / 2;

  msort_recursive(list, temp, left, middle);
  msort_recursive(list, temp, middle+1, right);
  merge(list, temp, left, middle, middle+1, right);
  

  }
}

void merge(int a[], int temp[], int i1, int j1, int i2, int j2){
  int i,j,k;
      i=i1;    //beginning of the first list
      j=i2;    //beginning of the second list
      k=0;

      
      while(i<=j1 && j<=j2)    //while elements in both lists
      {
          if(a[i]<a[j])
              temp[k++]=a[i++];
          else
              temp[k++]=a[j++];
      }
      
      while(i<=j1){   //copy remaining elements of the first list
          temp[k++]=a[i++];
      }    
      while(j<=j2){    //copy remaining elements of the second list
          temp[k++]=a[j++];
      }    
      //Transfer elements from temp[] back to a[]
      for(i=i1,j=0;i<=j2;i++,j++){
          a[i]=temp[j];
      }
}

//fix the bucket size to 256. run 4 passes where each pass processes 8 bits
//use lst and tmp only. do not use any more memory of size n.
void radix_sort(int ii) {
  int group=8;			/* 8 bits per pass (or round) */
  int bucket = 1 << group;	/* number of buckets = 256 */
  // fill here
}

int findLargestNum(int * array, int size){
  
  int i;
  int largestNum = -1;
  
  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }
  
  return largestNum;
}

void int_radix_sort(int array[], int size){

  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  
  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){
    
    int bucket[10] = { 0 };
    
    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    
    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
     * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    
    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];
    
    
    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];
    
    // Move to next significant digit
    significantDigit *= 10;

  }
}

void print_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d ",l[i]);
  }
  printf("\n");
}

void init_lst(int *l,int n){
  int i;
  //  int seed = time(0) % 100;	/* seconds since 1/1/1970 */
  //  printf ("seed=%d\n", seed);
  srand(1234);			/* SEED OLD 1234*/
  for (i=0; i<n; i++) {
    l[i] = rand() % 10;
  }
}

void self_check(int *list,int n) {
  int i,j,flag=OK,*listp;

  listp = list;
  for (i=0;i<n-1;i++)
     if (listp[i] > listp[i+1]) { flag = NOK; break; }

  if (flag == OK) printf("sorted\n");
  else printf("NOT sorted at %d\n",i);
}
