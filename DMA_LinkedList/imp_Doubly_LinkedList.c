/*
....Doubly Linked List Implementation....
................output...................

Enter number of nodes (max 5): 5
Enter data for node 1: 1
Enter data for node 2: 2
Enter data for node 3: 3
Enter data for node 4: 4
Enter data for node 5: 5

.........Forward Traversal..........
Node data: 1 | Prev: 00000000 | Current: 0061FEDC | Next: 0061FEE8 
Node data: 2 | Prev: 0061FEDC | Current: 0061FEE8 | Next: 0061FEF4 
Node data: 3 | Prev: 0061FEE8 | Current: 0061FEF4 | Next: 0061FF00 
Node data: 4 | Prev: 0061FEF4 | Current: 0061FF00 | Next: 0061FF0C 
Node data: 5 | Prev: 0061FF00 | Current: 0061FF0C | Next: 00000000 
NULL

Enter index to retrieve: 2
Data at index 2: 3

Enter index to delete: 2
Node at index 2 deleted (logically).

.........Forward Traversal..........
Node data: 1 | Prev: 00000000 | Current: 0061FEDC | Next: 0061FEE8 
Node data: 2 | Prev: 0061FEDC | Current: 0061FEE8 | Next: 0061FF00 
Node data: 4 | Prev: 0061FEE8 | Current: 0061FF00 | Next: 0061FF0C 
Node data: 5 | Prev: 0061FF00 | Current: 0061FF0C | Next: 00000000 
NULL
*/

#include <stdio.h>

#define MAX_SIZE 5  // Define the maximum number of nodes allowed

// Define the structure of a node
struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create and link the list using a static array
struct Node* createList(struct Node nodes[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodes[i].data);
        nodes[i].prev = (i == 0) ? NULL : &nodes[i - 1];
        nodes[i].next = (i == size - 1) ? NULL : &nodes[i + 1];
    }
    return &nodes[0];  // Return head
}
// Traverse the list forward
void traverseForward(struct Node *head) 
{
    printf("\n.........Forward Traversal.......... \n");
    struct Node *current = head;
    while (current != NULL) 
    {
        printf("Node data: %d | Prev: %p | Current: %p | Next: %p\n",
               current->data,
               (void*)current->prev,
               (void*)current,
               (void*)current->next);
        current = current->next;
    }
    printf("NULL\n");
}
// Retrieve data at a given index
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
// Delete node logically by relinking (does not reclaim memory)
void deleteNode(struct Node *head, int index) 
{
    struct Node *current = head;
    int i = 0;
    while (current != NULL) 
    {
        if (i == index) 
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }              
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
                current->prev = NULL;
                current->next = NULL;
                printf("Node at index %d deleted (logically).\n", index);
                return;
            }    
        }
        current = current->next;
        i++;
    }
    printf("Index %d is not valid.\n", index);
}
// Main function
int main() 
{
    int size;
    struct Node nodes[MAX_SIZE];  // Static allocation
    printf("Enter number of nodes (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) 
    {
        printf("Invalid size.\n");
        return 1;
    }
    struct Node *head = createList(nodes, size);
    traverseForward(head);
    // Retrieve
    int idx;
    printf("\nEnter index to retrieve: ");
    scanf("%d", &idx);
    retrieve(head, idx);
    // Delete
    printf("\nEnter index to delete: ");
    scanf("%d", &idx);
    deleteNode(head, idx);
    // Traverse again
    traverseForward(head);
    return 0;
}