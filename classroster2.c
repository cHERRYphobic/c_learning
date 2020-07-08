#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tstpt(void);
void prgmSt(void);

#define MAX_LENGTH 13

struct student{
	size_t noClass;
	char **classTaken;	
};
struct node{
	struct student* details; 
	struct node *next;
	char *name;
 	
};

struct node **head=NULL; 
char **studentNames;
size_t noOfStudents = 0;

//Takes the input and makes structs by inputing the data
void prgmSt(void){
	struct node **tmp;
	int testVar = 0;
	if(noOfStudents==0){
		fprintf(stdout,"0 is not a valid input");
		exit(EXIT_SUCCESS);
	}
	for(size_t i=0; i<noOfStudents; i++){
		
		struct node * studenti = malloc(sizeof(struct node));
		studenti->details = malloc(sizeof(struct student));
		
	    if((studenti==NULL)|(studenti->details==NULL)){
		perror("E:");
		exit(EXIT_FAILURE);
	    }
		
		printf("\nEnter the name of Student(max 12)(%zu)= ",i+1);
		studenti->name=malloc(MAX_LENGTH);
		if(studenti->name==NULL){
				perror("E:");
				exit(EXIT_FAILURE);
			}
		
		testVar=scanf("%s", studenti->name);
		if(testVar!=1){
			perror("E:");
			exit(EXIT_FAILURE);
		}
		studentNames[i] = studenti->name;
		
		printf("\nEnter the number of Classes he attended= ");
		testVar = scanf("%zu",&(studenti->details->noClass));
		if(testVar!=1){
			perror("E:");
			exit(EXIT_FAILURE);
		}
		
		studenti->details->classTaken = malloc((studenti->details->noClass)*sizeof(char *)); //Assumed MAX_LIMIT of 12+1 characters for sub name
		if(studenti->details->classTaken==NULL){
				exit(EXIT_FAILURE);
			}
		studenti->next = NULL;
		 	
		for(int  j=0; j<(studenti->details->noClass); j++){
            studenti->details->classTaken[j] = malloc(MAX_LENGTH*sizeof(char));
            
		    if(studenti->name==NULL){
				perror("E:");
				exit(EXIT_FAILURE);
			}			
			printf("\nEnter class(%d)(MAX 12 CHARACTERS) = ",j+1);
			testVar=scanf("%s",studenti->details->classTaken[j]);
			if(testVar!=1){
			perror("E:");
			exit(EXIT_FAILURE);
		}
		}
		
		if(i==0){
			printf("%p \n",head);
			head = &studenti;
			printf("%p %p %p\n ",head, *head,studenti);
			
			
			tmp = &studenti;
		} else{
			(*tmp)->next = studenti;
			tmp = &studenti;
			printf("%p %p %p\n ",head, *head,studenti);
		}
		studenti = studenti->next;
		printf("%p %p %p\n ",head, *head,studenti);
		
		
	}	
	printf("%p %p\n ",head, *head);
}
    void tstpt(void){
		printf("studentNames={");
		for(size_t k=0; k<noOfStudents; k++){
		printf("%s ",studentNames[k]);
	}
		printf("}");
	int j=0;
	printf("%p %p \n ",head, *head);
	while((*head)!=NULL){
		printf("\nStudent(%d)",j+1);
		printf("\n|name=%s",(*head)->name);
		printf("\n|Attended=%zu classes", (*head)->details->noClass);
		printf(" |He attendended: " );
		for(int i=0; i<noOfStudents; i++){
		printf(" %s ",(*head)->details->classTaken[i]);
		}
		 
		*head = (*head)->next;
	}
} 
int main(void){
    setbuf(stdout, NULL);
	printf("What is the no of students in class:: ");
	
	scanf("%zu", &noOfStudents);
    studentNames=malloc(noOfStudents*MAX_LENGTH);
	if(studentNames==NULL){
		perror("E:");
		exit(EXIT_FAILURE);
	}
	prgmSt();
	printf("succ");
	tstpt();
	return EXIT_SUCCESS;
}