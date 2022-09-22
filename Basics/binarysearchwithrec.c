#include<stdio.h>
int r_binarys(int[],int,int,int,int);
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

    res=r_binarys(arr,n,k,0,n);
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

int r_binarys(int a[10],int n,int k,int low,int high)
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
    {
        return -1;
    }
    if(a[mid]==k)
    {
        return mid;
    }
    if(k<a[mid])
    {
       return r_binarys(a,n,k,low,mid-1);

    }
    else
    {
       return  r_binarys(a,n,k,mid+1,high);
    }
   
}