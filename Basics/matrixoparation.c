#include<stdio.h>
const int MAXROWS = 10;
const int MAXCOLS = 10;
void readMatrix(int[MAXROWS][MAXCOLS],int[MAXROWS][MAXCOLS],int,int,int,int);
void printMatrix(int[MAXROWS][MAXCOLS],int,int);
void matrixAdd(int[MAXROWS][MAXCOLS],int[MAXROWS][MAXCOLS],int[MAXROWS][MAXCOLS],int,int,int,int);
void matrixMul(int[MAXROWS][MAXCOLS],int[MAXROWS][MAXCOLS],int[MAXROWS][MAXCOLS],int,int,int,int);

int main()
{
    int arr1[10][10],arr2[10][10];
    int result[10][10];
    int m,n,p,q;
    printf("Entern Size of firt Matrix");
    scanf("%d%d",&m,&n);
    printf("Entern Size of Second Matrix");
    scanf("%d%d",&p,&q);
    while (n != p)
	{
		printf("Error! column of first matrix not equal to row of second.\n");
		printf("Enter rows and column for first matrix: ");
		scanf("%d%d", &m, &n);
		printf("Enter rows and column for second matrix: ");
		scanf("%d%d", &p, &q);
	}

    readMatrix(arr1,arr2,m,n,p,q);
    //matrixAdd(arr1,arr2,result,m,n,p,q);
    matrixMul(arr1,arr2,result,m,n,p,q);
    printMatrix(arr1,m,n);
    printMatrix(arr2,p,q);
    //for multiplication display need to handled like M and Q
    printMatrix(result,m,q);

}
void matrixMul(int a[10][10],int b[10][10],int res[10][10],int m,int n,int p,int q)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            res[i][j] = 0;
            for(k=0;k<n;k++)
            {
				res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void matrixAdd(int a[10][10],int b[10][10],int res[10][10],int m,int n,int p,int q)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            res[i][j]=a[i][j]+b[i][j];
        }
    }
}
void readMatrix(int a[10][10],int b[10][10],int m,int n,int p,int q)
{
    int i,j;
    printf("Enter 1 st matrix values\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter 2nd matrix values\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}

void printMatrix(int res[10][10],int m,int n)
{
    int i,j;
    printf("Matrix Values are \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
}

