#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode();
struct node *createlist();
void traversal(struct node *);
struct node *reverse(struct node *);
int main()
{
    struct node *np,*rnp;
    np=createlist();
    traversal(np);
    printf("\nreverse of a list\n");
    rnp=reverse(np);
    traversal(rnp);
    return 0;
}
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data =0;
    newnode->next =NULL;
    return newnode;
}
struct node * createlist()
{
    struct node *head,*first,*newnode;
    first=getnode();
    head=first;
    newnode=getnode();
    printf("enter your value except -9 :");
    scanf("%d",&newnode->data);
    while (newnode->data!=-9)
    {
        first->next=newnode;
        first=newnode;
        newnode=getnode();
        printf("enter your value except -9 :");
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
struct node *reverse(struct node *head)
{
    struct node *temp,*rhead,*newnode;
    temp=head;
    rhead=getnode();
    rhead->data=temp->data;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        newnode=getnode();
        newnode->data=temp->data;
        newnode->next=rhead;
        rhead=newnode;
    }
    return rhead;
}