#include<stdio.h>
float addArr(int[],int);
int main()
{
    int i,n,a[10];
    float avg;
    printf("enter number");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    avg=addArr(a,n);
    printf("Average is %f",avg);

    return 0;
}
float addArr(int a[],int n)
{
    int res,i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum/n;
}