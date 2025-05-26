#include <stdio.h>

#define MAX 100

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages[MAX], temp[MAX], time[MAX];
    int i, j, k, pos, faults = 0, counter = 0, n;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page numbers: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; ++i) {
        temp[i] = -1;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; ++i) {
        int found = 0;

        for (j = 0; j < frames; ++j) {
            if (temp[j] == pages[i]) {
                found = 1;
                time[j] = counter++;
                break;
            }
        }

        if (!found) {
            int empty = -1;
            for (j = 0; j < frames; ++j) {
                if (temp[j] == -1) {
                    empty = j;
                    break;
                }
            }
            if (empty != -1) {
                temp[empty] = pages[i];
                time[empty] = counter++;
            } else {
                pos = findLRU(time, frames);
                temp[pos] = pages[i];
                time[pos] = counter++;
            }
            faults++;
        }

        printf("\n");
        for (j = 0; j < frames; ++j) {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
