#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

int total_nodes(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return total_nodes(root->left) + total_nodes(root->right) + 1;
    }
}

bool isCompleteUtil(struct node* root, int n, int i)
{
    if(root == NULL)
    {
        return true;
    }
    if(i>=n)
    {
        return false;
    }
    else
    {
        return isCompleteUtil(root->left, n, 2*i+1) && isCompleteUtil(root->right, n, 2*i+2);
    }
}

bool isHeapUtil(struct node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    if(root->right==NULL)
    {
        if(root->data >= root->left->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(root->data >= root->left->data && root->data >= root->right->data)
        {
            return isHeapUtil(root->left) && isHeapUtil(root->right);
        }
        else
        {
            return false;
        }
    }
}

bool HeapCheck(struct node* root)
{
    int n = total_nodes(root);
    return isHeapUtil(root) && isCompleteUtil(root, n, 0);
}

int main()
{
    struct node* root = NULL;
    root = createNode(10);
    root->left = createNode(9);
    root->right = createNode(8);
    root->left->left = createNode(7);
    root->left->right = createNode(6);
    root->right->left = createNode(5);
    root->right->right = createNode(4);
    root->left->left->left = createNode(3);
    root->left->left->right = createNode(2);
    root->left->right->left = createNode(1);
    //calling the main function to check out whether it is actually a heap
    if(HeapCheck(root))
    {
        printf("Given binary tree is a heap.");
    }
    else
    {
        printf("Binary tree is not a heap.");
    }
    return 0;
}