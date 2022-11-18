#include<stdio.h>
#include<stdlib.h>
//typedef struct node* nodeptr;

struct  node
{
    int data;
    struct node * next;
};
struct  stack
{
    struct node* top;
};

struct node* getnode();
void push(struct stack *,int);
void display(struct stack *);
int pop(struct stack *);
int peek(struct stack *);
int empty(struct stack *);
void push(struct stack *st,int ele)
{
    struct node *newnode;
    newnode=getnode();
    newnode->data=ele;
    if(st->top==NULL)
    {
        st->top=newnode;
    }
    else
    {
        newnode->next=st->top;
        st->top=newnode;
    }
}
void display(struct stack *st)
{
    struct node *temp;
    temp=st->top;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
int pop(struct stack *st)
{
    int res;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        res=st->top->data;
        st->top=st->top->next;
        return res;
    }
}
int peek(struct stack *st)
{
    int res;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        res=st->top->data;
        return res;
    }
}
int empty(struct stack *st)
{
    if(st->top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
struct node* getnode()
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}


int main()
{
    struct stack s;
    s.top = NULL;
    int x;

    int ch, element;
    while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.push\n2.pop\n3.empty\n4.peek\n5.display\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&element);
			push(&s,element);
			display(&s);
			break;
        case 2:	x=pop(&s);
			if(x==-1)
				printf("\nstack is empty");
			else
				printf("deleted item is:%d\n",x);
			display(&s);
			break;
		case 3:	x=empty(&s);
			if(x==1)
				printf("\nstack is empty");
			else
				printf("\nstack is nonempty");
			break;
		case 4:	x=peek(&s);
			if(x==-1)
				printf("\nStack is empty");
			else
				printf("\ntop element of the stack:%d",x);
			break;
		case 5:	display(&s);
			break;
		
		case 6:	exit(0);
		}
	}

    return 0;
}

