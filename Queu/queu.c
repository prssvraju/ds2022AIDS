#include<stdio.h>
#include<stdlib.h>
#define MAX 50
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
    qu.front=0;
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
    if(qu->rear == MAX-1)
    {
        printf("Queue is full");
    }
    else
    {
        qu->rear = qu->rear+1;
        qu->items[qu->rear]=element;
    }
}

void dequeue(struct queue *qu)
{
    int element;
    if(qu->rear<qu->front)
    {
      printf("Queue is under flow");   
    }
    else
    {
        element = qu->items[qu->front];
        qu->front++;
        printf("element remove is %d",element);
    }
}
void display(struct queue *qu)
{
    int i;
    if(qu->rear<qu->front)
    {
      printf("Queue is under flow");   
    }
    else
    {
        for(i=qu->front;i<=qu->rear;i++)
        {
         printf("\n%d indexed value is |%d|",i,qu->items[i]);
        }
    }

}