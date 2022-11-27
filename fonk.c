#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void fonk(char *param) {
    for (int i = 0; i < 3; i++) {
            printf("%s\n", (param + i));
            while(param != NULL) {
                if (strcmp(param, '\n') == 0 ) {
                    break;
                } else {
                    param++;
                }
            }
    }
}

int main(int argc, char *argv[], char** envp) {
    int i = 0, f;
        char input[50];
        printf("MyShell >> ");
        fgets(input, 50, stdin);
        char *split = strtok(input, " ");
        char inputs[10][10];
        while(split != NULL) {
            if (strcmp(split, "writef") == 0){
            
            }
            strcpy(inputs[i], split);
            split = strtok(NULL, " ");
            i++;
        }
         
        for (int i = 0; i < 3; i++) {
            printf("%s\n", inputs[i]);
        }
       // fonk(&inputs);
    return 0;
}