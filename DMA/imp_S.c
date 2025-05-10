#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

// declaration
int *stack = NULL;
int top = -1;
int capacity = INITIAL_SIZE;

// push function to insert element on the stack
void push(int element) {
    if (top == capacity - 1) {
        // resize stack using realloc
        capacity *= 2;
        stack = realloc(stack, capacity * sizeof(int));
        if (stack == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    top++;
    stack[top] = element;
}

// pop function to remove and return top element
int pop() {
    if (top == -1) {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack[top--];
}

// peek function to view top element
int peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

// size function to get the current stack size
int size() {
    return top + 1;
}

// main function
int main() {
    // Allocate initial memory
    stack = malloc(capacity * sizeof(int));
    if (stack == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    push(10);
    push(20);
    push(30);
    push(40);

    printf("\nCurrent stack size : %d", size()); // 4

    pop();
    pop();

    printf("\nCurrent stack size : %d", size()); // 2
    printf("\nTop element : %d\n", peek());      // 20
    printf("Popped element : %d", pop());        // 20
    printf("\nTop element : %d\n", peek());      // 10

    // Free allocated memory
    free(stack);

    return 0;
}
