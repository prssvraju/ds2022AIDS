#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* getNode();
struct node* create();
void traversal(struct node*);
int main()
{
    struct node *np;
    np=create();
    traversal(np);
    return 0;
}
struct node * getNode()
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->data=0;
    np->next =NULL;
    return np;
}

struct node * create()
{
    struct node *head,*first,*newnode;
    first=getNode();
    head=first;
    newnode = getNode();
    printf("Enter the -99 to stop list");
    printf("Enter value");
    scanf("%d",&newnode->data);
    while (newnode->data!=-99)
    {
        first->next = newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter value");
        scanf("%d",&newnode->data);
    }
    
    return head->next;
}

void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
