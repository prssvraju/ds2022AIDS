#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node*getNode();
struct node*createList();
void traversal(struct node*);
struct node* getNode()
{
    struct node *np;
    np = (struct node *) malloc(sizeof(struct node));
    np->data=0;
    np->next = NULL;
    return np;
}
struct node* createList()
{
    struct node *head,*first,*newnode;
    first=getNode();
    head=first;
    newnode=getNode();
    printf("Enter other than -99");
    scanf("%d",&newnode->data);
    while(newnode->data!=-99)
    {
        first->next=newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter other than -99");
        scanf("%d",&newnode->data);
    }
    return head;
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
    printf("NULL");

}
int main()
{
    struct node *np;
    np=createList();
    traversal(np);
    return 1;
}