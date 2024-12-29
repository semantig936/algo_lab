#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int key;
    struct tree* left;
    struct tree* right;
};

struct tree* allocate(int k)
{
    struct tree* t = (struct tree*)malloc(sizeof(struct tree));
    t->key = k;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void createBST(struct tree **root, int num, int *successor)
{
    if(*root == NULL)
    {
        *root =  allocate(num);
    }
    if(num < (*root)->key)
    {
        //printf("successor = %d, num = %d, value at root = %d",*successor, num, (*root)->key);
        *successor = (*root)->key;
        createBST(&((*root)->left), num, successor);
    }
    if(num > (*root)->key)
    {
        createBST(&((*root)->right), num, successor);
    }
}

void replace(int* arr, int n)
{
    printf("\nEntered the replace function...");
    // Initially the root will be a NULL pointer
    struct tree* root = NULL;
    for(int i=n-1; i>=0; i--)
    {
        int successor = -1; // successor is initialised at every loop because we'll keep traversing that array again and again and it'll get updated
        printf("\nsuccessor = %d, arr[i] = %d",successor, arr[i]);
        createBST(&root, arr[i], &successor); 
        arr[i] = successor; 
        printf("\nCurrent situation of the array: ");
        for(int j=0; j<n; j++)
        {
            printf("%d ",arr[j]);
        }
        printf("\n");
        // the elements at the back keep getting saved to the BST, so it doesn't really matter that the elements are getting changed 
        printf("\nThe final array is: ");
        for(int i=0; i<n; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n"); 
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in your array: ");
    scanf("%d",&n);
    // allocating memory to the array - and then taking input
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    replace(arr, n);
    return 0;
}