#include <pthread.h>
#include <stdio.h>

void* printNumbers(void* arg) {
    long id = (long)arg;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %ld: %d\n", id, i);
    }
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printNumbers, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

