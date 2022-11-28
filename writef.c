#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    char file_name[20];
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    FILE *fp = fopen("file_name.txt", "a+");
    fprintf(fp, "pid: %d, ppid: %d, Local time and date: %s", getpid(), getppid(), asctime(timeinfo));
    fclose(fp);
    return 0;
}