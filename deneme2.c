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
        perror("error");
    } else if(f > 0){ //parent
       wait(&i);
    } else { //error
        printf("Fork yapılamadı...");
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
            inputs[counter] = split;
            split = strtok(NULL, " ");
            counter++;
        }
        
        if ((strcmp(inputs[0], "exit\n") == 0)){
            return 0;

        } else if((strcmp(inputs[0], "ls\n") == 0)) {

            inputaGoreFonk("/bin/ls", inputs, envp);

        } else if((strcmp(inputs[0], "bash\n") == 0)) {

            inputaGoreFonk("/bin/bash", inputs, envp);

        } else if(strcmp(input, "cat\n") == 0) {
            

        } else if((strcmp(inputs[0], "clear\n") == 0)) {
            printf("\e[1;1H\e[2J");

        } else {
            printf("Yanlış argüman girildi\n");
        }
        
    }
    return 0;
}