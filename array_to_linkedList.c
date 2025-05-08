#include <stdio.h>
#define SIZE 5

// Define the structure of a node
struct Node 
{
    int data;
    struct Node *next;
};

// Function to convert array to linked list
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
    return &nodes[0]; // Return the head of the list
}

// Traverse the list
void traverse(struct Node *head) 
{
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() 
{
    struct Node nodes[SIZE];
    int arr[SIZE] = {10, 20, 30, 40, 50};
    struct Node *head = arrayToList(arr, nodes, SIZE);
    traverse(head);
    return 0;
}
