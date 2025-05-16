/*
:::::::::Stack to Singly Linked List implementation::::::::::::::::
::::::::::::::::::::::::::OUTPUT:::::::::::::::::::::::::::::::::::

Total elements in the Stack = 3 2 1 
Size of the stack = 3
top element of the stack=3
top element of the stack=1
Stack is empty!
top element of the stack=-1
Stack is empty!

*/
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node
typedef struct N
{
    int data;   // Data field
    struct N* next;  //pointer field
}Node;// 'Node' is a typedef alias for 'struct Node'

//Define the structure for a stack
typedef struct S
{
    struct N* top;//Points to the top node in the stack (last pushed item)
    int capacity;// Stores the current number of elements in the stack
} Stack;// 'Stack' is a typedef alias for 'struct S'
//createNode() – Creates a node in heap memory and assigns a value:::::::::
Node* createNode(int value)
{
    // Dynamically allocates memory on the heap for a Node structure, casts it to Node*, and stores the address in newNode
    Node* newNode = (Node*)malloc(sizeof(Node));
    
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

//push function 
void push (Stack* stack ,int value)
{
    //check overflow - not needed 
    Node* newNode=createNode(value);
    newNode -> next = stack -> top;
    stack -> top = newNode;
    stack -> capacity++;// Increase when an item is pushed
}
//pop function 
int pop(Stack* stack )
{
    if(stack -> top == NULL )
    {
        printf("Stack is empty \n");
        return -1;
    }
    Node* temp=stack->top;
    stack -> top = stack ->top->next;
    int data = temp->data;
    free(temp);
    stack ->capacity--;// Decrease when an item is popped
    return data;
}
//peek function 
int peek (Stack* stack)
{
    if(stack->top==NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}
//display function 
void display (Stack* stack)
{
    //check whether stack is empty or not 
    if(stack->top == NULL) 
    {
    printf("Stack is empty!\n");
    return;
    }
    Node* temp=stack -> top;
    while (temp!=NULL)
    {
        printf ("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    Stack stack;
    stack.top = NULL;
    stack.capacity = 0;
    push(&stack,1);
    push(&stack,2); 
    push(&stack,3);
    printf("Total elements in the Stack = ");
    display (& stack );
    printf("Size of the stack = %d\n",stack.capacity);
    printf ("top element of the stack=%d\n",peek(&stack));
    int a=pop(& stack);
    int b=pop(& stack);
    printf ("top element of the stack=%d\n",peek(&stack));
    int c=pop(& stack);
    printf ("top element of the stack=%d\n",peek(&stack));
    display (& stack );
    return 0;
}