#include<stdio.h>
void bubbleSort(int[],int);
void selectionSort(int[],int);
int main()
{
    int i,n, a[10];
    printf("Enter size of arr");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("---Elements before sorting---\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    insertionSort(a,n);
    printf("\n---Elements After sorting---\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void bubbleSort(int a[10],int n)
{
    int i,j,temp;
    printf("\n---Bubble Sort---\n");

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

}
void selectionSort(int a[10],int n)
{
    int i,j,min,temp;
        printf("\n---Selection sort---\n");

    for(i=0;i<n;i++)
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
