#include <pthread.h>
#include <stdio.h>

void* calculateSquare(void* arg) {
    int num = *((int*)arg);
    printf("Square of %d is %d\n", num, num * num);
    return NULL;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, calculateSquare, &numbers[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
