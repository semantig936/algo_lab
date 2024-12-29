#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void checkPreorder(struct node* root, int s, int sum, bool* flag)
{
    if(root==NULL)
    {
        return;
    }
    sum = sum + root->data;
    if(sum == s)
    {
        *flag = true;
    }
    checkPreorder(root->left, s, sum, flag);
    checkPreorder(root->right, s, sum, flag);
}

int main()
{
    int s; //target sum
    //creating a tree 
    struct node* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);
    printf("Enter the target sum: ");
    scanf("%d",&s);
    bool flag = false;
    checkPreorder(root, s, 0, &flag);
    if(flag)
    {
        printf("Possible");
    }
    else
    {
        printf("Not possible");
    }
    return 0;
}