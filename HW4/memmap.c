/*

 Write C program that prints a memory map.
 1. Memory map filled with hex decimals only.
 2. Memory map filled with command and parameters in ASCII text and others in hex.

*/

void formatPointerMemAddress(char **p);
void stringHexValues(char p[]);

#include <stdio.h>

int main(int argc, char *argv[]){

// int array[10];
// array[0]=10;
// printf("%p\n\n",array);


//  printf("argc value: %d\t argc address: %p\n\n", argc, &argc);
//  printf("argv value: %p\t argv address: %p\n\n", argv, &argv);
//  printf("argv value: %d\n\n", **argv);

  printf("\n\n\n\n\t+----+----+----+----+ FFFFFFFFFFFF\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");

  printf("\t| -- | -- | %.2x | %x | %p\n",  argv[4][3], argv[4][2], argv[5]);
  printf("\t| %x | %x | %.2x | %x | %p\n", argv[4][1], argv[4][0], argv[3][2], argv[3][1], argv[4]);
  printf("\t| %x | %.2x | %x | %.2x | %p\n",  argv[3][0], argv[2][2], argv[2][1], argv[2][0], argv[3]);
  printf("\t| %.2x | %x | %x | %.2x | %p\n",  argv[1][7], argv[1][6], argv[1][5], argv[1][4], argv[2]);
  printf("\t| %x | %x | %.2x | %x | %p\n",  argv[1][3], argv[1][2], argv[1][1], argv[1][0], argv[1]);
  printf("\t| %.2x | %x | %x | %x | %p\n",  argv[0][7], argv[0][6], argv[0][5], argv[0][4], argv[0]);
  printf("\t| %x | %x | %x | %x | %p\n",  argv[0][3], argv[0][2], argv[0][1], argv[0][0], argv[0-1]);

  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");


//  stringHexValues(argv[5]);
//  stringHexValues(argv[4]);
//  stringHexValues(argv[3]);
//  stringHexValues(argv[2]);
//  stringHexValues(argv[1]);
//  stringHexValues(argv[0]);


  if(argc > 1){
    for(int count=argc-1; count <= argc; count--){
      printf(" argv+%d | %p    | %p\n", count, argv[count], &argv[count]);
	if(count == 0){break;} 
    }
  }else{
    printf("The command had no other arguments.\n");
   }



  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf(" argv   | %p    | %p\n", argv, &argv);
  printf(" argc   | %.14x    | %p\n", argc, &argc);
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+\n");
  printf("\t+----+----+----+----+ 00000000000000\n");



formatPointerMemAddress(argv);

  return 0;

}

void stringHexValues(char p[]){

	int cnt;
	for(cnt=0; cnt<p[cnt]; cnt++){};

	int printed=0;
	while(cnt != 0){
		printed++;
		printf("\t| %2x |", *&p[cnt]);
		cnt--;
	}
	printf("%p\n", p);

}


// The function receives an array of 
void formatPointerMemAddress(char *p[]){




//	printf("argv: %p\n\n", p);
//	printf("argv+1: %p\n\n", p+1);
//	printf("*argv:%p\t\n\n", *p);
//      printf("**argv: %d\n\n", **p);
//	printf("**argv+1: %d\n\n", **p+1); 
//	printf("Success\n");

}
