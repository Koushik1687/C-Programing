#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void *print_prime(void *arg) {
    printf("Prime Numbers: ");
    for (int i = 1; i <= 20; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return NULL;
}

void *print_non_prime(void *arg) {
    printf("Non-Prime Numbers: ");
    for (int i = 1; i <= 20; i++) {
        if (!is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, print_prime, NULL);
    pthread_create(&thread2, NULL, print_non_prime, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
