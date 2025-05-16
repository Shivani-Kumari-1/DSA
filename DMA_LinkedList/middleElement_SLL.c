#include<stdio.h>
#include<stdlib.h>
// Define the structure for a node
typedef struct Node
{
    int data;   // Data field
    struct Node* next;  //pointer field
}Nodes;// 'Nodes' is a typedef alias for 'struct Node'

//createNode() – Creates a node in heap memory and assigns a value:::::::::
Nodes* createNode(int value)
{
    // Dynamically allocates memory on the heap for a Nodes structure, casts it to Nodes*, and stores the address in newNode
    Nodes* newNode = (Nodes*)malloc(sizeof(Nodes));
    
    // Checks if memory allocation was successful to avoid crashes due to null pointer access when memory is unavailable
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;// Assigns the value to the data field of the newly created node
    newNode->next = NULL;// Sets the next pointer to NULL because there is no next node
    return newNode;// Returns the address of the newly created node
}

//traverse() – Traverses the entire linked list and prints the data of each node::::::::::::::::::::::::
void traverse(Nodes* head)
{
    if(head == NULL)// If the list is empty (head is NULL)
    {
        printf("No linked list found !!");//It will print "No linked list found" MESSAGE
        return; //and exit from the function.
    }

    // The 'head' is assigned to 'temp' to safely traverse the list without modifying the original 'head' pointer.
    Nodes* temp = head;

    while(temp != NULL)// Traverse the list starting from 'temp' (which points to 'head') until reaching the end (NULL).
    {
        printf("%d ",temp->data);// Print the data of each node
        temp = temp->next;// Move 'temp' to the next node.
    }
    printf("\n");//not necessary
}
//insertAtHead() – Inserts the new node at the beginning of the list:::::::::::::::::::::::::::::::::::
Nodes* insertAtHead(Nodes* head, int value)
{
    if(head == NULL) //Check if the list is empty (head is NULL). then
    {
        return createNode(value);//create a new node and return it as the new head.
    }
    Nodes* newNode = createNode(value);//If the list is not empty, create a new node and assign with given value.
    newNode->next = head;//Set the next pointer of the new node to point to the current head.
    return newNode;//Return the new node as the new head of the list.
}
//insertAtTail() – // Inserts a new node at the end of the list :::::::::::::::::::::::::::::::::::::::
Nodes* insertAtTail(Nodes* head, int value)
{
    if(head == NULL)//same logic,if head is empty then
    {
        return createNode(value);//create a new node and return it as the new head.
    }
    Nodes* newNode = createNode(value);//If the list is not empty, create a new node and assign with given value.
    Nodes* temp = head;// Create a temporary pointer (temp) to traverse the list starting from head.
    while (temp->next != NULL)// Traverse the list to reach the last node.
    {
        temp = temp->next; // Update temp to point to the next node in the list, means go one step forward in the linked list.
    }
    temp->next = newNode;//Set the last node's next pointer to the newNode, inserting it at the end of the list
    return head;// Return the unchanged head since the head hasn't changed.
}
//insertAtKthPosition() – Inserts a new node at the K-th position in the list :::::::::::::::::::::
Nodes* insertAtKthPosition(Nodes* head, int value, int K)
{
    if (K <= 1 || head == NULL)//If the position K is less than or equal to 1, or the list is empty (head is NULL), THEN
    {
        return insertAtHead(head, value);// Call insertAtHead() to insert the newNode at the head (at the beginning).
    }
    int i=1;// Created an integer variable 'i' to track the position, initialized to 1 since the first node is at position 1.
    Nodes* newNode=createNode(value);// Create a new node and assign the given value to it and
                                        //store its address in the newNode pointer.

    Nodes* temp = head; // The 'head' is assigned to 'temp' to safely traverse the list without modifying the original 'head' pointer.
    while(i != K-1 && temp->next != NULL)// Traverse until the (K-1)th position and the end of the list is reached, 
                                        //e.g., for inserting at the 3rd position, stop at the 2nd.
    {
        temp = temp->next;// Update temp to point to the next node in the list, means go one step forward in the linked list.
        i++; // Increment the position counter.
    }

    // Update the links to insert the new node at position K.
    newNode->next = temp->next;// Update the link to insert the new node, which now points to the next node.
    temp->next = newNode;// The (K-1)th node now points to the new node, effectively inserting it at position K.
    return head;// Return the unchanged head since the head hasn't changed.
} 
//DeleteAtHead() - Deletes the node at the beginning of the list::::::::::::::::::::::::::::::
Nodes* deleteAtHead(Nodes* head)
{
    if (head == NULL)//same logic,if head is empty then
    {
        printf("List is already empty!\n");//It will print "List is already empty!" MESSAGE
        return NULL;//return NULL, since there is no node to delete
    }
    Nodes* temp = head; // Stored the head in a temporary pointer
    head = head->next; // Move the head to the next node, now next head is valid head
    free(temp); // Free the memory of the old head to avoid memory leak
    return head;// Return the updated head pointer                
}

