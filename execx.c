#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, f;
    f = fork(); 

    if(f == 0) { //child
        i = execve(argv[2], argv, NULL); //burada oluşan çocuğu farklı bir programa çeviriyoruz.
        perror("error");
    } else if(f > 0){ //parent
       wait(&i);
    } else { //error
        printf("Fork yapılamadı...");
    }
    return 0;
}