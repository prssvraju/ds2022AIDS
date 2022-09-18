#include<stdio.h>
#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif
int main()
{
    bool test;
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