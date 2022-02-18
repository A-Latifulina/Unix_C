#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int pid;
    int fd;
    printf("About to run who into a file\n");

    //create a new process or quit
    if((pid = fork()) == -1) {
        perror("fork"); exit(1);
    }

    //child does the work 
    if (pid == 0) {
        close(1);
        fd = open("userlist", O_WRONLY|O_APPEND|O_CREAT, 0644);
        execlp("who", "who", NULL);
        perror("execlp");
        exit(1);
    }

    if (pid != 0) {
        wait(NULL);
        printf("Done running who. results in userlist\n");
    }
}