#include <stdio.h>

int main(void) {
    int i, j, k;
    i = 7; j = 8; k = 9;
    printf("%d", (i + 10) % k / j);
}