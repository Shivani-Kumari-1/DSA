#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Create node in heap memory
Node *createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* getNthFromEnd(Node* head, int n) 
{
    int length = 0;
    Node* temp = head;

    // Calculate length
    while (temp != NULL) 
    {
        length++;
        temp = temp->next;
    }

    // Validate n
    if (n > length || n <= 0) 
    {
        return NULL;
    }

    // Go to (length - n)th node
    temp = head;
    for (int i = 0; i < length - n; i++) 
    {
        temp = temp->next;
    }

    return temp;
}
// Function to print linked list
void printList(Node* head) 
{
    while (head != NULL) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() 
{
    // Create linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Linked List: ");
    printList(head);

    int n = 2;

    Node* found = getNthFromEnd(head, n);  
    if (found)
    {
        printf("%dth node from end is %d\n", n, found->data);
    }
    else
    {
        printf("Invalid position (n is too large)\n");
    }   
    return 0;
}
