#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int left;
    int right;
};

struct node* createNode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* createBST(struct node* root, int key)
{
    if(root == NULL)
    {
        root = createNode(key);
        return root;
    }
    if(key < root->data)
    {
        root->left = createBST(root->left, key);
    }
    else
    {
        root->right = createBST(root->right, key);
    }
    return root;
}



int main()
{
    int n;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d",&n);
    int x;
    printf("Enter the node values of your tree: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
    }
    int* arr = (int*)malloc(n*sizeof(int));
}