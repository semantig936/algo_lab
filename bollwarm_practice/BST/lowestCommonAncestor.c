#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int key)
{
    if(root == NULL)
    {
        root = createNode(key);
        return root;
    }
    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

// I'll assume that k1 is the greater of the two nodes
struct node* LCA(struct node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(k1>=root->data && k2<=root->data)
    {
        return root;
    }
    if(k1<root->data && k2<root->data)
    {
        return LCA(root->left, k1, k2);
    }
    if(k1>root->data && k2>root->data)
    {
        return LCA(root->right, k1, k2);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    // creating the binary tree
    struct node* root;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]);
    }
    int k1, k2;
    printf("\nEnter the values of two nodes which must be looked up: ");
    scanf("%d %d",&k1,&k2);
    struct node* ancestor;
    if(k1 < k2)
    {
        ancestor = LCA(root, k2, k1);
    }
    else
    {
        ancestor = LCA(root, k1, k1);
    }
    return 0;
}