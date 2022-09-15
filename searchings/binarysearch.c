#include<stdio.h>
//#include<conio.h>

int binarysearch(int arr[],int si,int ei,int k)
{
    int mid = 0;
    while(si<=ei)
    {
        mid=(si+ei)/2;
        printf("--------\n");
        printf("Starting index : %d\n",si);
        printf("Ending index : %d\n",ei);
        printf("Midle index : %d\n",mid);
        printf("--------\n");
        if(arr[mid] == k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            ei = mid-1;
        }
        else 
        {
            si = mid+1;
        }
    }
    return -1;
}
int main(void) {
    int n,i;
    int arr[10];
    int k;
    int res;
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to search");
    scanf("%d",&k);
     
    res = binarysearch(arr,0,n,k);
    if(res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d\n",res);
    }
    //getch();
}