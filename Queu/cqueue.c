#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct  queue
{
    int items[MAX];
    int front,rear;
};
void enqueue(struct queue*,int);
void dequeue(struct queue*);
//int peek(struct queue*);
void display(struct queue*);
int main()
{
    int i;
    int ch,ele;
    struct queue qu;
    qu.front=-1;
    qu.rear = -1;
    while(1)
    {
        printf("\n1.insert/enqueue");
        printf("\n2.delete/Dequeue");
        printf("\n3.Display");
        printf("\n4.peek");
        printf("\n5.Check queue Is empty");
        printf("\n6.Exit");
        printf("Enter choice");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert");
            scanf("%d",&ele);
            enqueue(&qu,ele);
            break;
        case 2:
            dequeue(&qu);
            break;
        case 3:
            display(&qu);
            break;
        case 4:
            printf("Peek");
            //peek(&qu);
            break;
        case 5:
            printf("Empty");
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
  
    return 0;
}

void enqueue(struct queue *qu,int element)
{
    if((qu->front==0 && qu->rear==MAX-1)||(qu->front==qu->rear+1))
    {
        printf("Queue is full");
        return;
    }
    if(qu->front == -1)
    {
        qu->front = 0;
        qu->rear =0;
    }
    else
    {
        if(qu->rear == MAX-1)
        {
            qu->rear = 0;
        }
        else
        {
            qu->rear = qu->rear+1;
        }
    }
    qu->items[qu->rear]=element;
}

void dequeue(struct queue *qu)
{
    int element;
    if(qu->front == -1)
    {
      printf("Queue is under flow");   
      return;
    }
    element = qu->items[qu->front];
    printf("element remove is %d",element);
    if(qu->front==qu->rear)
	{
		qu->front=-1;
		qu->rear=-1;
	}
	else
	{
		if(qu->front == MAX-1)
			qu->front=0;
		else
			qu->front++;
	}
	printf("Element Removed is %d",element);   
}
void display(struct queue *cqu)
{
      int i;
    if(cqu->front == -1)
    {
        printf("Circle queue is empty");
    }
    else
    {
        if(cqu->front <= cqu->rear)
        {
            for(i=cqu->front;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
        else
        {
            for(i=cqu->front;i<=MAX-1;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
            for(i=0;i<=cqu->rear;i++)
            {
                printf("\n%d indexed element is |%d|",i,cqu->items[i]);
            }
        }
    }
}