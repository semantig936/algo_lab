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

struct node* findMin(struct node* root)
{
    struct node* ptr = root;
    while(ptr->left)
    {
        ptr = ptr->left;
    }
    return ptr;
}

struct node* findSuccessor(struct node* root, struct node* successor, int key)
{
    if(root==NULL)
    {
        return successor;
    }
    if(key == root->data)
    {
        if(root->right)
        {
            return findMin(root->right);
        }
        else
        {
            return successor;
        }
    }
    if(key < root->data)
    {
        successor = root;
        return findSuccessor(root->left, successor, key);
    }
    if(key > root->data)
    {
        return findSuccessor(root->right, successor, key);
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
    struct node* root = NULL; 
    for(int i=0; i<n; i++)
    {
        root = createBST(root, arr[i]);
    }
    int k;
    printf("\nEnter the key element: ");
    scanf("%d",&k);
    struct node* successor = createNode(-1);
    successor = findSuccessor(root, successor, k);
    printf("\nThe successor is: %d",successor->data);
    return 0;
}