/*Infix to postfix*/
#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack
{
	int top;
	char items[MAX];
};
struct stack s;
char postfix[MAX];
int isp(char);
int icp(char);
void push(struct stack *,char);
char pop(struct stack *);
int empty(struct stack *);
void  intopost(char []);
int isoper(char);
char peek(struct stack *);
int main()
{

	char infix[MAX];
	s.top=-1;
	printf("enter the infix expression");
	scanf("%s",infix);
	printf("\nthe original infix expression is %s",infix);
	intopost(infix);
	return 0;
 }

void  intopost(char expr[])
{
	int i,j=0;
	char symb,topsymb;

	for(i=0;(symb=expr[i])!='\0';i++)
    {
        if(isoper(symb))
			postfix[j++]=symb;
		else if(symb=='(')
			push(&s,symb);
		else if(symb==')')
		{       topsymb=pop(&s);
			while((!empty(&s))&&(topsymb!='('))
			{
				postfix[j++]=topsymb;
				topsymb=pop(&s);
			}
		}
		else
		{
			while(!empty(&s)&&icp(symb)<=isp(peek(&s)))
			{
				topsymb=pop(&s);
				postfix[j++]=topsymb;
			}
			push(&s,symb);
		}

    }
		
    while(!empty(&s))
    {
        topsymb=pop(&s);
        postfix[j++]=topsymb;
    }
    postfix[j]='\0';
    printf("\npostfix expression is: %s",postfix);


}
int isoper(char symb)
{
	if((symb>='0'&&symb<='9')||(symb>='a'&&symb<='z')||(symb>'A'&&symb<='Z'))
		return 1;
	else
		return 0;
}
void push(struct stack *st,char a)
{
	if(st->top==MAX-1)
	{
		printf("\nstack is overflow");

	}
	else
	{
		st->top++;
		st->items[st->top]=a;
	}

}

char pop(struct stack *st)
{
	char a;
	if(empty(st))
		return -1;
	else
	{
		a=st->items[st->top];
		st->top--;
		return a;
	}
}
int empty(struct  stack *st)
{
	if(st->top==-1)
		return 1;
	else
		return 0;
}
char peek(struct stack *st)
{
	if(empty(&s))
		return -1;
	else
		return st->items[st->top];
}
int isp(char c)
{
	switch(c)
	{
		case '(':return 0;
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '$':return 3;

	}
}
int icp(char c)
{
	switch(c)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '$':return 3;
	}
}