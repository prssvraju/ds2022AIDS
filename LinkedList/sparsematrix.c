#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    int row, column;
    struct node *next;
};
typedef struct node *nodeptr;
nodeptr create(nodeptr, int, int, int);
nodeptr getnode();
void display(nodeptr);
int main()
{
    nodeptr start;
    int i, j, a[10][10], n, m, count;
    count = 0;
    start = NULL;
    printf("\nEnter the row size of array:");
    scanf("%d", &n);
    printf("\nEnter the column size of array:");
    scanf("%d", &m);
    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                count++;
            }
        }
    }

    start = create(start, n, m, count);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                start = create(start, i, j, a[i][j]);
            }
        }
    }

    printf("Sparse Matrix is\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    display(start);
    return 0;
}

nodeptr create(nodeptr start, int x, int y, int z)
{
    nodeptr temp, newnode;
    temp = start;
    newnode = getnode();
    newnode->row = x;
    newnode->column = y;
    newnode->value = z;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return start;
}
nodeptr getnode()
{
    nodeptr p;
    p = (nodeptr)malloc(sizeof(struct node));
    p->row = 0;
    p->column = 0;
    p->value = 0;
    p->next = NULL;
    return p;
}
void display(nodeptr start)
{
    nodeptr temp;
    temp = start;
    printf("\nrow\tcolumn\tvalue\n");
    while (temp != NULL)
    {
        printf("%d\t%d\t%d\n", temp->row, temp->column, temp->value);
        temp = temp->next;
    }
}