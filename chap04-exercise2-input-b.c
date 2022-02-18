#include <stdio.h>

int main(void) {
    int i, j;
    i = 2; j = 3;
    printf("%d", (i + 10) % j);
}