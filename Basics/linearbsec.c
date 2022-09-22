#include<stdio.h>
int lsearch(int[],int,int);


int main()
{
    int a[10],n,i,
    
    k,res;
    printf("Enter array size");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);


    }
    printf("Enter Key value");
    scanf("%d",&k);

    res=lsearch(a,n,k);
    if(res==-1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d",res);
    }


    
    return 0;
}

int lsearch(int arr[],int n,int k)
{
    int i;
    for(i=0;i<=n-1;i++)
    {
        if(arr[i]==k)
        {
            return i;
        }
    }
    return -1;
}