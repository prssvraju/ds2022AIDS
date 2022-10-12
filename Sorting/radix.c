#include<stdio.h>
int largest(int[],int);
int noOfDigits(int n);
void radixSort(int[],int);
int main()
{
    int n,i;
    int arr[10];
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    radixSort(arr,n);
    printf("Elements after Sorting"); 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
int largest(int a[10],int n)
{
    int large,i;
    large=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large = a[i];
        }
    }
    return large;
}

int noOfDigits(int n)
{
    int digits = 0;
    while(n>0)
    {
        digits++;
        n=n/10;
    }
    return digits;
}
void radixSort(int a[10],int n)
{
    int bucket[10][12];
    int bc[10];
    int rem,div=1;
    int i,j,k;
    int l,nopass,pass;
    l = largest(a,n);
    nopass = noOfDigits(l);
    printf("\nLargest Number is %d",l);
    printf("\n Number of digits is %d\n",nopass);
    for(pass=0;pass<nopass;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            rem=(a[i]/div)%10;
            bucket[rem][bc[rem]]=a[i];
            bc[rem]=bc[rem]+1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bc[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        div=div*10;
    }

}