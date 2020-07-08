//SINGLE LINKED LIST IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};
void printLL();
void resolveAdr(struct node** x, struct node*** y);
void insertST(int c, struct node** head);
void insertED(int f, struct node** head);
int insertPOS(int p, int q, struct node** head);
void clearED(struct node** head);
void clearST(struct node** head);
int clearPOS(int t, struct node** head);
struct node* llinit(int a);
//To print the contents of the linked list
void printLL(struct node* head) {
  struct node* b=head;
  while (b!=NULL) {
    printf(" %d ",b->data);
    b=b->next;
  }
}
//This fn changes the head
void resolveAdr(struct node** x, struct node*** y){
  struct node* tmp=*x;
  *x=**y;
  **y=tmp;
}
//to insert a node at start
void insertST(int c, struct node** head){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=c;
  if((*head)==NULL){
    (*head)=newnode;
    (*head)->next=NULL;

  }else{

    newnode->next=(*head);
    resolveAdr(&newnode,&head);

  }
}

// insert node at the end
void insertED(int f, struct node** head){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  struct node* tmpnode=*head;
  newnode->data=f;
  newnode->next=NULL;
  if((*head)==NULL){
    *head=newnode;

  }else{
    while (tmpnode->next!=NULL) {
      tmpnode=tmpnode->next;
    }
    tmpnode->next=newnode;
  }

}
// // insert node at ,middle and in empty list throws error if out of bound, start and end
// // or negative  position
int insertPOS(int p, int q, struct node** head){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  struct node* tmpnode = *head;
  newnode->data=p;
  if((*head)==NULL){
    *head=newnode;
    (*head)->next=NULL;
  }else if(q>0){
    for(int i=0;i<q-1;i++){
      if(tmpnode!=NULL){
        tmpnode=tmpnode->next;
      }
      else{
        printf("insertPOS:OUT OF BOUND\n");
        return EXIT_FAILURE;
      }
    }
    if(tmpnode->next!=NULL){
      newnode->next=tmpnode->next;
      tmpnode->next=newnode;
    }else {
      printf("insertPOS:LOCATION INVALID 1");
      return EXIT_FAILURE;
    }
  }
  else{
    printf("insertPOS:LOCATION INVALID 2\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// clear the 1st element of ll
void clearST(struct node** head){
  struct node* tmp=*head;
  if(tmp!=NULL){
    *head=(*head)->next;

    free(tmp);

  }
}
// clears the last elememt of ll
void clearED(struct node** head){
  struct node* tmp=*head;
  struct node* tmp1=*head;
  if(tmp!=NULL){
    while (tmp->next!=NULL) {
      tmp1=tmp;
      tmp=tmp->next;
    }
    free(tmp);
    tmp1->next=NULL;
  }
}
// clear intermediate position in ll
int clearPOS(int t, struct node** head) {
  struct node* h1 = *head;
  struct node* h2 = *head;
  if(*head==NULL){
    printf("EMPTY LIST\n");
  } else if(t>0){
    for(int i=0;i<(t-1);i++){
      if (h2->next!=NULL){
        h1=h2;
        h2=h2->next;
      }else{
        printf("clearPOS:LOCATION INVALID 1\n" );
        return EXIT_FAILURE;
      }
    }
    if (t==1){
      h2=h2->next;

    }
    if(h2->next==NULL){
      printf("clearPOS: LOCATION INVALID 2\n");
      return EXIT_FAILURE;
    }
    h1->next=h2->next;
    free(h2);

  }
  else {
    printf("clearPOS: LOCATION INVALID 3\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

struct node* llinit(int a) {
  struct node* head=NULL;
  head = (struct node*)malloc(sizeof(struct node));
  head->data=a;
  head->next=NULL;
  return head;
}

int main(int argc, char const *argv[]) {
  struct node* head=llinit(21);

  insertST(12, &head);
  insertED(15,&head);
  insertPOS(22,2,&head);
  clearST(&head);
  clearED(&head);


  clearPOS(1, &head);
  printLL(head);


  return EXIT_SUCCESS;
}
