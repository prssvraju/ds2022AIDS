/* QUEUE OPERATIONS USING LINKED LISTS */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
struct queue
{
	nodeptr front,rear;
};
nodeptr getnode();
void insert(struct queue*,int);
int del(struct queue*);
int empty(struct queue*);
void display(struct queue*);
int main()
{
	int choice,x;
	struct queue q;
	q.rear=NULL;
	q.front=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.Enqueue(push)\n2.Dqueue(pop)\n3.empty\n4.display\n");
		printf("5.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&x);
			insert(&q,x);
			display(&q);
			break;
		case 2:x=del(&q);
			if(x==-1)
				printf("\nQueue is empty");
			else
				printf("deleted item is:%d",x);
			display(&q);
			break;
		case 3:if(empty(&q))
				printf("\nQueue is empty");
			else
				printf("\nQueue is nonempty");
			break;
		case 4:display(&q);
			break;
		case 5:exit(0);
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
	return p;
}
void insert(struct queue *qu,int a)
{
	nodeptr newnode;
	newnode=getnode();
	newnode->info=a;
	if(qu->front==NULL)
	{
	  qu->rear=newnode;
	  qu->front=newnode;
	}
	else
	{
		qu->rear->next=newnode;
		qu->rear=newnode;
	}
 }
int del(struct queue *qu)
{
    int t;
    if(empty(qu))
	return -1;
	else
	{
	     t=qu->front->info;
	     qu->front=qu->front->next;
	     return t;
	}
}
void display(struct queue *qu)
{
	nodeptr p1;
	p1=qu->front;
    if(p1==NULL)
    {
         printf("\nQueue is --EMPTY--\n");
    }
    else{
        printf("\nelements are:\n");
        while(p1!=NULL)
        {
            printf("%d-->",p1->info);
            p1=p1->next;
        }
    }
}
int empty(struct queue *qu)
{
	if(qu->front==NULL)
		return 1;
	else
		return 0;
}