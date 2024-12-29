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
    printf("\nSomething really seems to be wrong with VS code");
    int k1, k2;
    printf("\nEnter k1: ");
    scanf("%d",&k1);
    printf("\nEnter k2: ");
    scanf("%d",&k2);
    printf("\nThe two values taken as input are: k1=%d, k2=%d",k1,k2);
    printf("\nTaken input of the two values...");
    struct node* ancestor;
    if(k1 < k2)
    {
        ancestor = LCA(root, k2, k1);
    }
    else
    {
        ancestor = LCA(root, k1, k1);
    }
    printf("\nIt's executed till here");
    if(ancestor)
    {
        printf("\nThe common ancestor is: %d",ancestor->data);
    }
    else
    {
        printf("\nNo as such common ancestor.");
    }
    return 0;
}