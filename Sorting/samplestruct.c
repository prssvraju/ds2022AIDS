#include<stdio.h>
#include<stdlib.h>
#define MAX 3
struct stack
{
    int items[MAX];
    int top;
} ;
void push(struct stack*,int);
void display(struct stack*);
void pop(struct stack*);
void peek(struct stack*);
void empty(struct stack*);
int main()
{
    int ch,e;
    struct stack st;
    st.top=-1;

    while (1)
    {
        printf("\n\n***************************\n\n");
        printf("\t\tMENU\n");
        printf("\n***************************\n");
        printf("1.push\n2.pop\n3.empty\n4.peek\n5.display\n6.exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
             printf("Please enter element");
             scanf("%d",&e);
             push(&st,e);

            break;
        case 2:
             printf("pop");
             pop(&st);
            break;
         case 3:
             printf("Empty");
             empty(&st);
            break;
         case 4:
             peek(&st);
             printf("Peek");
            break;
         case 5:
             printf("Display");
             display(&st);
            break;
         case 6:
             printf("Exit");
             exit(0);
            break;
        
        default:
            printf("INvalid choice please re enter choice");
            break;
        }

    }
    
}
void push (struct stack *stp,int ele)
{
    if(stp->top == MAX-1)
    {
        printf("Stack is over flow");
    }
    else
    {
        stp->top=stp->top+1;
        stp->items[stp->top]=ele;
    }
}
void display(struct stack *stp)
{
    int i;
    if(stp->top == -1)
    {
        printf("Stack is Under flow");
    }
    else
    {
        for(i=stp->top;i>=0;i--)
        {
            printf("\n|%d|",stp->items[i]);
        }
    }
}
void pop(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        printf("Stack is Under flow");
    }
    else
    {
        ele=stp->items[stp->top];
        stp->top= stp->top -1;
        printf("Removed Element is %d",ele);
    }
}
void peek(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        printf("Stack is Under flow");
    }
    else
    {
        ele=stp->items[stp->top];
        printf("peek Element is %d",ele);
    }
}
void empty(struct stack *stp)
{
    if(stp->top == -1)
    {
     printf("NO element in stack");
    }
    else
    {
      printf("element in stack");  
    }

}

