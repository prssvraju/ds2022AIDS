#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int item[MAX];
    int top;
};

void push(struct stack*,int);
void display(struct stack*);
void pop();
int main()
{
    int ch,element;
    struct stack s;
    s.top = -1;
    
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
            printf("Enter element to push");
            scanf("%d",&element);
            push(&s,element);
            break;
        case 2:
            printf("Pop");
            break;
         case 3:
            printf("Display");
            display(&s);
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
void push(struct stack *st,int ele)
{
    if(st->top == MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
        st->top = st->top+1;
        st->item[st->top]=ele;
    }
}
void display(struct stack *st)
{
    int i;
    if(st->top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=st->top;i>=0;i--)
        {
            printf("\n|%d|",st->item[i]);
        }
    }
}