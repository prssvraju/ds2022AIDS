#include<stdio.h>
int main()
{
    int num=125;
    int rem,rev=0;
    while(num!=0)
    {
        rem=num%10;
        rev=rem+rev*10;
        num=num/10;
    }
    printf("Reverse %d",rev);
}