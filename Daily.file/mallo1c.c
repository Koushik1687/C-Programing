#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr, sum = 0;
    ptr = (int *)malloc(3 * sizeof(ptr));
    for (int i = 0; i < 3; i++)
    {
        printf("Number : ");
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Number print : %d\n", ptr[i]);
        sum += ptr[i];
    }
    printf("%d\n", sum);

    ptr = (int *)calloc(3, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Number : ");
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Number print : %d\n", ptr[i]);
    }

    ptr = (int *)realloc(ptr, 4 * sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        printf("Number : ");
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Number print: %d\n", ptr[i]);
    }
    free(ptr);
    return 0;
}