#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
void display(struct stack*);
void pop(struct stack*);
void peek(struct stack*);
void isEmpty(struct stack*);

int main()
{
    int ch;
    struct stack st;
    st.top=-1;
    int ele;
    
    while(1)
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
            printf("Enter element to insert");
            scanf("%d",&ele);
            push(&st,ele);
            break;
        case 2:
            pop(&st);
            break;
       case 3:
            isEmpty(&st);
            break; 
        case 4:
            peek(&st);
            break;
        case 5:
            display(&st);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Choise");
            break;
        }

    }

}
void push(struct stack *stp,int ele)
{
    if(stp->top == MAX-1)
    {
        printf("\n---OVER FLOW----");
    }
    else{
        stp->top =stp->top+1;
        stp->items[stp->top]=ele;
    }
}
void display(struct stack *stp)
{
    int i;
    if(stp->top == -1)
    {
        printf("\n---UNDER  FLOW(EMPTY)----");
    }
    else
    {
        for(i=stp->top;i>=0;i--)
        {
            printf("|%d|\n",stp->items[i]);
        }
    }
   
}
void pop(struct stack *stp)
{
    int ele;
    if(stp->top == -1)
    {
       printf("\n---UNDER  FLOW(EMPTY)----"); 
    }
    else
    {
        ele=stp->items[stp->top];
        stp->top = stp->top-1;
        printf("Poped element is %d",ele);
    }

}

void peek(struct stack *stp)
{
    int ele;
    if(stp->top == -1)
    {
       printf("\n---UNDER  FLOW(EMPTY)----"); 
    }
    else
    {
        ele=stp->items[stp->top];
        printf("Peek element is %d",ele);
    }

}
void isEmpty(struct stack *stp)
{
    if(stp->top == -1)
    {
       printf("\n---UNDER  FLOW(EMPTY)----"); 
    }
    else
    {
        printf("\nStack contains elements"); 
    }

}
