#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void fonk(char *ptr[]) {
    if(strcmp(ptr[0], "abc") == 0) {
        printf("OLDU");
    } 
    if(strcmp(ptr[1], "def") == 0) {
        printf("Sen bu işi biliyorsun");
    }
}
int main(int argc, char *argv[], char** envp) {
    
    char input[50];
    printf("MyShell >> ");
    fgets(input, 50, stdin);

    char *split = strtok(input, " ");
    char *ptr[10];

    int i = 0;
    while(split != NULL) {
        strcpy(ptr[i], split);
        split = strtok(NULL, " ");
        i++;
    }
         
    for (int i = 0; i < 3; i++) {
        printf("%s\n", ptr[i]);
    }

    fonk(ptr);
    return 0;
}