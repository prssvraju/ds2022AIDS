/* Insertion operations in DOUBLE Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next, *prev;
};
typedef struct node *nodeptr;
nodeptr getnode();
void create();
void traversal();

void insert();
void insertbeg(nodeptr);
void insertend(nodeptr);
void insertAtPos(nodeptr);

void delete();
void deleteAtBeg();
void deleteAtEnd();
void deleteAtPos();


nodeptr first,last;
int main()
{
	int choice;
	create();
	traversal();
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.traversal\n3.Delete");
		printf("\n4.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	insert();
				    traversal();
				    break;
			case 2:	traversal();
				    break;
            case 3: delete(first);
                    traversal();
                    break;
			case 4:	exit(0);
		}
	}
    return 0;
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void insert()
{
	nodeptr newnode;
	int ch;
	newnode=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&newnode->info);
	if(first==NULL)
	{
		first=newnode;
		last=newnode;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert At Position\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insertbeg(newnode);
				break;
			case 2:	insertend(newnode);
				break;
            case 3: insertAtPos(newnode);
                break;
		}
	}
}
void traversal()
{
	nodeptr p1;
	p1=first;
	printf("\nelements are:\n");
	while(p1!=NULL)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
	printf("\nelements in reverse order\n");
	p1=last;
	while(p1!=NULL)
	{
	      printf("%d-->",p1->info);
	      p1=p1->prev;
	}

}
void insertbeg(nodeptr newnode)
{
	newnode->next=first;
	first->prev=newnode;
	first=newnode;
}
void insertend(nodeptr newnode)
{
	
	last->next=newnode;
	newnode->prev=last;
	last=newnode;
}

void insertAtPos(nodeptr newnode)
{
    int k,i;
    nodeptr temp;
    printf("\nEnter the position to insert:");
    scanf("%d",&k);
    if(k==1) 
    {
        insertbeg(newnode);
    }
    else
    {
        temp=first;
        for(i=1;i<k-1;i++)
        {
            temp=temp->next;
        }
        if(temp==last)
        {
            insertend(newnode);
        }
        else
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev =newnode;
            temp->next=newnode;
        }
    }

}

void delete()
{
    int c,i,k;
    if(first==NULL)
    {
        printf("\nlist is empty");
    }
    else if(first==last)
    {
        first=last=NULL;
    }
    else
    {
        printf("\nDelete\n1.at begining\n2.at end\n3.delete at given position"); 
        printf("\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: deleteAtBeg();
                    break;
            case 2: deleteAtEnd();
                    break;
            case 3: deleteAtPos();
                    break;
        }
    }
}

void deleteAtBeg()
{
   nodeptr temp;
   temp=first;
   first=first->next;
   temp->next=NULL;
   first->prev=NULL;
}

void deleteAtEnd()
{
    nodeptr temp;
    temp = last;
    last=last->prev;
    last->next = NULL;
    temp->prev =NULL;

}

void deleteAtPos()
{
    int k,i;
    nodeptr temp;
    nodeptr temp2,temp3;

    printf("\nenter the position to delete:");
    scanf("%d",&k);
    if(k==1)
    {
        deleteAtBeg(first);
    }
    else
    {
        temp=first;
        // Move up to postion we are supposed to delete so we need to write K insted of k-1
        for(i=1;i<k;i++)
        {
            temp=temp->next;
        }
        if(temp==last)
        {
            deleteAtEnd(first);
        }
        else
        {
            //make a copy of temp->next and temp->prev in two diffent pointers
            //now assign temp->prev->next value with temp->next(new temp2 pointer variable)
            //assign temp->next->prev value with temp->prev(new temp3 pointer variable)
            // temp->prev->next = temp->next;
            // temp->next->prev =temp->prev;
            // temp->next = NULL;
            // temp->prev = NULL;    

            temp2 = temp->prev;
            temp3 = temp->next;
            temp2->next = temp3;
            temp3->prev = temp2;
            temp->prev = NULL;
            temp->next = NULL;

        }

    }

}

void create()
{

       nodeptr head,firstnode,newnode,temp;
       firstnode=getnode();
       head=firstnode;
       newnode=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&newnode->info);
       while(newnode->info!=-999)
       {
		firstnode->next=newnode;
		newnode->prev=firstnode;
		firstnode=newnode;
		newnode=getnode();
		printf("\nEnter the number:");
		scanf("%d",&newnode->info);
       }
	temp=head->next;
	head->next=NULL;
	temp->prev=NULL;
	first=temp;
	last=firstnode;
}