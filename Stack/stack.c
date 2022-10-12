#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int item[MAX];
    int top;
} stack;

void push();
void display();
void pop();
int main()
{
    int ch;
    stack.top=-1;
    while (1)
    {
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Check Stack Is empty");
        printf("\n6.Exit");
        printf("\n\nEnter your Choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Push");
            push();
            break;
        case 2:
            printf("Pop");
            pop();
            break;
         case 3:
            printf("Display");
            display();
            break;
         case 4:
            printf("Peek");
            break;
         case 5:
            printf("Check Stack Is empty");
            break;
         case 6:
            printf("Exit");
            exit(0);
            break;
        
        default:
            printf("Invalid choice");
            break;
        }
    }
    

    
    
    return 0;

}
void push()
{
    int element;
    if(stack.top == MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
        printf("Enter Element to be pushed into Stack");
        scanf("%d",&element);
        stack.top=stack.top+1;
        stack.item[stack.top]=element;
    }
}
void pop()
{
    int element;
    if(stack.top == -1)
    {
         printf("Stack is Empty");
    }
    else
    {
        element = stack.item[stack.top];
        stack.top = stack.top -1;
        printf("Element Removed for stack is %d",element);   
    }
}
void display()
{
    int i;
    if(stack.top==-1)
    {
         printf("Stack is Empty");
    }
    else
    {
        for(i=stack.top;i>=0;i--)
        {
             printf("\n|%d|",stack.item[i]);
        }
    }
}