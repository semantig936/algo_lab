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

void addition(int* arr, int key)
{
    
}

void traverse(struct node* root, int* arr, int i)
{
    //printf("\nEntered the elements function...");
    if(root == NULL)
    {
        return;
    }
    elements(root->left, arr, i);
    printf("\nroot->data = %d ",root->data); 
    arr[i] = root->data;
    printf("\narr[%d] = %d",i,arr[i]);
    i++;
    elements(root->right, arr, i);
}

void merge(int* arr, int* aux, int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = high;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        aux[k++] = arr[i++];
    }
    while(j<=high)
    {
        aux[k++] = arr[j++];
    }
    for(int x=low; x<=high; x++)
    {
        arr[x] = aux[x];
    }
}

//We'll check it out y going through the errors
void mergesort(int* arr, int* aux, int low, int high)
{
    if(high<=low)
    {
        return;
    }
    int mid = low + (high-low)/2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid+1, high);
    merge(arr, aux, low, mid, high);
}

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

// cool technique - retaining the structure, i is for the index of the array
void create(struct node* root, int* arr, int i)
{
    if(root == NULL)
    {
        return;
    }
    create(root->left, arr, i);
    root->data = arr[i++];
    create(root->right, arr, i);
}

int main() 
{
    // this time, I'll create my own BST as input
    int n = 7; // n is the number of nodes in the BST 
    struct node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->left = createNode(10);
    root->left->right = createNode(2);
    root->right->left = createNode(4);
    root->right->right = createNode(6);
    printf("\nInitial BST: ");
    inorderPrint(root);
    int* arr = (int*)malloc(n*sizeof(int));
    elements(root, arr, 0);
    printf("\nThe initial array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    int* aux = (int*)malloc(n*sizeof(int));
    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    mergesort(arr, aux, 0, n-1);
    create(root, arr, 0); // creating the new BST
    printf("\nThe new BST(in inorder) is: ");
    inorderPrint(root);
}