#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void fonk(char *ptr[]) {
    if(strcmp(ptr[0], "abc") == 0) {
        printf("OLDU");
    } 
    if(strcmp(ptr[1], "def") == 0) {
        printf("Sen bi harkiasın");
    }
}
int main(int argc, char *argv[], char** envp) {
    
    char input[50];
    printf("MyShell >> ");
    fgets(input, 50, stdin);

    
    char *ptr[10];
    int i = 0;
    char * token = strtok(input, " ");
    
    // loop through the string to extract all other tokens
    while( token != NULL ) {
      ptr[i] = token; //printing each token
      token = strtok(NULL, " ");
      i++;
    }
         
    for (int i = 0; i < 3; i++) {
        printf("%s\n", ptr[i]);
    }

    fonk(ptr);
    return 0;
}