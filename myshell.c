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
        i = execve(string, input1, input2); //burada oluşan çocuğu farklı bir programa çeviriyoruz.
        perror("error");
    } else if(f > 0){ //parent
       wait(&i);
    } else { //error
        printf("Fork yapılamadı...");
    }
}
void cat(char *input1[]) {
    int i = 1;
    printf("cat: ");
    while(input1[i+1] != NULL) {
        printf("%s ", input1[i]); //girilen inputu ekrana basıyoruz.
        i++;
    }
    printf("%s\n", input1[i]);
}

int main(int argc, char *argv[], char** envp) {

    while(1)  {
    
       
        char input[50];
        printf("MyShell >> ");
        fgets(input, 50, stdin);
        char *split = NULL;
        split = strtok(input, " ");
        char *inputs[100];
        int counter = 0;
        while(split != NULL) {
            inputs[counter] = split;
            split = strtok(NULL, " ");
            counter++;
        }
        int i = 0;
        
        if ((strcmp(inputs[0], "exit\n") == 0) ){
            return 0;

        } else if((strcmp(inputs[0], "ls\n") == 0)) {

            inputaGoreFonk("/bin/ls", inputs, envp);

        } else if((strcmp(inputs[0], "bash\n") == 0)) {

            inputaGoreFonk("/bin/bash", inputs, envp);

        } else if(strcmp(inputs[0], "cat") == 0) {
            cat(inputs);

        } else if(strcmp(inputs[0], "writef") == 0 && (strcmp(inputs[1], "-f") == 0)){
            inputaGoreFonk("writef", inputs, envp);

        } else if(strcmp(inputs[0], "execx") == 0 && (strcmp(inputs[1], "-t") == 0)){
            inputaGoreFonk("writef", inputs, envp);

        } else if((strcmp(inputs[0], "clear\n") == 0)) {
            printf("\e[1;1H\e[2J");

        } else if((strcmp(inputs[0], "help\n") == 0)) {

            printf("You can write 7 thing.\n");
            printf("1- If you want to exit -> exit\n");
            printf("2- If you want to list of docs -> ls\n");
            printf("3- If you want to bash -> bash\n");
            printf("4- If you want to rewrite your input -> cat -input-\n");
            printf("5- If you want to create new file and saw time and pid-> writef -f -filename-\n");
            printf("6- If you want to exec -t times -> execx -t -times- -command-\n");
            printf("7- If you want to clear page -> clear-\n");

        } else {
            printf("Yanlış argüman girildi\n");
        }
        
        
    }
    return 0;
}