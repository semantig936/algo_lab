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

void printZigZag(struct node* root)
{
    struct node** queue = (struct node**)malloc(20*sizeof(struct node*));
    int* level = (int*)malloc(20*sizeof(int));
    int front = 0;
    int rear = 0;
    queue[rear] = root;
    level[rear] = 0;
    rear++;
    while(front!=rear)
    {
        struct node* s = queue[front];
        printf("%d ",s->data);
        if(level[front]%2==0)
        {
            if(s->left)
            {
                queue[rear] = s->left;
                level[rear] = level[front] + 1;
                rear++;
            }
            if(s->right)
            {
                queue[rear] = s->right;
                level[rear] = level[front] + 1;
                rear++;
            }
        }
        else
        {
            if(s->right)
            {
                queue[rear] = s->right;
                level[rear] = level[front] + 1;
                rear++;
            }
            if(s->left)
            {
                queue[rear] = s->left;
                level[rear] = level[front] + 1;
                rear++;
            }
        }
        front++;
    }
}

int main()
{
    struct node* root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);
    printZigZag(root);
}