#include <pthread.h>
#include <stdio.h>

void* threadFunction(void* arg) {
    printf("Thread %ld is running\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    return 0;
}
