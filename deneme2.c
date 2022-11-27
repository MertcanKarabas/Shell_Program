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
    input1[0] = "/bin/ls";
    input1[1] = NULL;
    input1[2] = NULL;
    input1[3] = NULL;
    input1[4] = NULL;
    input1[5] = NULL;
    inputaGoreFonk("/bin/ls", input1, input2);
}

void bashCalling(char *input1[], char **input2) {
    input1[0] = "/bin/ls";
    input1[1] = NULL;
    input1[2] = NULL;
    input1[3] = NULL;
    input1[4] = NULL;
    input1[5] = NULL;
    inputaGoreFonk("/bin/bash", input1, input2);
}

int main(int argc, char *argv[], char** envp) {
    
    while(1)  {
    
        int counter = 0;
        char input[50];
        printf("MyShell >> ");
        fgets(input, 50, stdin);
        char *split = strtok(input, " ");
        char inputs[10][10];
        while(split != NULL) {
            strcpy(inputs[i], split);
            split = strtok(NULL, " ");
            i++;
        }
        char *newargv[6];

        if (strcmp(input, "exit") == 0){
            return 0;

        } else if(strcmp(input, "ls") == 0) {
            lsCalling(newargv, envp);

        } else if(strcmp(input, "bash") == 0) {
            bashCalling(newargv, envp);

        } else if(strcmp(input, "cat") == 0) {
            bashCalling(newargv, envp);

        } else {
            printf("Yanlış argüman girildi\n");
        }
        
    }
    return 0;
}