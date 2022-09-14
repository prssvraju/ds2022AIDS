#include<stdio.h>
int ** readMatrix(int,int);
void printMatrix(int[][],int,int);
int main()
{
    int n,m,**a;
    printf("Enter the size of matrix in M , N");
    scanf("%d%d",&m,&n);
    a =readMatrix(m,n);

    printMatrix(a,m,n);
}

int ** readMatrix(int m,int n)
{
    int matrix[10][10];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    return matrix;
}
void printMatrix(int a[10][10],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

