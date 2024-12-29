#include<stdio.h>
#include<stdlib.h>

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

void levelOrder(struct node* root)
{
    //My assumption : a binary tree can have a maximum of 20 nodes - an array of pointers
    struct node** queue = (struct node**)malloc(20*sizeof(struct node*));
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while(front!=rear)
    {
        struct node* s = queue[front];
        front++;
        printf("%d ",s->data);
        if(s->left)
        {
            queue[rear++] = s->left;
        }
        if(s->right)
        {
            queue[rear++] = s->right;
        }
    }
}

int main()
{
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
    levelOrder(root);
    return 0;
}
