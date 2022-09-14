#include<stdio.h>
int r_lsearch(int[],int,int);
int main()
{
    int n,i;
    int arr[10];
    int k;
    int index;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
    index = r_lsearch(arr,n,k);
    if(index == -1)
    {
        printf("Element is not found");
    }
    else
    {
        printf("Element is  found at %d",index+1);
    }
    return 0;
}
int r_lsearch(int arr[],int n, int k)
{
    if(n<0)
    {
        return -1;
    }
    else if(arr[n] == k)
    {
        return n;
    }
    else
    {
        return r_lsearch(arr,n-1,k);
    }
}