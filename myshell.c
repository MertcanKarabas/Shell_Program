#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    while(1) {
        char input[50];
        printf("MyShell >> ");
        scanf("%s", input);

        if (input == "exit"){
            exit(1);
        } else if(input == "ls") {
            execv("/bin/ls");
        }

        break;
    }
    return 0;
}