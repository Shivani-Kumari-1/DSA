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

//array to DLL conversion::::::  EVEN  :::::::::::::::::
Node* arrayToDLL_even(int arr[], int size)
{
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < size; i++)
    {
        if(i % 2 == 0)
        {
            Node* newNode = createNode(arr[i]);
            if (head == NULL)
            {
                head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                newNode->pre = temp;
                temp = newNode;
            }
        }
    }
    return head;
}

//array to DLL conversion::::::  ODD  :::::::::::::::::
Node* arrayToDLL_odd(int arr[], int size)
{
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < size; i++)
    {
        if(i % 2 != 0)
        {
            Node* newNode = createNode(arr[i]);
            if (head == NULL)
            {
                head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                newNode->pre = temp;
                temp = newNode;
            }
        }
    }
    return head;
}

void result_traversal(int arr[], int size) 
{
    if (size == 0) 
    {
        printf("Array is empty. No result to display.\n");
        return;
    }

    int result[size];
    int index = 0;

    //Copy arr[i] to result array
    for (int i = 0; i < size; i += 2) 
    {
        result[index++] = arr[i];
    }

    //Copy arr[i] to result array
    for (int i = 1; i < size; i += 2) 
    {
        result[index++] = arr[i];
    }

    //ptint result
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}


//print all node data::::::::::::::::::::
void traversal(Node* head)
{
    if(head == NULL)
    {
        printf("No linked list found!");
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//main function::::::::::::::::::::
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* evenHead = arrayToDLL_even(arr, size);
    printf("\n\nEven index value at Linked List : ");
    traversal(evenHead);

    Node* oddHead = arrayToDLL_odd(arr, size);
    printf("\n\nOdd index value at Linked List : ");
    traversal(oddHead);

    printf("\n\nResult after rearrange Linked List : ");
    result_traversal(arr, size);
    return 0;
}
