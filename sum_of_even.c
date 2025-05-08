#include <stdio.h>
#define SIZE 5

// Define the structure of a node
struct Node 
{
    int data;
    struct Node *next;
};

// Convert array to linked list
struct Node* arrayToList(int arr[], struct Node nodes[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        nodes[i].data = arr[i];
        if (i < size - 1)
        {  nodes[i].next = &nodes[i + 1];  }
        else
        {  nodes[i].next = NULL;  }
    }
    return &nodes[0]; // Return head
}

// Traverse and compute count + even sum
void traverse(struct Node *head) 
{
    struct Node *current = head;
    int evenSum = 0;

    printf("Linked List: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        if (current->data % 2 == 0) 
        {
            evenSum += current->data;
        }
        current = current->next;
    }
    printf("NULL\n");
    printf("Sum of even numbers: %d\n", evenSum);
}

// Main function
int main() 
{
    struct Node nodes[SIZE];
    int arr[SIZE] = {10, 5, 6, 1, 50};
    struct Node *head = arrayToList(arr, nodes, SIZE);
    traverse(head);
    return 0;
}
