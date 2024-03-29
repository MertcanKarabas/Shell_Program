#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {

    char file_name[20];

    //Getting system time
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    //File operations
    FILE *fp = fopen(argv[2], "a+");
    fprintf(fp, "pid: %d, ppid: %d, Local time and date: %s", getpid(), getppid(), asctime(timeinfo));
    fclose(fp);

    return 0;
}