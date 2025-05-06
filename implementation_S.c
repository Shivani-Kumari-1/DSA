#include<stdio.h>
#define SIZE 10

//declaration
int stack[SIZE];
int top = -1;

//push function for insert element on the stack
void push(int element)
{
    if(top == SIZE - 1)
    { printf("Stack is full,can't push next value."); }
    else
    {
        top++;
        stack[top] = element;
    }
}
//pop function for decrease the top index by 1
int pop()
{
    if(top == -1)
    { return -1; }
    else
    {
       return stack[top--];
    }
}
//peek function for return the top element on the stack
int peek()
{
    if(top == -1)
    { return -1; }
    else
    { return stack[top]; }
}
//size function to find the number of elements in the stack
int size()
{
    return top + 1;
}
//main function 
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    printf("\nCurrent stack size : %d",size());//4
    pop();
    pop();
    printf("\nCurrent stack size : %d",size());//2
    printf("\nTop element : %d\n",peek());//20
    printf("Popped element : %d",pop());//currently popped element is 20
    printf("\nTop element : %d\n",peek());//10
    return 0;
}
