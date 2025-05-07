#include <stdio.h>
#define SIZE 5

// declarations.......
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
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    push(50);
    pop();
    pop();

    printf("Peeked value: %d\n", peek());//40
    printf("Current size: %d\n", size());//2

    push(60);
    pop();
    push(70); 

    printf("Peeked value : %d\n", peek());//50
    printf("Final size: %d\n", size());

    return 0;
}