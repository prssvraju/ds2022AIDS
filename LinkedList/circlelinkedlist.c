#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node * nodeptr;

nodeptr getnode();
nodeptr insert(nodeptr);
nodeptr insertAtBeg(nodeptr,nodeptr);
nodeptr insertAtEnd(nodeptr,nodeptr);
nodeptr insertAtPos(nodeptr,nodeptr);


nodeptr del(nodeptr);
nodeptr deleteAtBeg(nodeptr);
nodeptr deleteAtEnd(nodeptr);
nodeptr deleteAtPos(nodeptr);



void traversal(nodeptr);

int main()
{
    nodeptr head;
	int choice;
	head=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.delete a node");
		printf("\n3.traversal\n");
		printf("4.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	head=insert(head);
				traversal(head);
				break;
			case 2:	head=del(head);
				traversal(head);
				break;
			case 3: traversal(head);
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
	p->data=0;
	p->next=p;
	return p;
}

nodeptr insertAtBeg(nodeptr headnode,nodeptr newnode)
{
    nodeptr temp;
    temp=headnode;
    while(temp->next!=headnode)
    {
        temp=temp->next;
    }
    newnode->next=headnode;
    temp->next = newnode;
    headnode=newnode;
    return headnode;
    
}


nodeptr insertAtEnd(nodeptr headnode,nodeptr newnode)
{
    nodeptr temp;
    temp=headnode;
    while(temp->next!=headnode)
    {
        temp=temp->next;
    }
    newnode->next=headnode;
    temp->next = newnode;
    return headnode;
}
nodeptr insertAtPos(nodeptr headnode,nodeptr newnode)
{
    nodeptr temp;
    temp= headnode;
    int pos,i;
    printf("enter position");
    scanf("%d",&pos);
    if(pos==1)
    {
        while(temp->next!=headnode)
        {
            temp=temp->next;
        }
        newnode->next=headnode;
        temp->next = newnode;
        headnode=newnode;
        return headnode;
    }
    else
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return headnode;
;
    }

}


nodeptr insert(nodeptr head)
{
	nodeptr firstnode,newnode;
	int k,ch,i;
	//firstnode=head;
	newnode=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=newnode;
		head=newnode;
		return head;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert At Position\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:return(insertAtBeg(head,newnode));
                    break;  
			case 2:return(insertAtEnd(head,newnode));	
                    break;
            case 3:return(insertAtPos(head,newnode));	
                    break;
		}
	}
}

nodeptr deleteAtBeg(nodeptr headnode)
{
	nodeptr temp;
	temp=headnode;
	if(headnode->next==headnode)
	{
		headnode = NULL;
		return headnode;
	}
	else{
		while(temp->next!=headnode)
        {
            headnode=temp->next;
        }
		temp->next->next=temp->next;
		headnode =temp->next;
		return headnode;

	}
}

nodeptr deleteAtEnd(nodeptr firstnode)
{
    
}

nodeptr deleteAtPos(nodeptr firstnode)
{
    
}



nodeptr del( nodeptr p)
{
	int c,i,k;
	nodeptr firstnode;
	firstnode=p;

	if(firstnode==NULL)
	{
		printf("\nlist is empty");
		return firstnode;
	}
	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete At Positon\n");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:return(deleteAtBeg(firstnode));
				   break;
			case 2:return(deleteAtEnd(firstnode));
				   break;
			case 3:return(deleteAtPos(firstnode));
				   break;
		  }
	}
}

void traversal(nodeptr head)
{
	nodeptr temp;
	temp=head;
	printf("\nelements are:\n");
	while(temp->next!=head)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}