#include<stdio.h>
#include<string.h>
struct Person {
  char name[50];
  int citNo;
  float salary;
};
int main()
{
    struct Person p1,p2;
    struct Person *p2ptr;
    p2ptr = &p2;


    p1.citNo=40;
    p1.salary=400.89;
    strcpy(p1.name,"Raghu"); 

    p2ptr->citNo = 50;

    
    

    printf("Name :%s\n",p1.name);
    return 0;
}