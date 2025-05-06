#include<stdio.h>
#include<string.h>
#define SIZE 5
//declaration
char stack[SIZE];
int top = -1;
//pushing all characters onto the stack
void push(char ch)
{
    (top == SIZE - 1) ? printf("Can't push,Stack is full.") : (stack[++top] = ch);
}
//pop function 
char pop()
{
    return(top == -1) ? '\0' : stack[top--];
}
//main function
int main()
{
    char str[SIZE + 1];
    char reverse_str[SIZE + 1];
    printf("Enter a string : ");
    fgets(str,SIZE + 1,stdin);
    str[strcspn(str,"\n")] = '\0';
    //pushing all characters to stack
    for(int i=0 ; str[i] != '\0' ; i++)
    { push(str[i]); }
    //Now print currently popped characters
    int i = 0;
    printf("Reversed string : ");
    while(top != -1)
    {  
        reverse_str[i] = pop(); 
        i++;
    }
    reverse_str[i] = '\0';//VALIDATING NEW STRING
    printf("%s",reverse_str);
    return 0;
}

