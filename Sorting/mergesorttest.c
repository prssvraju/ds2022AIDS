#include<stdio.h>
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
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
    mergeSort(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=0;i<=n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
void mergeSort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[10],int low,int mid,int high)
{
    int b[10];
    int i,j,k;
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++; 
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }
   for(k=low;k<=high;k++)
   {
    a[k]=b[k];
   }
}