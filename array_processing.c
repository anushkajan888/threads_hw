#include <pthread.h>
#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6};
int sum1 = 0, sum2 = 0;

void* sumHalf(void* arg) {
    int start = *((int*)arg);
    int end = start + 3;
    int* sum = (start == 0) ? &sum1 : &sum2;
    for (int i = start; i < end; i++) {
        *sum += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int start1 = 0, start2 = 3;
    pthread_create(&t1, NULL, sumHalf, &start1);
    pthread_create(&t2, NULL, sumHalf, &start2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Sum1: %d, Sum2: %d, Total: %d\n", sum1, sum2, sum1 + sum2);
    return 0;
}
