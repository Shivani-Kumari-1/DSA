/*
           ......OUTPUT.........
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

Enter index to retrieve: 2
Data at index 2: 30

Enter index to delete (except index 0): 3
Node at index 3 deleted.
Linked List: 10 -> 20 -> 30 -> 50 -> NULL

*/

#include <stdio.h>
#define SIZE 5 // Only 5 nodes, no extra node

// Define the structure of a node
struct Node 
{
    int data;            // Stores the data
    struct Node *next;   // Pointer to the next node
};

// Function to create the list using static array
struct Node* createList(struct Node nodes[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodes[i].data);
        if (i < size - 1) 
        {
            nodes[i].next = &nodes[i + 1];
        } 
        else 
        {
            nodes[i].next = NULL;
        }
    }
    return &nodes[0]; // Return head pointer
}

// Function to traverse the list
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

// Function to retrieve data at a given index
void retrieve(struct Node *head, int index) 
{
    struct Node *current = head;
    int i = 0;
    while (current != NULL) 
    {
        if (i == index) 
        {
            printf("Data at index %d: %d\n", index, current->data);
            return;
        }
        current = current->next;
        i++;
    }
    printf("Index %d is not valid.\n", index);
}

// Function to delete a node at a given index (except index 0)
void deleteNode(struct Node *head, int index) 
{
    if (index == 0) 
    {
        printf("Can't delete head in static array.\n");
        return;
    }
    struct Node *current = head;
    int i = 0;
    while (current != NULL && current->next != NULL) 
    {
        if (i == index - 1) 
        {
            current->next = current->next->next;
            printf("Node at index %d deleted.\n", index);
            return;
        }
        current = current->next;
        i++;
    }

    printf("Index %d is not valid.\n", index);
}

// Main function
int main() 
{
    struct Node nodes[SIZE];
    struct Node *head = createList(nodes, SIZE);
    //traversal
    traverse(head);

    // Retrieval
    int idx;
    printf("\nEnter index to retrieve: ");
    scanf("%d", &idx);
    retrieve(head, idx);

    // Deletion
    printf("\nEnter index to delete (except index 0): ");
    scanf("%d", &idx);
    deleteNode(head, idx);

    // Traverse after deletion
    traverse(head);
    return 0;
}
