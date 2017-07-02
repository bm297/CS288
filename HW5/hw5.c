#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 100

struct clip *build_a_lst();
struct clip *append();
//int find_length();
void print_lst();
void split_line();

struct clip {
  int views;
  char *user;
  char *id;
  char *title;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  int n;
  head = build_a_lst(*(argv+1));
//  n = find_length(head);
//  printf("%d clips\n",n);
  print_lst(head);		/* prints the table */
  return 0;
}

struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[4]; //fields is array of 4 pointers
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;

  // open fn
  fp = fopen(fn, "r");
  if(fp == NULL) printf("Cannot open file");

  // while no more lines
  else{
	while(!feof(fp)){

		// read a line
		if((fgets(line, LINE_LENGTH, fp)) != NULL){

			// split the line into four substrings/int and store them in a struct
			split_line(fields, line);
			hp=append(hp,fields);
		}
	}
  }

  // split the line into four substrings/int and store them in a struct
  // append - add the struct at the end of the list
  // return the head pointer holding the list

  return hp;
}

/* fields will have four values stored upon return */
void split_line(char **fields,char *line) {
  int i=0;
  char *token, *delim;
  delim = ",\n";
  token=strtok(line,delim);
  /*
     call strtok(line, delim);
     repeat until strtok returns NULL using strtok(NULL, delim);
 */
 
  while(token!=NULL && i<4)
    {
      fields[i]=token;
      token=strtok(NULL, delim);
      i++;
 
    }
}

/* set four values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp,*tp;

 cp=tp=NULL;
  /*
     malloc tp
     set views using atoi(*five)
     malloc for four strings.
     strcpy four strings to tp
     insert tp at the end of the list pointed by hp
     use cp to traverse the list
 */

  tp=malloc(sizeof(struct clip));
  tp->next= NULL;
  cp=malloc(sizeof(struct clip));
  cp->next= NULL;

  tp->views=atoi(*five);
  tp->user= malloc(strlen(five[1]));
  tp->id=malloc(strlen(five[2]));
  tp->title=malloc(strlen(five[3]));

  strcpy(tp->user, five[1]);
  strcpy(tp->id, five[2]);
  strcpy(tp->title, five[3]);

  if(hp==NULL){
	cp=hp=tp;

  }else{
	cp=hp;
	while(cp!=NULL){
		if(cp->next==NULL){
			cp->next=tp;
			cp=cp->next;
			break;
		}
	cp=cp->next;
	}

  }

  return hp;
}

void print_lst(struct clip *cp) {
  /* 
     use a while loop and the statement below to print the list
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  */

  if(cp==NULL) printf("CP is NULL\n");
  while(cp!=NULL){
	printf("%d,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title);
	cp=cp->next;
  }

}

/* end */
