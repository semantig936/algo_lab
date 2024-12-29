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
}

// creating the binary tree
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

// come on Fox, trust yourself and try to do this
// key is the element whose predecessor you've got to find
struct node* findPredecessor(struct node* root, struct node* predecessor, int key)
{
    printf("\nEntered findPredecessor, root->data=%d",root->data);
    if(root->data == key)
    {
        return root->left;
    }
    if(root == NULL)
    {
        return predecessor;
    }
    if(key < root->data)
    {
        return findPredecessor(root, predecessor, key);
    }
    if(key > root->data)
    {
        predecessor->data = root->data;
        return findPredecessor(root, predecessor, key);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of nodes in the binary search tree: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    struct node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]); 
    }
    struct node* predecessor = createNode(-1);
    int key;
    printf("\nEnter the element whose predecessor you wanna find: ");
    scanf("%d",&key);
    predecessor = findPredecessor(root, predecessor, key);
    printf("\nPredecessor of the given element is: %d",predecessor->data);
    return 0;
}