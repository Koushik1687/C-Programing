#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, num, *ptr, *ptr1, sum = 0;
    printf("Please Enter the number of element : ");
    scanf("%d", &num);
    ptr = (int *)malloc(num * sizeof(int));
    if (ptr == NULL)
    {
        printf("Unable to allocate memory !!");
        exit(0);
    }
    printf("Please Enter %d Elements: \n", num);
    for (i = 0; i < num; i++)
    {
        printf("Enter Element no. %d : ", i);
        scanf("%d", ptr + i);
    }
    printf("You have entered: \n");
    for (i = 0; i < num; i++)
    {
        printf("Element No. %d :%d\n", i, *(ptr + i));
    }
    for (i = 0; i < num; i++)
    {
        sum += *(ptr + i);
    }
    printf("Sum of all elements are:\n");
    printf("Sum = %d\n", sum);

    free(ptr);
    num = 0;
    sum = 0;

    printf("Please Enter the number of element : ");
    scanf("%d", &num);
    ptr1 = (int *)calloc(num, sizeof(int));
    if (ptr1 == NULL)
    {
        printf("Unable to allocate memory !!");
        exit(0);
    }
    printf("Please Enter %d Elements: \n", num);
    for (i = 0; i < num; i++)
    {
        printf("Enter Element no. %d : ", i);
        scanf("%d", ptr1 + i);
    }
    printf("You have entered: \n");
    for (i = 0; i < num; i++)
    {
        printf("Element No. %d :%d\n", i, *(ptr + i));
    }
    for (i = 0; i < num; i++)
    {
        sum += *(ptr1 + i);
    }
    printf("Sum of all elements are:\n");
    printf("Sum = %d\n", sum);

    free(ptr1);
    return 0;
}