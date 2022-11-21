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
struct node* polyAdd(struct node*,struct node*);
int main()
{
    struct node *polyhead1, *polyhead2, *polyhead3;
    int c,e,n1,n2,i;
    polyhead1 = NULL;
    polyhead2 = NULL;
    polyhead3 = NULL;
    printf("No of terms in 1st expression");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter c and e of term %d",i+1);
        scanf("%d%d",&c,&e);
        polyhead1=insertPolyNode(polyhead1,c,e);
    }
    printf("No of terms in 2st expression");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter c and e of term %d",i+1);
        scanf("%d%d",&c,&e);
        polyhead2=insertPolyNode(polyhead2,c,e);
    }
    printf("\nFirst Polynomial Expression\n");
    display(polyhead1);
    printf("\nSecond Polynomial Expression\n");
    display(polyhead2);
    
    printf("\nSum of two Polynomial Expression is \n");
    polyhead3 = polyAdd(polyhead1,polyhead2);
    display(polyhead3);    
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
struct node* polyAdd(struct node *ph1,struct node *ph2)
{
    //struct node *polyh1,*polyh2,*polyh3;
    // struct node *h1=ph1;
    // struct node *h2=ph2;
    // struct node *h3=NULL;
    // while(h1!=NULL && h2 !=NULL)
    // {
    //     if(h1->exp == h2->exp)
    //     {
    //         h3 = insertPolyNode(h3,h1->cof+h2->cof,h1->exp);
    //         h1 = h1->next;
    //         h2 = h2->next;
    //     }
    //     if(h1->exp > h2->exp)
    //     {
    //         h3 = insertPolyNode(h3,h1->cof,h1->exp);
    //         h1 = h1->next;
    //     }
    //     if(h1->exp < h2->exp)
    //     {
    //         h3 = insertPolyNode(h3,h2->cof,h2->exp);
    //         h2 = h2->next;
    //     }
    // }
    // while (h1!=NULL)
    // {
    //     h3 = insertPolyNode(h3,h1->cof,h1->exp);
    //     h1 = h1->next;
    // }
    // while (h2!=NULL)
    // {
    //     h3 = insertPolyNode(h3,h2->cof,h2->exp);
    //     h2 = h2->next;
    // }
    // return h3;


    struct node* ptr1=ph1;
    struct node* ptr2=ph2;
    struct node* head3 = NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp == ptr2->exp)
        {
            head3 = insertPolyNode(head3,ptr1->cof+ptr2->cof,ptr1->exp);
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            head3 = insertPolyNode(head3,ptr1->cof,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp)
        {
            head3 = insertPolyNode(head3,ptr2->cof,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        head3 = insertPolyNode(head3,ptr1->cof,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        head3 = insertPolyNode(head3,ptr2->cof,ptr2->exp);
        ptr2=ptr2->next;
    }
    return head3;

}
struct node * insertPolyNode(struct node* phead,int cof,int exp)
{
    struct node *temp,*newnode;
    temp=phead;
    newnode = getNode(cof,exp);
    // newnode=(struct node *)malloc(sizeof(struct node));
    // newnode->cof=cof;
    // newnode->exp=exp;
    // newnode->next = NULL;
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