#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct stack
{
    struct node *top;
};
struct node* getNode();
void push(struct stack*,int);
void display(struct stack*);
int pop(struct stack*);
int empty(struct stack*);

struct node* getNode()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data =0;
    newNode->next =NULL;
    return newNode;
}

void push(struct stack *st,int ele)
{
    struct node *newnode;
    newnode=getNode();
    newnode->data = ele;

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

int pop(struct stack* st)
{
    int val;
    if(st->top == NULL)
    {
        return -1;
    }
    else{
        val=st->top->data;
        st->top = st->top->next;
        return val;
    }
}
void display(struct stack* st)
{
    struct node *temp;
    temp=st->top;
    while(temp!=NULL)
    {
        printf("|%d|\n",temp->data);
        temp=temp->next;
    }
}

int empty(struct stack *st)
{
    if(st->top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek(struct stack *st)
{
    int val;
    if(st->top==NULL)
    {
        return -1;
    }
    else
    {
        val = st->top->data;
        return val;
    }
}

int main()
{
    struct stack st;
    st.top = NULL;
    int ch,ele;
    int x;
    while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.push\n2.pop\n3.empty\n4.peek\n5.display\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&ele);
			push(&st,ele);
			display(&st);
			break;
        case 2:	x=pop(&st);
			if(x==-1)
				printf("\nstack is empty");
			else
				printf("deleted item is:%d\n",x);
			display(&st);
			break;
		case 3:	
            x=empty(&st);
			if(x==1)
				printf("\nstack is empty");
			else
				printf("\nstack is nonempty");
			break;
		case 4:	
            x=peek(&st);
			if(x==-1)
				printf("\nStack is empty");
			else
				printf("\ntop element of the stack:%d",x);
			break;
		case 5:	display(&st);
			break;
		
		case 6:	exit(0);
		}
	}
    return 0;
}