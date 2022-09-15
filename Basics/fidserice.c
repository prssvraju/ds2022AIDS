#include<stdio.h>
int main()
{
    int f1=0,f2=1,f3=f1+f2;
    int i;
    printf("%d\n%d\n",f1,f2);

    for(i=0;i<10;i++)
    {
        
        printf("%d\n",f3);       
        f1=f2;
        f2=f3;
        f3=f1+f2;
    }
    
}