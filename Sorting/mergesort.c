#include<stdio.h>
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
    int n,i;
    int arr[10];
    printf("Enter array length");
    scanf("%d",&n);
    printf("%d",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
void mergeSort(int a[],int low, int high)
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

void merge(int a[],int low,int mid,int high)
{
    int b[10];
    int i,j,k;
    i = low;
    j= mid+1;
    k=0;
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
    while(i<=mid)
    {
        b[k++] = a[i++];
    }
    while(j<=high)
    {
         b[k++] = a[j++];
    }

   for(i=high;i>=low; i--)
  {
    a[i] = b[--k];        // copying back the sorted list to a[]
  }

}