#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

void tstpt(void);
void prgmSt(void);
void initHead(void);

void scanCheck(int tst);
void alloCheck(void* ptr);
void inputCheck(int x);

void init(struct node** wptr);
void enterClassNo(struct node** yptr);
void enterName(struct node** xptr);
void enterClassTaken(struct node** zptr);



struct node *head=NULL;
 
char **studentNames;
size_t noOfStudents = 0;
int studentNo = 0;

void alloCheck(void* ptr){
	if(ptr==NULL){
				perror("Error Allocating Memory:");
				exit(EXIT_FAILURE);
			}
}
void scanCheck(int tst){
	if(tst!=1){
		perror("scanf Error:");
		exit(EXIT_FAILURE);
	}
}
void inputCheck(int x){
	if(x){
		fprintf(stdout,"Invalid input");
		exit(EXIT_FAILURE);
	}
	
}

//i from 1....n  struct node*
void enterName(struct node** xptr){
	printf("\nEnter the name of Student(%d)(max 12)= ",studentNo+1);
		(*xptr)->name=malloc(MAX_LENGTH);
		    alloCheck((*xptr)->name);
		    scanCheck(scanf("%s", (*xptr)->name));
		studentNames[studentNo] = (*xptr)->name;
		studentNo++;
}
void enterClassNo(struct node** yptr){
	printf("\nEnter the number of Classes he attended= ");	
			scanCheck(scanf("%zu",&((*yptr)->details->noClass)));
		
}
void enterClassTaken(struct node** zptr){
	(*zptr)->details->classTaken = malloc(((*zptr)->details->noClass)*sizeof(char *)); //Assumed MAX_LIMIT of 12+1 characters for sub name
        alloCheck((*zptr)->details->classTaken);	
		for(int  j=0; j<((*zptr)->details->noClass); j++){
            (*zptr)->details->classTaken[j] = malloc(MAX_LENGTH*sizeof(char));
                alloCheck((*zptr)->details->classTaken[j]);
			printf("\nEnter class(%d)(MAX 12 CHARACTERS) = ",j+1);
			scanCheck(scanf("%s",(*zptr)->details->classTaken[j]));
		}
}
void init(struct node** wptr){
	*wptr=malloc(sizeof(struct node));
	    alloCheck(wptr);
    (*wptr)->details = malloc(sizeof(struct student));
	    alloCheck((*wptr)->details);
	(*wptr)->next = NULL;
}


//Takes the input and makes structs by inputing the data
void initHead(void){	
    init(&head);
	enterName(&head);
	enterClassNo(&head);
    enterClassTaken(&head);		    
}

void prgmSt(void){
	struct node *tmp=NULL;
	    inputCheck((noOfStudents<=0)|(isdigit(noOfStudents)!=0));
	initHead();
    for(size_t i=0; i<noOfStudents-1; i++){//
		//init struct
		struct node * studenti =NULL;
		init(&studenti);    
		//studentname
        enterName(&studenti);
		
		//no of classes
		enterClassNo(&studenti);
		//classesTaken
		
		enterClassTaken(&studenti);
		//assignment
		
		if(i==0){
			printf("%p \n",head);
			head->next = studenti;
			printf("%p %p\n ",head,studenti);
			tmp = studenti;
		} else{
			
			printf("this %p %p \n ",tmp->next, studenti);
			tmp->next = studenti;
			tmp = studenti;
			printf("%p %p\n ",head,studenti);
		}
		studenti = studenti->next;
		printf("%p %p\n ",head,studenti);
		
		
	}	
	printf("%p \n ",head);
}
void tstpt(void){
		printf("studentNames={");
		for(size_t k=0; k<noOfStudents; k++){
		printf("%s ",studentNames[k]);
	}
		printf("}");
	int j=0;
	printf("%p \n ",head);
	while(head!=NULL){
		printf("\n------------------");
		printf("\nStudent(%d)",j+1);
		j++;
		printf("\n|||name=%s|||",head->name);
		printf("\n|||Attended=%zu classes|||", head->details->noClass);
		printf(" \n|||He attendended: " );
		for(int i=0; i<head->details->noClass; i++){
		printf(" %s ",head->details->classTaken[i]);
		}
		printf("|||" );
		printf("\n------------------");
		 
		head = head->next;
	}
} 
int main(void){
    setbuf(stdout, NULL);
	printf("What is the no of students in class:: ");
	    scanCheck(scanf("%zu", &noOfStudents));
    studentNames=malloc(noOfStudents*MAX_LENGTH);
	    alloCheck(studentNames);
	prgmSt();
	printf("succ");
	tstpt();
	return EXIT_SUCCESS;
}