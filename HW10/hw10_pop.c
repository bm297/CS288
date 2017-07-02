// CS288 HW10
// Point-to-point dot product calculator using scatter/gather. 


#include <stdio.h>
#include <mpi.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define NELMS 1000000
#define MASTER 0
#define MAXPROCS 16

long dot_product();
void init_lst();
void print_lst();

int main(int argc, char **argv) {
  int i,n,portion,vector_x[NELMS],vector_y[NELMS];
  int sidx,eidx,size;
  long prod, tmp_prod;
  int pid,nprocs, rank;
  double stime,etime;
  MPI_Status status;
  MPI_Comm world;

  n = atoi(argv[1]);
  if (n > NELMS) { printf("n=%d > N=%d\n",n,NELMS); exit(1); }

  MPI_Init(&argc, &argv);
  world = MPI_COMM_WORLD;
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
 
	portion = n/nprocs;

	if (pid == MASTER){ 		
		init_lst(vector_x, n);
		init_lst(vector_y, n);
	}

	sidx = (pid * portion);
	eidx = (sidx + portion);

	MPI_Scatter(vector_x, portion, MPI_INT, &vector_x[sidx], portion, MPI_INT, MASTER, MPI_COMM_WORLD);
	MPI_Scatter(vector_y, portion, MPI_INT, &vector_y[sidx], portion, MPI_INT, MASTER, MPI_COMM_WORLD);

  	stime = MPI_Wtime();

	prod = dot_product(sidx,eidx,vector_x, vector_y, n);

	long *prod_lst = NULL;
	if(pid == MASTER)
		prod_lst = malloc(sizeof(long) * nprocs);

	MPI_Gather(&prod, 1, MPI_LONG, prod_lst, 1, MPI_LONG, MASTER, MPI_COMM_WORLD);

	if (pid == MASTER){
		prod = 0;
		for (int i = 0; i < nprocs; i++)
			prod += prod_lst[i];
	}

  etime = MPI_Wtime();

  if (pid == MASTER) {
    printf("pid=%d: final prod=%lu\n",pid,prod);
    printf("pid=%d: elapsed=%f\n",pid,etime-stime);
  }
  MPI_Finalize();
}

long dot_product(int s,int e, int x[], int y[], int n){
	long i,prod=0;

	for (i = s; i < e; i++)
		prod = 	prod + x[i] * y[i];

	return prod;
}

void init_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) 
		*l++ = i;
}
void print_lst(int s,int e, int *l){
  int i;
  for (i=s; i<e; i++) {
    printf("%x ",l[i]);
  }
  printf("\n");
}

// end of file