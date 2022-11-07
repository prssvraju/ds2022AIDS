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
struct node*reverseList(struct node*);
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
    printf("NULL");

}
struct node* reverseList(struct node* head)
{
    struct node *temp,*revHead,*newnode;
    temp=head;
    revHead = getNode();
    revHead->data = temp->data;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        newnode = getNode();
        newnode->data=temp->data;
        newnode->next = revHead;
        revHead=newnode;
    }
    return revHead;
}
int main()
{
    struct node *np,*revHead;
    np=createList();
    printf("\nElement is given Order : \n");
    traversal(np);
    printf("\nElement is Reverse Order : \n");
    revHead = reverseList(np);
    traversal(revHead);
    return 1;
}
