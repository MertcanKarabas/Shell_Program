#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[], char** envp) {
    while(1) {
        int i;
        char input[50];
        printf("MyShell >> ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0){
            return 0;
        } else if(strcmp(input, "ls") == 0) {
            system("ls");
            
        } else if(strcmp(input, "bash") == 0) {
            system("bash");
        } else {
            printf("Yanlış argüman girildi\n");
        }
        
    }
    return 0;
}