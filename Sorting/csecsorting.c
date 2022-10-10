#include<stdio.h>
void bubbleSort(int[],int);
void selectionSort(int[],int);
void insertSort(int[],int);
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
    insertSort(a,n);
    printf("\n--Elements After sorting--\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }



    return 0;
}
void bubbleSort(int a[10],int n)
{
    int i,j,temp;
    printf("\n---BubbleSort---");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selectionSort(int a[10],int n)
{
    int i,j,min,temp;
    printf("\n---SelectionSort---");
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;

    }
}
void insertSort(int a[10],int n)
{
    int i,j,temp;
        printf("\n---InsertionSort---");

    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=temp;
    }
}