//deleteAtTail() - Deletes the node at the end of the list::::::::::::::::::::::::::::::::::::::
Nodes* deleteAtTail(Nodes* head)
{
    // Case 1: If the list is empty
    if (head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }

    // Case 2: If there is only one node in the list
    if (head->next == NULL) 
    {
        free(head);// Free the only node
        return NULL;// Return NULL because the list is now empty
    }

    // Case 3: If the list has more than one node
    Nodes* temp = head;// The 'head' is assigned to 'temp' to safely traverse the list without modifying the original 'head' pointer.
    while (temp->next->next != NULL) // Traverse to the second-last node (node before the tail)
    {
        temp = temp->next; // Move to the next node to continue traversal
    }

    // At this point, temp is pointing to the second-last node
    free(temp->next);       // Free the last node's memory
    temp->next = NULL;      // Remove the last node by setting the next pointer to NULL
    return head;  // Return the updated head of the list
}
//deleteAtKthPosition() - Deletes the node at the K-th position in the list:::::::::::::::::::::::::
Nodes* deleteAtKthPosition(Nodes* head, int K)
{
    // Case 1: If the list is empty
    if (head == NULL)
    {
        printf("List is empty!\n");// Print message if list is empty
        return NULL;// Return NULL because there are no nodes to delete
    }

    // Case 2: If K is 1, we delete at the head of the list
    if (K <= 1)
    {
        return deleteAtHead(head);// Call the deleteAtHead function for K = 1
    }

    // Case 3: Traverse to the (K-1)-th node
    int i = 1;// Created an integer variable 'i' to track the position, initialized to 1 since the first node is at position 1.
    Nodes* temp = head;// The 'head' is assigned to 'temp' to safely traverse the list without modifying the original 'head' pointer.

    // Traverse until the (K-1)th position and the end of the list is reached.(e.g., for deleting at the 3rd position, stop at the 2nd.)
    while (i < K - 1 && temp->next != NULL)
    {
        temp = temp->next;// Move to the next node
        i++;// Increment the position counter.
    }
    
    // If K is out of range, i.e., the position is greater than the number of nodes
    if (temp->next == NULL)
    {
        printf("Position out of range!\n");//print error message
        return head;// Return the original head without making any changes to the list
    }
    Nodes* delposition = temp->next;// Save the node to be deleted (temp->next is the K-th node)
    temp->next = temp->next->next;//This updates the next pointer of the (K-1)th node (temp) to point to the (K+1)th node.

    free(delposition);// Free the memory of the deleted node to avoid memory leak
    return head;// Return the updated head of the list after deletion
}


int main()
{
    // Section 1: Create nodes with data 1, 2, 3, and 4 and store their addresses
    
    Nodes* first = createNode(1);// first is a pointer pointing to the node with data 1
    Nodes* second = createNode(2);// second is a pointer pointing to the node with data 2
    Nodes* third = createNode(3); // third is a pointer pointing to the node with data 3
    Nodes* fourth = createNode(4);// fourth is a pointer pointing to the node with data 4

    // Section 2: Linking the nodes by updating their 'next' pointers

    first->next=second;// first node's next points to second node
    second->next=third;// second node's next points to third node
    third->next=fourth;// third node's next points to fourth node

    // Section 3: print all node data
    printf("\nOriginal List : ");
    traverse(first);// Function that prints the entire list starting from 'first'

    // Insert a node with data 11 at the head of the list
    first = insertAtHead(first,11);
    printf("\nAfter insertion at head : ");
    traverse(first);// Print the list after inserting at head

    // Insert a node with data 44 at the tail of the list
    insertAtTail(first,44);
    printf("\nAfter insertion at tail : ");
    traverse(first);// Print the list after inserting at tail

    // Insert a node with data 22 at the 3rd position in the list
    insertAtKthPosition(first,22,3);
    printf("\nAfter insertion at 3rd position : ");
    traverse(first);// Print the list after inserting at 3rd position

    // Delete the head of the list
    first = deleteAtHead(first);
    printf("\nAfter deleting head : ");
    traverse(first);// Print the list after deleting the head

    // Delete the tail of the list
    first = deleteAtTail(first);
    printf("\nAfter deleting tail : ");
    traverse(first);  // Print the list after deleting the tail

    // Delete the node at the 3rd position in the list
    first = deleteAtKthPosition(first, 3); // 3rd position node will be deleted 
    printf("\nAfter deleting at position 3 : ");
    traverse(first);// Print the list after deleting the node at position 3
    
    return 0;
}


