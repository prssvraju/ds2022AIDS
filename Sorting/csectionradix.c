#include<stdio.h>
int largest(int[],int);
int noOfDigits(int);
void radixSort(int[],int);
int main()
{
    int n,a[10],i;
    printf("Enter size of Array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("--Elements Befor sorting--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    radixSort(a,n);
    printf("\n--Elements After sorting--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
int largest(int a[10],int n)
{
    int large,i;
    large=a[0];
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
        digits++;
        n=n/10;
    }
    return digits;
}
void radixSort(int a[10],int n)
{
    int bucket[10][10],bc[10];
    int i,j,k;
    int div=1,rem;
    int l,nopass,pass;
    l=largest(a,n);
    nopass=noOfDigits(l);
    //printf("\nlargest number is %d",l);
    //printf("\n no of digits is %d",nopass);
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

