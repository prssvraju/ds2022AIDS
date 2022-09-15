#include<stdio.h>
//AIDS COde
int fact(int);
int main()
{
    int n;
    printf("Enter Number");
    scanf("%d",&n);
    printf("Fact of givne numbr %d is %d",n,fact(n));
    return 0;
}
int fact(int num)
{
    if(num ==1)
    {
        return 1;
    }
    else
    {
        return num*fact(num-1);
    }
}