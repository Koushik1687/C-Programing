#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    int *arr;

    arr = (int*) calloc(n, sizeof(int));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    else 
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

    printf("Sum of the elements: %d\n", sum);

    free(arr);
    return 0;
}
