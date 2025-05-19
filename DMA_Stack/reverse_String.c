/*
Enter the size of the string: hello
Enter a string: Reversed string: olleh
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Push function: inserts a character into the stack:::::::::::::::::::::::::
void push(char* stack, int* top, int size, char ch) 
{
    if (*top == size - 1) 
    {
        printf("Can't push, Stack is full.\n");
    } 
    else 
    {
        stack[++(*top)] = ch;
    }
}

// Pop function: removes and returns the top character from the stack:::::::::::::::
char pop(char* stack, int* top) 
{
    if (*top == -1) 
    {
        return '\0'; // Stack is empty
    } 
    else 
    {
        return stack[(*top)--];
    }
}

//main()::::::::::::::::::::::::::::::::::::::::::::::::
int main() 
{
    int size;
    printf("Enter the size of the string: ");
    scanf("%d", &size);
    //getchar(); 

    // Allocate memory dynamically
    char* str = (char*)malloc((size + 1) * sizeof(char));         // original string
    char* reverse_str = (char*)malloc((size + 1) * sizeof(char)); // reversed string
    char* stack = (char*)malloc(size * sizeof(char));             // stack
    int top = -1;

    // Check memory allocation
    if (str == NULL || reverse_str == NULL || stack == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(str, size + 1, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character

    // PUSH all characters of the string into the stack
    for (int i = 0; str[i] != '\0'; i++) 
    {
        push(stack, &top, size, str[i]);
    }

    // POP characters from the stack and store them in reverse_str
    int i = 0;
    while (top != -1) 
    {
        reverse_str[i++] = pop(stack, &top);
    }
    reverse_str[i] = '\0';  // Null-terminate the reversed string

    printf("Reversed string: %s\n", reverse_str);

    // Free the dynamically allocated memory
    free(str);
    free(reverse_str);
    free(stack);

    return 0;
}
