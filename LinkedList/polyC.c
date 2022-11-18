#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp,coef;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr create(); 
nodeptr getnode();
void display(nodeptr);
int main()
{
    nodeptr first,second,res;
    first = create();
    printf("\nFirst polynomial is:");
	display(first);
    return 0;

}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->exp=p->coef=0;
	p->next=NULL;
	return p;
}
nodeptr create()
{
    nodeptr head,first,newnode;
    first = getnode();
    head = first;
    newnode = getnode();
    printf("\nenter the expantions in order\n");
	printf("\nEnter the exp -1 at END\n");
	printf("enter the coef &  exp :");
	scanf("%d%d",&newnode->coef,&newnode->exp);
    while(newnode->exp!=-1)
    {
        first->next = newnode;
        first=newnode;
        newnode = getnode();
        printf("\nenter the coef & exp :");
		scanf("%d%d",&newnode->coef,&newnode->exp);
    }
    head=head->next;
	return head;
}
void display(nodeptr head)
{
	nodeptr temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d*X^%d+",temp->coef,temp->exp);
		temp=temp->next;
	}
}