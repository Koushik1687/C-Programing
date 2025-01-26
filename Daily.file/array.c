#include <stdio.h>
void arr();
void arrdisplay();
int main()
{
    arr();
    return 0;
}

void arr()
{

    int arr[10];
    for (int i = 1; i <= 10; i++)
    {
        printf("Please enter element %d : ", i);
        scanf("%d", &arr[i]);
    }
    arrdisplay(arr);
}

void arrdisplay(int arr[])
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Element %d : %d\n", i, arr[i]);
    }
    printf("[ ");
    for (int i = 1; i <= 10; i++)
    {
        printf("%d", arr[i]);
        if (i < 10)
        {
            printf(", ");
        }
    }
    printf(" ]");
}
