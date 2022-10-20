#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct  queue
{
    int items[MAX];
    int front,rear;
};
void enqueue(struct queue*,int);
int dequeue(struct queue*);
int peek(struct queue*);
void display(struct queue*);
int main()
{
    int i;
    int ch;
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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