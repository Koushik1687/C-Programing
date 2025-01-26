#include <stdio.h>

int main () {
    int a = 40;
    int *b;
    b = &a;
    printf("A: %d\n", a);
    printf("A: %p\n", &a);
    printf("B: %u\n", b);
    printf("A: %p\n", &b);
    printf("A: %d\n", *b);

    return 0;
}