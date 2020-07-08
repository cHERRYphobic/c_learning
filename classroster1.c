#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tstpt(void);
void prgmSt(void);

struct student{
	char *name;
	int noClass;
	//char **classTaken;
    struct student *next;	
};
struct student **head;
char **studentNames;
int noOfStudents = 0;

//Takes the input and makes structs by inputing the data
void prgmSt(void){
	//setbuf(stdout, NULL);
	for(int i=0; i<noOfStudents; i++){
		
		printf("\nhere5\n");
		struct student *new = (struct student*)malloc(sizeof(struct student));
		printf("\nhere6\n");
		printf("new=%p\n",new);
		struct student **tmp;//outside for l
		struct student **tmp1;//outside for l
		//new->classTaken = NULL;
		printf("\nEnter the name of Student(%d)= ",i+1);
		fflush(stdout);
		scanf("%s", new->name);
		studentNames[i] = new->name;
		printf("\n%s, test1 ", studentNames[i]);
		printf("\nEnter the number of Classes he attended= ");
		fflush(stdout);
		scanf("%d",&(new->noClass));
		printf("\nhere4\n");
		printf("%d, test2 \n", new->noClass);
		new->next = NULL;
//writes class taken by students		
/* 		for(int  j=0; j<(new->noClass); j++){			
			printf("\nEnter class(%d) = ",j+1);
			new->classTaken = realloc(new->classTaken,(j+1)*sizeof( *(new->classTaken)));
			if(new->classTaken==NULL){
				exit(EXIT_FAILURE);
			}
			scanf("%s",new->classTaken[i]);
		} */
		
		if(i==0){
			head = &new;
			tmp = &new;
			printf("head=%p tmp=%p new=%p \n",head,tmp,new);
		} else{
			printf("here1\n");
			tmp1 = &new;
			(*tmp)->next = *tmp1;
			printf("here2\n");
			printf("tmp->next=%p new=%p \n",(*tmp)->next,new);
			printf("here3\n");
		}
 
		new = new->next;
		
		printf("new=%p\n",new);
		
		
	}	
}
void tstpt(void){
	for(int k=0; k<noOfStudents; k++){
		printf("%s ",studentNames[k]);
	}
	
	while((*head)->next!=NULL){
		printf("\n%s , %d = ",(*head)->name, (*head)->noClass );
		/* for(int i=0; i<noOfStudents; i++){
		printf("%s ",*(head->classTaken));
		head->classTaken += i;
		}
		 */
		*head = (*head)->next;
	}
}
int main(void){

	printf("What is the no of students in class:: ");
	fflush(stdout);
	scanf("%d", &noOfStudents);
    studentNames=(char**)malloc(noOfStudents*sizeof(char *));
	prgmSt();
	printf("succ");
	//tstpt();
	return EXIT_SUCCESS;
}