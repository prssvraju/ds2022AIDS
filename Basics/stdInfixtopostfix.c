#include<stdio.h>
#define max 50
struct stack
{
	char items[max];
	int top;
	
};
struct stack s;

void push(struct stack*,char);
void display(struct stack *);
char pop(struct stack*);
char peek(struct stack*);
int empty(struct stack*);
int isOperand(char);
void infixtopost(char[]);
int isp(char);
int icp(char);
char postfix[max];
int main()
{
	char infix[max];
	s.top=-1;
	printf("enter infix expression\n");
	scanf("%s",infix);
	printf("\n entered inflix expression is %s\n",infix);
	infixtopost(infix);
	return 0;	
}
void infixtopost(char infix[max])
{
	int i,j=0;
	char sym,topsym;
	for(i=0;(sym=infix[i])!='\0';i++)
	{
		//printf("\n--%c",sym);
		if(isOperand(sym))
		{
		 postfix[j]=sym;
		//printf("\n---%c---%c--%d",sym,postfix[j],j);

			j++;
		}
		else if(sym=='(')
		{
			push(&s,sym);
		}
		else if(sym==')')
		{
			topsym=pop(&s);
			while(topsym!='(')
			{
			
				postfix[j]=topsym;
				j++;
				topsym=pop(&s);
			}
		}
		else{
		
			while(!empty(&s) && icp(sym)<=isp(peek(&s)))
			{
				topsym=pop(&s);
				postfix[j]=topsym;
				j++;
			}
			push(&s,sym);
		}
	}		

	while(!empty(&s))
	{
		topsym=pop(&s);
		postfix[j]=topsym;
		j++;
	}
	postfix[j]='\0';
	printf("postfix string is %s\n",postfix);
}
int isOperand(char c)
 {
    if((c>='0' && c<='9') || (c>='a' && c<='z')||(c>='A' && c<='Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }
int icp(char c)
{
	switch(c)
	{
		case'+':
		case'-':return 1;
		case'/':
		case'*':return 2;
		case'$':return 3;
	}
}
int isp(char c)
{
		switch(c)
	{
		case'(':return 0;
		case'+':
		case'-':return 1;
		case'/':
		case'*':return 2;
		case'$':return 3;
	}
}
void push(struct stack *stp,char sym)
{
    if(stp->top == max-1)
    {
        printf("\n---OVER FLOW----");
    }
    else{
        stp->top =stp->top+1;
        stp->items[stp->top]=sym;
    }
}

char pop(struct stack *stp)
{
    char sym;
    if(stp->top == -1)
    {
       return -1; 
    }
    else
    {
        sym=stp->items[stp->top];
        stp->top = stp->top-1;
        return sym;
    }

}

char peek(struct stack *stp)
{
    int sym;
    if(stp->top == -1)
    {
      return -1; 
    }
    else
    {
        sym=stp->items[stp->top];
       return sym;
    }

}
int empty(struct stack *stp)
{
    if(stp->top == -1)
    {
      return 1;
    }
    else
    {
       return 0;
    }

}