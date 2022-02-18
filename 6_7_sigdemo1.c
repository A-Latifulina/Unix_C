#include    <stdio.h>
#include    <signal.h>
#include    <unistd.h>
#include    <string.h>

int     counter;

int main()
{
    void    f(int);         /* declare the handler */
    int     * i; 
    signal( SIGINT, f );    /* install the handler */
    
    printf("Enter the command line arguement ");
    scanf("%d", i);
    
    counter = 0;
    while(counter<*i){    /* do something else */
        printf("hello\n");
        sleep(1);
    }
}

void f(int signum)
{
    int     j;
    char    exclam[100];
    for( j = 1; j <= counter; j++) {
        strcat(exclam, "!");
    };
    printf("OUCH%s\n", exclam);
    counter++;
}

