#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("The largest number is: %d\n", largest);

    free(arr);

    return 0;
}
