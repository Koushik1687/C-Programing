#include <stdio.h>
#include <stdlib.h>
#define MAX 5
//insert data in a sorted array.
int arr[MAX];

void display(int ar[])
{
    printf("Array in Desending Order:\n");
    for (int i = MAX - 1; i >= 0; i--)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void sort(int ar[])
{
    int temp;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (ar[i] > ar[j])
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    display(ar);
}

int main()
{
    int ar[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("Please enter element %d: ", i + 1);
        scanf("%d", &ar[i]);
    }

    sort(ar);

    return 0;
}
