/*
:::::::::::Doubly Linked List Implementation - (output):::::::::::::::

Original List (Forward traversal) : 1 -> 2 -> 3 -> 4 -> NULL

Original List (backward traversal) : 4 <- 3 <- 2 <- 1 <- NULL

After insertion at head : 11 -> 1 -> 2 -> 3 -> 4 -> NULL

After insertion at tail : 11 -> 1 -> 2 -> 3 -> 4 -> 55 -> NULL

After insertion at Kth position : 11 -> 1 -> 99 -> 2 -> 3 -> 4 -> 55 -> NULL

After deleting head : 1 -> 99 -> 2 -> 3 -> 4 -> 55 -> NULL

After deleting tail : 1 -> 99 -> 2 -> 3 -> 4 -> NULL

After deleting at position 3 : 1 -> 99 -> 3 -> 4 -> NULL

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    struct N *pre;
    int data;
    struct N *next;
} Node;

//createNode() – Creates a node in heap memory and assigns a value:::::::::
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value; 
    newNode->next = NULL;  
    newNode->pre = NULL;
    return newNode;        
}

//ftraversal() – Traverses the entire linked list in forward direction and prints each node's data::::::::::::::::::::::::
void ftraversal(Node* head)
{
    if(head == NULL)
    {
        printf("No linked list found !!\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//btraversal() – Traverses the entire linked list in backward direction and prints each node's data::::::::::::::::::::::::
void btraversal(Node* tail)
{
    if(tail == NULL)
    {
        printf("No linked list found !!\n");
        return;
    }
    Node* temp = tail;
    while(temp != NULL) 
    {
        printf("%d <- ", temp->data);
        temp = temp->pre;
    }
    printf("NULL\n");
}
//insertAtHead() – Inserts the new node at the beginning of the list:::::::::::::::::::::::::::::::::::
Node* insertAtHead(Node* head, int value)
{
    if(head == NULL)
    {
        return createNode(value);
    }
    Node* newNode = createNode(value);
    newNode->next = head;
    head->pre = newNode;
    return newNode;
}
//insertAtTail() – // Inserts a new node at the end of the list :::::::::::::::::::::::::::::::::::::::
Node* insertAtTail(Node* head, int value)
{
    if(head == NULL)
    {
        return createNode(value);
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->next = newNode;
    newNode->pre = temp;
    return head;
}

//insertAtKthPosition() – Inserts a new node at the K-th position in the list :::::::::::::::::::::
Node* insertAtKthPosition(Node* head, int value, int K)
{
    //If the position K is less than or equal to 1, or the list is empty (head is NULL), THEN
    if (K <= 1 || head == NULL)
    {
        return insertAtHead(head, value);
    }

    int i = 1;
    Node* newNode = createNode(value);// Create a new node with the given value
    Node* temp = head;

    while (i != K - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    // Insert the new node between temp and temp->next
    newNode->next = temp->next;// Link newNode to the K-th node
    newNode->pre = temp;// Link newNode back to the (K-1)-th node

    // If K-th node exists, link its previous pointer to newNode
    if (temp->next != NULL)
    {
        temp->next->pre = newNode;
    }

    temp->next = newNode;// Link (K-1)-th node to the new node
    return head;// Return the updated head
}

//DeleteAtHead() - Deletes the node at the beginning of the list:::::::::::::
Node* deleteAtHead(Node* head)
{
    if (head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->pre = NULL; 
    }
    free(temp);
    return head;
}

//deleteAtTail() - Deletes the node at the end of the list::::::::::::::::::::::
Node* deleteAtTail(Node* head)
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
        free(head);
        return NULL;
    }

    // Case 3: If the list has more than one node
    Node* temp = head;
    while (temp->next->next != NULL)
                                   
    {
        temp = temp->next;
    }
    // At this point, temp is pointing to the second-last node
    Node* fourth = temp->next;
    temp->next = NULL;
    free(fourth);
    return head;
}

//deleteAtKthPosition() - Deletes the node at the K-th position in the list:::::::::::::::::::::::::
Node* deleteAtKthPosition(Node* head, int K)
{
    // Case 1: If the list is empty
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    // Case 2: If K is 1, we delete at the head of the list
    if (K <= 1)
    {
        return deleteAtHead(head);
    }

    // Case 3: Traverse to the (K-1)-th node
    int i = 1;
    Node* temp = head;
    // Traverse until the (K-1)th position and the end of the list is reached.(e.g., for deleting at the 3rd position, stop at the 2nd.)
    while (i < K - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    // If K is out of range, i.e., the position is greater than the number of nodes
    if (temp->next == NULL)
    {
        printf("Position out of range!\n");
        return head;
    }

    Node* kposition = temp->next;
    temp->next = kposition->next;

    if (kposition->next != NULL)
    {
        kposition->next->pre = temp; 
    }

    free(kposition);
    return head;
}

int main()
{
    // Section 1: Create nodes with data 1, 2, 3, and 4 and store their addresses

    Node *first = createNode(1); 
    Node *second = createNode(2);
    Node *third = createNode(3);
    Node *fourth = createNode(4);

    // Section 2: Linking the nodes by updating their 'next' pointers

    first->next = second; 
    
    second->pre = first;
    second->next = third; 
    
    third->pre = second;
    third->next = fourth; 

    fourth->pre = third;

    // print all node data in forward direction
    printf("\nOriginal List (Forward traversal) : ");
    ftraversal(first);

    // print all node data in backward direction
    printf("\nOriginal List (backward traversal) : ");
    btraversal(fourth);
    
    //insert at head
    first = insertAtHead(first,11);
    printf("\nAfter insertion at head : ");
    ftraversal(first);

    //insert at tail
    insertAtTail(first,55);
    printf("\nAfter insertion at tail : ");
    ftraversal(first);

    //insert at Kth position
    insertAtKthPosition(first,99,3);
    printf("\nAfter insertion at Kth position : ");
    ftraversal(first);

    //delete at head
    first = deleteAtHead(first);
    printf("\nAfter deleting head : ");
    ftraversal(first);

    //delete at Tail
    first = deleteAtTail(first);
    printf("\nAfter deleting tail : ");
    ftraversal(first);    //1 -> 2 -> 3 -> 4

    //delete at Kth position
    first = deleteAtKthPosition(first, 3);  
    printf("\nAfter deleting at position 3 : ");
    ftraversal(first);
    
    return 0;
}