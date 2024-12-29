#include<stdio.h>
#include<stdlib.h>

// Note to self: While using a recursive process, if you wanna keep the change in one pariticular variable fixed, use pointers.

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// creating an array in ascending from the BST given, this technique works but I'm trying to go fora better a technique
struct node* kthLargest(struct node* root, int* i, int k)
{
    if(root == NULL)
    {
        return NULL;
    }
    // since we're targetting the kth 'largest' element, we're starting from the right subtree
    struct node* ptr = kthLargest(root->right, i, k);
    if(ptr)
    {
        return ptr;
    }
    if(++(*i) == k)
    {
        return root;
    }
    return kthLargest(root->left, i, k);
}

// this is not required but just for the check
void inorderPrint(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    printf("%d ",root->data);
    inorderPrint(root->right);
}

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

int main()
{
    int n;
    printf("Enter the total number of nodes in the tree: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    // creating the BST(the zeroth element will always be at the root, but that's fine, I guess)
    struct node* root = NULL;
    for(int i=0; i<n; i++)
    {
        root = insert(root, arr[i]); 
    }
    printf("\nThe tree that has been created is: ");
    inorderPrint(root);
    int* newarr = (int*)malloc(n*sizeof(int));
    int i=0;
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
    struct node* kl = kthLargest(root, &i, k);
    //printf("\nThe kth smallest elements is: %d",newarr[k-1]);
    printf("\nThe kth largest element is: %d",kl->data);
    return 0;
}