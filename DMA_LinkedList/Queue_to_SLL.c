/*
PUSHED: 10
PUSHED: 20
PUSHED: 30
Queue: 10 20 30 
SIZE of queue: 3
Peeked Front element: 10
POPPED: 10
POPPED: 20
Queue: 30 
SIZE of queue: 1
Peeked Front element: 30
POPPED: 30
Queue is empty!

*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node
{
    int data;             // Value to store (Data field)
    struct Node* next;    // Pointer to next node(Pointer field)
} Node;// 'Node' is a typedef alias for 'struct Node'

// Queue structure using front and end pointers
typedef struct Q
{
    Node* front;          // Points to the front node (for removal)
    Node* end;           // Points to the end node (for insertion)
    int size;             // Tracks Number of elements in the queue
} Queue;// 'Queue' is a typedef alias for 'struct Q'

// Function to create a new node
Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// PUSH: Insert at end of the queue
void PUSH(Queue* q, int value) 
{
    Node* newNode = createNode(value);
    if (newNode == NULL) 
    {
        return;
    }
    if (q->end == NULL) 
    {
        // Queue is empty
        q->front = q->end = newNode;
    } 
    else 
    {
        q->end->next = newNode;
        q->end = newNode;
    }
    q->size++;
    printf("PUSHED: %d\n", value);
}

// POP: Remove from front of the queue
int POP(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) 
    {
        q->end = NULL;
    }

    free(temp);
    q->size--;
    printf("POPPED: %d\n", value);
    return value;
}

// Peek the front element
int peek(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Display the queue
void display(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// SIZE Show total number of elements in the queue
void SIZE(Queue* q)
{
    printf("SIZE of queue: %d\n", q->size);
}
// Main function
int main() 
{
    Queue q;
    q.front = NULL;
    q.end = NULL;
    q.size = 0;
    PUSH(&q, 10);
    PUSH(&q, 20);
    PUSH(&q, 30);
    display(&q);
    SIZE(&q);
    printf("Peeked Front element: %d\n", peek(&q));
    POP(&q);
    POP(&q);
    display(&q);
    SIZE(&q);
    printf("Peeked Front element: %d\n", peek(&q));
    POP(&q);
    POP(&q);  // Trying to pop from empty queue
    return 0;
}
