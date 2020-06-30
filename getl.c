#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
  size_t sz=0;
  ssize_t len=0; 
  char * line=NULL;
  char ** storga=NULL;
  size_t i=0;
  size_t k=0;
  FILE *f=fopen("log","w+");
  if(f==NULL){
    perror("ERROR");
    return EXIT_FAILURE;
  } 
  while((len=getline( &line, &sz, stdin))>=0){
    storga=realloc( storga, (i+1)*sizeof(* storga));
    storga[i]=line;
    line=NULL;
    i++;
  }

  /*
  k=fwrite( storga, sizeof(* storga),sizeof(storga), f);
  perror("HERE");
  printf("EXIT CODE :%ld", k);
  */
  free(line);

  for(size_t j=0;j<i;j++){
    printf("%s ",storga[j]);
    free(storga[j]);
  }
  free(storga);
  
  
  fclose(f);
  return EXIT_SUCCESS;
}
