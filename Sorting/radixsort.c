#include<stdio.h>
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
    int large=a[0],i;
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
        }
    }
    return large;
}

int noOfDigits(int n)
{
    int digits=0;
    while(n>0)
    {
        digits=digits+1;
        n=n/10;
    }
    return digits;
}

void radixSort(int a[10],int n)
{
    int i,j,k,reminder,divisor=1;
    int bucket[10][12],bc[10];
    int large,nopass,pass;
    large = largest(a,n);
    nopass = noOfDigits(large);
    // printf("Largest is %d",large);
    // printf("No of digits is %d",nopass);
    for(pass=0;pass<nopass;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            reminder = (a[i]/divisor)%10;
            bucket[reminder][bc[reminder]]=a[i];
            bc[reminder] = bc[reminder]+1;
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
        divisor = divisor*10;

    }
}