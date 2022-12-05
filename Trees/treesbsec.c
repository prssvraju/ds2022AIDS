#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node *nodeptr;
nodeptr getNode();
nodeptr create(nodeptr);
void insert(nodeptr,nodeptr);
void inorder(nodeptr);
void preorder(nodeptr);
void postorder(nodeptr);
main()
{
    nodeptr root;
    int ch;
    root =NULL;
    root=create(root);
    
    while(1)
    {
        printf("\n*************\n\n\tMENU\n"); 
        printf("\n*************\n\n1.in order\n2.pre order");
        printf("\n3.post order\n4.exit\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nelements in in oreder is:\n"); 
                    inorder(root);
                    break;
            case 2: printf("\nelements in pre order is:\n");
                    preorder(root); 
                    break;
            case 3: printf("\nelements in pre order is:\n");
                    postorder(root); 
                    break;
            case 4: exit(0);
        }
    }
}

nodeptr getNode()
{
    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct node));
    p->data =0;
    p->left = NULL;
    p->right = NULL;
    return p;
}

nodeptr create(nodeptr root)
{
    nodeptr newnode;
    newnode=getNode();
   printf("enter value except -9");
   scanf("%d",&newnode->data);
   while(newnode->data!=-9)
   {
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        insert(root,newnode);
        newnode=getNode();
        printf("enter value except -9");
        scanf("%d",&newnode->data);

    }

   }
   return root;
}
void insert(nodeptr root, nodeptr newnode)
{
 if(newnode->data<root->data)
 {
    if(root->left==NULL)
    {
        root->left=newnode;

    }
    else
    {
        insert(root->left,newnode);

    }
 }
 if(newnode->data>root->data)
 {
    if(root->right==NULL)
    {
        root->right=newnode;
    }
    else
    {
        insert(root->right,newnode);

    }
 }
}


/* This function displays the tree in inorder fashion */
void inorder(nodeptr temp) {
   if (temp != NULL) {
      inorder(temp->left);
      printf("%d --> ", temp->data);
      inorder(temp->right);
   }
}
/* This function displays the tree in preorder fashion */
void preorder(nodeptr temp) {
   if (temp != NULL) {
      printf("%d --> ", temp->data);
      preorder(temp->left);
      preorder(temp->right);
   }
}
 /* This function displays the tree in postorder fashion */
void postorder(nodeptr temp) {
   if (temp != NULL) {
      postorder(temp->left);
      postorder(temp->right);
      printf("%d --> ", temp->data);
   }
}