/*
Reverse elements: 3 2 1 4 5 
*/
#include <stdio.h>
#define SIZE 5

// Declarations
int queue[SIZE];
int start = -1;
int end = -1;
int noe = 0;

// Push function (enqueue)
void push(int data)
{
    if (noe == SIZE)//checking whether queue is full or not
    { 
        printf("Can't push, Queue is full.\n"); 
        return; 
    }

    if (noe == 0)//checking whether queue is empty or not
    {
        start = 0;
        end = 0;
        queue[end] = data;
        noe++;
        return;
    }
    else
    {
        end = (end + 1) % SIZE;  // For circular increment
        queue[end] = data;
        noe++;
    }
}
// Pop function (dequeue)
int poppedElement;
int pop()
{
    if (noe == 0)//check whether queue is empty or not
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int poppedElement = queue[start];

    if(noe == 1)
    {
        poppedElement = queue[start];
        start = -1;
        end = -1;
        noe = 0;
        return poppedElement;
    }
    
    if (noe > 1)
    {   
        poppedElement = queue[start];
        start++;
        noe--;
        return poppedElement;
    }
    else
    {
        start = (start +1) % SIZE;
        noe--;
        poppedElement = queue[start];
    }

}
//peek function
int peek()
{
    if (noe == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[start];
}
//size function
int size()
{
    return noe;
}

// Main function
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    int k = 3;
    int stack[k];           // Stack to reverse the first k elements
    int new_array[SIZE];    // New array to store the result

    //Pop first k elements into stack
    for (int i = 0; i < k; i++) 
    {
        stack[i] = pop(); 
    }

    //Store reversed stack into new_array[i]
    for (int i = 0; i < k; i++) 
    {
        new_array[i] = stack[k - 1 - i]; 
    }

    //Pop remaining elements and store in new_array[i]
    for (int i = k; i < SIZE; i++) 
    {
        new_array[i] = pop();
    }

    //Now Printing result array
    printf("Reverse elements: ");
    for (int i = 0; i < SIZE; i++) 
    {
        printf("%d ", new_array[i]);
    }
    printf("\n");

    return 0;
}
