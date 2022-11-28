#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void inputaGoreFonk(char *string, char *input1[], char **input2) {
    int i, f;
    f = fork();

    if(f == 0) { //child
        i = execve(string, input1, input2);
    } else if(f > 0){ //parent
       wait(&i);
    } else { //error
        printf("Fork yapılamadı...");
    }
}

void execxCalling() {

}

void writefCalling() {

}

void clearCalling() {

}

void catCalling() {

}

void lsCalling(char *input1[], char **input2) {
    
}

void bashCalling(char *input1[], char **input2) {
    if(strcmp(input1[0], "bash") == 0 ) {
        inputaGoreFonk("/bin/bash", input1, input2);
    }
}

int main(int argc, char *argv[], char** envp) {

    while(1)  {
    
        int counter = 0;
        char input[50];
        printf("MyShell >> ");
        fgets(input, 50, stdin);

        char *split = strtok(input, " ");
        char *inputs[10];
        while(split != NULL) {
            strcpy(inputs[counter], split);
            split = strtok(NULL, " ");
            counter++;
        }

        if (strcmp(input, "exit\n") == 0){
            return 0;

        } else if(strcmp(input, "ls\n") == 0) {

            int i, f;
            f = fork();

            if(f == 0) { //child
                 i = execve("/bin/ls", argv, envp);
            } else if(f > 0){ //parent
                wait(&i);
            } else { //error
                printf("Fork yapılamadı...");
            }

        } else if(strcmp(input, "bash\n") == 0) {

            bashCalling(inputs, envp);

        } else if(strcmp(input, "cat\n") == 0) {
            

        } else if(strcmp(input, "clear\n") == 0) {
            printf("\e[1;1H\e[2J");

        } else {
            printf("Yanlış argüman girildi\n");
        }
        
    }
    return 0;
}