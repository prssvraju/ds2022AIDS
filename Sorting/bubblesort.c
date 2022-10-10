#include<stdio.h>
void bubbleSort(int[],int);
void selectionSort(int[],int);
void insertionSort(int[],int);
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
    insertionSort(arr,n);
    printf("Elements after Sorting"); 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
void insertionSort(int arr[10],int n)
{
    int i,j,temp;
    printf("---InsertionSort---\n");
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
}
void bubbleSort(int arr[10],int n)
{
   int i,j,temp;
   for(i=0;i<n-1;i++)
   {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
   }
}
void selectionSort(int a[],int n)
{
    int min,i,j,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}