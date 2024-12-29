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

void inorderPrint(struct node* root)
{
    //printf("\nEntered the inorder function...");
    if(root == NULL)
    {
        //printf("\nAbout to return...");
        return;
    }
    //printf("\nroot->data = %d",root->data);
    inorderPrint(root->left);
    //printf("\nSomething, just to signify that it reached this spot ");
    printf("%d ",root->data);
    inorderPrint(root->right);
}

struct node* insert(struct node* root, int key)
{
    /*if(root)
    {
        printf("\nroot->data = %d",root->data);
    }
    else
    {
        printf("\nNULL");
    }*/
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

struct node* truncate(struct node* root, int low, int high)
{
    if(root == NULL)
    {
        return root;
    }
    root->left = truncate(root->left, low, high);
    root->right = truncate(root->right, low, high);
    struct node* ptr = root;
    if(root->data > high)
    {
        root = root->left;
        free(ptr);
    }
    else if(root->data < low)
    {
        root = root->right;
        free(ptr);
    }
    return root;
}

int main()
{
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    // creating the binary tree
    struct node* root = NULL;
    for(int i=0; i<n; i++)
    {
        //printf("\narr[i] = %d",arr[i]);
        root = insert(root, arr[i]);
    }
    // printing the inorder tree created 
    printf("\nTree that was created(viewing in inorder) is: ");
    //printf("\nroot->data = %d",root->data);
    /*if(root == NULL)
    {
        printf("\nSuspicions confirmed.");
    }*/
    inorderPrint(root);
    // truncating the inorder tree
    int lower, upper;
    printf("\nEnter the lower and upper bounds respectively: ");
    scanf("%d %d",&lower, &upper);
    root = truncate(root, lower, upper);
    printf("\nThe binary tree after truncating is: ");
    inorderPrint(root);
    return 0;
}