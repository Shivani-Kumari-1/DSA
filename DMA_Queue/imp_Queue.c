//Queue code here by using DMA
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5

// Declarations
int *queue = NULL;
int start = 0;
int end = -1;
int capacity = INITIAL_SIZE;
int noe = 0;

// Push function (Enqueue)
void push(int data) {
    if (noe == capacity) {
        // Resize queue
        int new_capacity = capacity * 2;
        int *new_queue = malloc(new_capacity * sizeof(int));
        if (new_queue == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        // Copy elements to new queue
        for (int i = 0; i < noe; i++) {
            new_queue[i] = queue[(start + i) % capacity];
        }

        free(queue);
        queue = new_queue;
        capacity = new_capacity;
        start = 0;
        end = noe - 1;
    }

    end = (end + 1) % capacity;
    queue[end] = data;
    noe++;
}

// Pop function (Dequeue)
int pop() {
    if (noe == 0) {
        printf("Queue is empty.\n");
        return -1;
    }

    int poppedElement = queue[start];
    start = (start + 1) % capacity;
    noe--;

    return poppedElement;
}

// Peek function
int peek() {
    if (noe == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[start];
}

// Size function
int size() {
    return noe;
}

// Main function
int main() {
    queue = malloc(capacity * sizeof(int));
    if (queue == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    push(50);
    pop();
    pop();

    printf("Peeked value: %d\n", peek());    // 40
    printf("Current size: %d\n", size());    // 2

    push(60);
    pop();
    push(70);

    printf("Peeked value: %d\n", peek());    // 50
    printf("Final size: %d\n", size());   //3

    // Free dynamically allocated memory
    free(queue);

    return 0;
}
