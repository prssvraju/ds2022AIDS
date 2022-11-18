#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
struct stack
{
    int items[MAX];
    int top;
};
double oper(char,double,double);
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
double eval(char []);
int isdigit(char);
int main()
{
    char exp[10];
    printf("Enter expersion");
    scanf("%s",exp);
    printf("%s  expersion",exp);
    printf("Result is %f",eval(exp));
    return 0;
}
double eval(char ex[])
{
    int i;
    char c;
    double opnd1,opnd2,value;
    struct stack s;
    s.top=-1;
    for(i=0;(c=ex[i])!='\0';i++)
    {
        if(isdigit(c))
        {
            push(&s,(double)c-'0');
        }
        else
        {
            //printf(" %d\t%c",i,c);
			opnd2=pop(&s);
			opnd1=pop(&s);
			value=oper(c,opnd1,opnd2);
			push(&s,value);

        }
    }
    return pop(&s);
}

int isdigit(char symb)
{
	return(symb>='0'&&symb<='9');
}
double oper(char symb,double op1,double op2)
{
	switch(symb)
	{
		case '+':return(op1+op2);

		case '-':return(op1-op2);

		case '*':return(op1*op2);

		case '/':return(op1/op2);

		case '$':return(pow(op1,op2));

		default:printf("\nillegal operation");
			exit(0);
	}
}
void push(struct stack *st,double a)
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
double pop(struct stack *st)
{
	double a;
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