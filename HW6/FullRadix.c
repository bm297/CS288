#include <stdio.h>

#define MAXBIT 32
#define LST 1
#define BUF 0
#define BIN 256
int n;
int group = 8;
int flag;


void int_radix_sort();
void print_lst();

int main() {

  	int_radix_sort();
	print_lst(lst,n);

	return 0;
}

void int_radix_sort(){	

	int n, group=8; 
}

void print_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d ",l[i]);
  }
  printf("\n");
}

