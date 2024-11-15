#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, new_size;

    n = 5;
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the new size of the array: ");
    scanf("%d", &new_size);

    arr = (int *)realloc(arr, new_size * sizeof(int));

    if (arr == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }

    for (int i = n; i < new_size; i++) {
        printf("Enter new element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nElements in the resized array:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}