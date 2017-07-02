#include <stdio.h>

void header();
void head();
void bottom();
void footer();

int main(int argc, char* argv[]){

	header();
	//head();
	bottom(argc, argv);
	footer();

	return 0;
}

void header(){
	printf("\n\n\t\t+-----+-----+-----+-----+ FFFFFFFF\n");
	for(int i=0; i<3; i++){
		printf("\t\t+-----+-----+-----+-----+\n");
	}
}

void bottom(int ac, char* av){
	
	printf("\targv\t");

	int a[sizeof(av)];

	for(int i=0, j=0; i<sizeof(a); i++, j++){
		printf("%d\n", av[i][j]);

	}
}

void footer(){
	for(int i=0; i<3; i++){
		printf("\t\t+-----+-----+-----+-----+\n");
	}
	printf("\t\t+-----+-----+-----+-----+ 00000000\n");
}