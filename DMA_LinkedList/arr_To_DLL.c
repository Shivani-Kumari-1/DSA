/*
:::::::::::::::Array to Doubly Linked List Conversion::::::::::

Linked List : 10 -> 20 -> 30 -> 40 -> NULL

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    struct N *pre;
    int data;
    struct N *next;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
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
//array to DLL conversion:::::::::::::
Node* arrayToDLL(int arr[], int size)
{
    if (size <= 0) 
    {
        return NULL;
    }
    Node* head = createNode(arr[0]);
    Node* temp = head;

    for (int i = 1; i < size; i++)
    {
        Node* newNode = createNode(arr[i]);
        temp->next = newNode;
        newNode->pre = temp;
        temp = newNode;
    }
    return head;
}
//print all node data::::::::::::::::::::
void traversal(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//main function::::::::::::::::::::
int main()
{
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* head = arrayToDLL(arr, size);
    printf("Linked List : ");
    traversal(head);
    return 0;
}
