#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tstpt(void);
void prgmSt(void);

struct student{
	char *name;
	int noClass;
	char **classTaken;
    struct student *next;	
};
struct student *head = NULL;
char **studentNames;
int noOfStudents = 0;

//Takes the input and makes structs by inputing the data
void prgmSt(void){
	for(int i=0; i<noOfStudents; i++){
		struct student *new = malloc(sizeof(struct student));
		struct student *tmp = NULL;
		new->classTaken = NULL;
		setbuf(stdout, NULL);
		printf("\nEnter the name of Student(%d)= ",i+1);
		scanf("%s", new->name);
		studentNames[i] = new->name;
		printf("\n%s, test1 ", studentNames[i]);
		printf("\nEnter the number of Classes he attended= ");
		scanf("%d",&(new->noClass));
		printf("%d, test2 ", new->noClass);
		
		for(int  j=0; j<new->noClass; j++){
			printf("\nEnter class(%d) = ",j+1);
			new->classTaken = realloc(new->classTaken,(i+1)*sizeof(char*));
			new->classTaken+=i;
			scanf("%s",*(new->classTaken));
		}
		new->next = NULL;
		if(i==0){
			head = new;
			tmp = new;
		} else{
			tmp->next = new;
		}
		new = new->next;
		
		
	}
}
void tstpt(void){
	while(head->next!=NULL){
		printf("\n%s , %d = ",head->name, head->noClass );
		for(int i=0; i<noOfStudents; i++){
		printf("%s ",head->classTaken[i]);
		}
		head = head->next;
	}
}
int main(void){
	setbuf(stdout, NULL);
	printf("What is the no of students in class:: ");
	scanf("%d", &noOfStudents);
    studentNames=malloc(noOfStudents*sizeof(char *));
	prgmSt();
	//tstpt();
	return EXIT_SUCCESS;
}