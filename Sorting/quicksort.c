#include <stdio.h>
void quicksort(int[],int,int);
int partition(int[],int,int);
int main(void) 
{
	int a[100],i,j,temp,n;
	printf("enter the value of n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
  a[i]=999;
	quicksort(a,0,n);
	printf("//---after sorting---//\n");
	for(i=0;i<n;i++)
		{
			printf("%d\t-[%d]\t\t",a[i],i);
		}
}

void quicksort(int arr[],int p,int q)
{
	int j;
	if(p<q)
	{
		j=partition(arr,p,q+1);
		quicksort(arr,p,j-1);
		quicksort(arr,j+1,q);
	}
}
int partition(int arr[], int fst, int last)
{
//printf("form quick");
 int i,j,pivot,tmp;
 
  pivot=arr[fst];
  i=fst;
  j=last;
  while (i<j) 
  {
    while (arr[i]<=pivot && i<last)
    {
        i++;
    }
    while(arr[j]>pivot && j>fst)
    {
        j--;
    } 
    if(i<j)
    {
      tmp=arr[i];
      arr[i]=arr[j];
      arr[j]=tmp;
    }
  }
  tmp=arr[fst];
  arr[fst]=arr[j];
  arr[j]=tmp;
  return j;
}