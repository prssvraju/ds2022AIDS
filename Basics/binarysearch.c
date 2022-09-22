#include<stdio.h>
int binarys(int[],int,int);
int main()
{
    int arr[10],n,k,res,i;
    printf("Enter the size of array");
    scanf("%d",&n);

    printf("Enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Key value");
    scanf("%d",&k);

    res=binarys(arr,n,k);
    if(res == -1)
    {
     printf("Element not found");   
    }
    else
    {
        printf("Element is found at %d",res+1);   
    }
    return 0;
}

int binarys(int a[10],int n,int k)
{
    int i,mid,low,high;
    low=0;
    high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==k)
        {
            return mid;
        }
        if(k<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}