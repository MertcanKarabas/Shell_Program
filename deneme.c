#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[], char** envp) {

    while(1)  {
    
        char input[50];
        printf("MyShell >> ");
        fgets(input, 50, stdin);

        if (strcmp(input, "exit\n") == 0){
            return 0;

        } else if(strcmp(input, "ls\n") == 0) {
            int i, f;
            f = fork();

            if(f == 0) { //child
                 i = execvp("/bin/ls", argv);
            } else if(f > 0){ //parent
                wait(&i);
            } else { //error
                printf("Fork yapılamadı...");
            }
             
        } else if(strcmp(input, "bash\n") == 0) {
            int i, f;
            f = fork();

            if(f == 0) { //child
                 i = execvp("/bin/bash", argv);
            } else if(f > 0){ //parent
                wait(&i);
            } else { //error
                printf("Fork yapılamadı...");
            }

        } else if(strcmp(input, "cat") == 0) {

        } else if(strcmp(input, "clear\n") == 0) {
            printf("\e[1;1H\e[2J");

        } else {
            printf("Yanlış argüman girildi\n");
        }
        
    }
    return 0;
}