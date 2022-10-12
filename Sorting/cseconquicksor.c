
#include<stdio.h>
int mypartition(int[],int,int);
void myquickSort(int[],int,int);
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
    arr[i]=99;
    myquickSort(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
void myquickSort(int a[10],int low, int high)
{
    int j;
    if(low<high)
    {
        j=mypartition(a,low,high+1);
        myquickSort(a,low,j-1);
        myquickSort(a,j+1,high);
    }
}
int mypartition(int a[10],int low,int high)
{
    int i,j,temp,pivot;
    i=low;
    j=high;
    pivot= a[low];
    while(i<j)
    {
        while(a[i]<=pivot && i<high)
        {
            i++;
        }
        while(a[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            temp= a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp =a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

