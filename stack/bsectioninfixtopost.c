#include<stdio.h>
#define MAX 50
struct stack
{
    char item[MAX];
    int top;
};

struct stack st;
char postfix[MAX];

void push(struct stack*,char);
char pop(struct stack*);
char peek(struct stack*);
int empty(struct stack*);
void infixtopostfix(char[]);
int isOperand(char);
int icp(char);
int isp(char);
int main()
{
    st.top=-1;
    char infix[MAX];
    printf("Enter input expression");
    scanf("%s",infix);

    printf("Infix Expression is : %s",infix);
    infixtopostfix(infix);

    return 0;
}
void infixtopostfix(char infix[MAX])
{
    int i,j=0;
    char sym,topsym;
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        if(isOperand(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(sym == '(')
        {
            push(&st,sym);
        }
        else if(sym == ')')
        {
            topsym = pop(&st);
            while(topsym!='(')
            {
                postfix[j]=topsym;
                j++;
                topsym =pop(&st);
            }
        }
        else
        {
            while (!empty(&st) && icp(sym)<=isp(peek(&st)))
            {
                topsym = pop(&st);
                postfix[j]=topsym;
                j++;
            }
            push(&st,sym);    
        }
    }
    while(!empty(&st))
    {
        topsym = pop(&st);
        postfix[j]=topsym;
        j++;
    }
    postfix[j]='\0';
    printf("\nPostfix Sting is %s",postfix);
}
int isOperand(char c)
{
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
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
    switch (c)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '$':return 3;
    }
}
int isp(char c)
{
    switch (c)
    {
        case '(':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '$':return 3;
    }
}
void push(struct stack *stp,char sym)
{
    if(stp->top == MAX-1)
    {
        printf("Stack is over flow");
    }
    else
    {
        stp->top =stp->top+1;
        stp->item[stp->top]=sym;
    }
}
char pop(struct stack *stp)
{
    char sym;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        sym = stp->item[stp->top];
        stp->top=stp->top-1;
        return sym;
    }
}
char peek(struct stack *stp)
{
    char sym;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        sym = stp->item[stp->top];
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