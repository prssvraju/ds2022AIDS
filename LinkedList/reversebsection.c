#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createlist();
void traversal(struct node*);
struct node* getnode();
struct node *reverselist(struct node *);
struct node* getnode()
{
    struct node *np;
    np=(struct node*)malloc(sizeof(struct node));
    np->data=0;
    np->next=NULL;
    return np;
}
struct node* createlist()
{
    struct node *head,*first,*newnode;
    first=getnode();
    head=first;
    newnode=getnode();
    printf("Enter value:");
    scanf("%d",&newnode->data);
    while(newnode->data!=-9)
    {
        first->next=newnode;
        first=newnode;
        newnode=getnode();
        printf("Enter value:");
        scanf("%d",&newnode->data);
    }
    return head->next;
}
void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
struct node *reverselist(struct node *head)
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
int main()
{
    struct node *np,*rnp;
    np=createlist();
    printf("\nGiven list\n");
    traversal(np);
    printf("\nList in reverse order\n");
    rnp=reverselist(np);
    traversal(rnp);
    
    return 0;
}
