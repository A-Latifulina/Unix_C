#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 2

int main() {
    int newpid;
    int newpid1;
    void child_code(), parent_code();
    printf("Before: my pid is %d\n", getpid());
    newpid = fork();
    if(newpid == 0)
        child_code(DELAY);
    else
        parent_code(newpid);

    newpid1 = fork();
    if(newpid1 == 0)
        child_code(DELAY);
    else
        parent_code(newpid1);
}

void child_code(int delay){
    printf("Child %d here. Will sleep for %d seconds.\n", getpid(), delay);
    sleep(delay);
    printf("Child done. About to exit.\n");
    exit(17);
}

void parent_code(int childpid) {
    int wait_rv;
    wait_rv = wait(NULL);
    printf("Done wainting for %d. Wait returned: %d.\n", childpid, wait_rv);
}