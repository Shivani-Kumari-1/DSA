#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node
typedef struct N 
{
    int data;
    struct N *next;
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

// Function to count length of list
int getLength(Node *head) 
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find and display middle elements
void DisplayMiddle(Node *head) 
{
    int length = getLength(head);
    int middleIndex = length / 2;

    Node *temp = head;
    for (int i = 0; i < middleIndex - (length % 2 == 0 ? 1 : 0); i++) 
    {
        temp = temp->next;
    }

    if (length % 2 == 0) 
    {
        // Even length: print both m1 and m2
        printf("Middle element m1: %d\n", temp->data);
        printf("Middle element m2: %d\n", temp->next->data);
    } 
    else 
    {
        // Odd length: print single middle
        printf("Middle element: %d\n", temp->data);
    }
}

int main() 
{
    // Create nodes
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);
    Node* fifth = createNode(50);
    Node* sixth = createNode(60);

    // Link the nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    // Display middle elements
    DisplayMiddle(first);

    return 0;
}
