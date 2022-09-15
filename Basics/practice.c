#include<stdio.h>
void getArr(int[10],int);
void printArr(int[10],int);
int main()
{
    int size,a[10];
    printf("Enter size of array");
    scanf("%d",&size);
    getArr(a,size);
    printArr(a,size);
    return 0;
}
void getArr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

}

void printArr(int arr[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }

}

