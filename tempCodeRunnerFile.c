#include<stdio.h>
int main()
{
    int a[10],n,i,k;
    printf("Enter array size");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);


    }
    printf("Enter Key value");
    scanf("%d",&k);

    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            printf("Enter element is found at %d",i+1);
        }
    }
    if(i>=n)
    {
        printf("Enter element is found at %d",i+1);

    }
    return 0;
}