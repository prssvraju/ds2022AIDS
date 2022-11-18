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
struct node*insert(struct node*);
struct node*delete(struct node*);
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
int main()
{
     int ch;
    struct node *start;
    start = createList();
    traversal(start);
    while (1)
    {
        printf("\n**************\nMENU\n***********\n");
        printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insert(start);
            traversal(start);
            break;
        case 2:
            //traversal(start);
            break;
        case 3:
            start = delete (start);
            traversal(start);
            break;
        case 4:
            exit(0);

        }
    }
    return 1;
}
struct node*insert(struct node *head)
{
    struct node *temp,*newnode;
    int ch,pos,i;
    temp=head;
    newnode=getNode();
    printf("enter value");
    scanf("%d",&newnode->data);
    printf("\n1.at begining\n2. at end\n3. at given position");
    printf("\nenter your choice:");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            newnode->next=head;
            head=newnode;
            return head;
            break;
        case 2:
            while(temp->next!=NULL)
            {
                temp=temp->next;

            }
            temp->next=newnode;
            return head;
            break;
        case 3:
            printf("enter position");
            scanf("%d",&pos);
            if(pos==1)
            {
                newnode->next=head;
                head=newnode;
                return head;
            }
            else
            {
                for(i=1;i<pos-1;i++)
                {
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                return head;
            }
            break;
    }
}
struct node*delete(struct node *head)
{
    struct node *temp;
    int ch,pos,i;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {

        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=head->next;
                return head;
                break;
            case 2:
                while(temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=NULL;
                return head;
                break;
            case 3:
                printf("enter position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    head=head->next;
                    return head;
                }
                else
                {
                        for(i=1;i<pos-1;i++)
                        {
                            temp=temp->next;

                        }
                        temp->next=temp->next->next;
                }
                return head;
                break;
            
                
                
                
        }
    }

}