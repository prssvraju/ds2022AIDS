#include<stdio.h>
#define max  10
struct stk
{
	int items[max];
	int top;
};
void push(struct stk*,int);
void pop(struct stk*);
void peak(struct stk*);
void display(struct stk*);
int main()
{
    int i,j,k;
	struct stk s;
	s.top=-1;	
	printf("\n-----Main-------");
	//printf("\nValue of top in stack is %d",s.top);
	//for(i=0;i<max;i++)
	//{
		push(&s,1);
		push(&s,5);
		push(&s,6);
		peak(&s);
		push(&s,8);
		push(&s,7);
		pop(&s);
	//}
	display(&s);
}
void push(struct stk *s,int e)
{
	if(s->top==max-1)
	{
		printf("over flow\n");
	}
	else
	{
		s->top=s->top+1;
		s->items[s->top]=e;
	}
}
void pop(struct stk *s)
{
	int f;
    if(s->top==-1)
	{
		printf("no elements\n");
	}
	else
	{
		f=s->items[s->top];
		s->top=s->top-1;
		printf("\npoped Element is %d",f);
	}	

}
void display(struct stk *s)
{ 
	int i;

	for(i=s->top;i>=0;i--)
	{
		printf("\nIndex is %d \telements in stack are:%d\t\n",i,s->items[i]);
	}
}
void peak(struct stk *s)
{
	int f;
    if(s->top==-1)
	{
		printf("no elements\n");
	}
	else
	{
		f=s->items[s->top];
		//s->top=s->top-1;
		printf("\nTop element (Peek) :%d\n",s->items[s->top]);
	}	
}
