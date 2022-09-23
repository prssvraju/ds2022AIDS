#include<stdio.h>
int fibK(int);
int fibSearch(int[],int,int);
int main()
{
    int n,i;
    int arr[10];
    int k;
    int res;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
     
    res = fibSearch(arr,n,k);
    if(res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d\n",res);
    }
}
int fibSearch(int a[],int n,int k)
{
    int low=0;
    int high=n;
    int loc = -1;
    int flag = 0;
    int index =0;
    printf("low\thigh\tloc\tflag\tindex\tn\n");
    while(flag!=1 && low<=high)
    {
        index=fibK(n);
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",low,high,loc,flag,index,n);
        if(a[index+low]==k)
        {
            flag = 1;
            loc = index + low;
        }
        if(k<a[index+low])
        {
            high=index+low-1;
        }
        else
        {
            low=index+low+1;
        }
        n=high-low+1;
    }
    
    if(flag == 0)
    {
        return -1;
    }
    else
    {
        return loc;
    }
}

int fibK(int n)
{
    int fib1,fib2,fibk;
    fib1=0;
    fib2=1;
    fibk=0;
    fibk=fib1+fib2;
    if(n==0||n==1)
    {
        return 0;
    }
    while(fibk<n)
    {
        fib1=fib2;
        fib2=fibk;
        fibk=fib1+fib2;
    }
    return fib2;
}