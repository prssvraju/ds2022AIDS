#include<stdio.h>
int re_l_search(int[],int,int);
int main()
{
    int size,i,a[10],key,index;
    printf("Enter the size");
    scanf("%d",&size);
    printf("Enter Element of array");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key value");
    scanf("%d",&key);

    index = re_l_search(a,size,key);
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
int re_l_search(int arr[10],int n,int k)
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
        return re_l_search(arr,n-1,k);
    }
}