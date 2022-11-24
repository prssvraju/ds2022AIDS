#include<stdio.h>
#include<stdlib.h>
struct node
{
    int cof,exp;
    struct node * next;
};
struct node* insertPolyNode(struct node*,int,int);
void display(struct node*);
struct node* getNode(int,int);
int main()
{
    struct node *polyhead;
    int c,e,n,i;
    polyhead = NULL;
    printf("No of terms in expression");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter c and e of term %d",i+1);
        scanf("%d%d",&c,&e);
        polyhead=insertPolyNode(polyhead,c,e);
    }
    display(polyhead);
    return 0;
}
struct node* getNode(int c,int e)
{
    struct node* pnp;
    pnp=(struct node*)malloc(sizeof(struct node));
    pnp->cof=c;
    pnp->exp=e;
    pnp->next = NULL;
    return pnp;

}
struct node * insertPolyNode(struct node* phead,int cof,int exp)
{
    struct node *temp,*newnode;
    temp=phead;
    newnode = getNode(cof,exp);
    //if head node is null or we are trying to add term with highest exponent it need to add at staring of linke list so we compare exp>temp->exp
    if(temp==NULL||exp>temp->exp) 
    {
        newnode->next = phead;
        phead = newnode;
        return phead;
    }
    else{
        //for checking next node is null we use temp->next!=NULL and
        //find exat location of term based on exp we will check temp->next->exp>exp
         while(temp->next!=NULL && temp->next->exp > exp)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return phead;
}
void display(struct node* thead)
{
    struct node *temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
    //     while(temp->next!=NULL){
    //         printf(" %dx^%d",temp->cof,temp->exp);
    //          temp=temp->next;
    //         if(temp!=NULL)
    //         {
    //             printf("+");
    //         }
    //         else
    //         {
    //             printf("\n");
    //         }
    //     }  
    //    //printf(" %dx^%d ",temp->coef,temp->expo);
    //    printf("%d",temp->cof);
        while(temp!=NULL)
        {
            printf("%d*X^%d+",temp->cof,temp->exp);
            temp=temp->next;
        }
    }
}