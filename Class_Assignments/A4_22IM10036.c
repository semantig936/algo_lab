#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* allocate(int key)
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
		root = allocate(key);
		return root;
	}
	if(key<root->data)
	{
		root->left = createBST(root->left, key);
	}
	else
	{
		root->right = createBST(root->right, key);
	}
	return root;
}

void preOrder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void postOrder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}

struct node* findLeftptr(struct node* root)
{
	if(root == NULL)
	{
		return root;
	}
	struct node* ptr = root;
	while(ptr->left)
	{
		ptr = ptr->left;
	}
	return ptr;
}

void printmin(struct node* root, int* i, int k)
{
	//printf("\nEntered min_k, k=%d",*k);
	if(root == NULL)
	{
		return;
	}
	if(k == 0)
	{
		return;
	}
	printmin(root->left, i, k);
	if(*i == k)
	{
		printf("%d ",root->data);
	}
	(*i)++;
	printmin(root->right, i, k);
}

void min_k(struct node* root, int k)
{
	int i = 1;
	printmin(root, &i, k);
}

struct node* search(struct node* root, int l)
{
	if(root == NULL)
	{
		return root;
	}
	if(root->data == l)
	{
		return root;
	}
	if(root->data < l)
	{
		return search(root->left, l);
	}
	else
	{
		return search(root->right, l);
	}
}

struct node* findParent(struct node* root, int l)
{
	if(root == NULL)
	{
		return root;
	}
	struct node *ptr1, *ptr2;
	if(root->right)
	{
		if(root->right->data == l)
		{
			return root;
			ptr1 = findParent(root->right, l);
		}
	}
	if(root->left)
	{
		if(root->left->data == l)
		{
			return root;
			ptr2 = findParent(root->left, l);
		}
	}
	if(ptr1==NULL && ptr2==NULL)
	{
		return NULL;
	}
}

struct node* find_and_change(struct node* root, int l)
{
	struct node* ptr = search(root, l);
	printf("\nHello");
	printf("\n%d ",ptr->data);
	if(ptr == NULL)
	{
		return ptr;
	}
	struct node* parent = findParent(ptr, l);
	struct node* temp = ptr;
	printf("%p %p",parent, ptr);
	if(root->data > ptr->data)
	{
		ptr->right = root;
		root->left = ptr->left;
	}
	else
	{
		ptr->left = root;
		root->right = ptr->right;

	}
	/*if(parent->right == ptr)
	{
		ptr->left = parent;
		parent->right = temp->left;
	}
	else
	{
		ptr->right = parent;
		parent->left = ptr->right;
	}*/
	return ptr;
} 


int main()
{
	int n;
	printf("Enter the number of nodes in the BST: ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter the values in the nodes in inorder: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	struct node* root = NULL;
	for(int i=0; i<n; i++)
	{
		root = createBST(root, arr[i]);
	}
	printf("\nPreorder traversal is: ");
	preOrder(root);
	printf("\nInorder traversal is: ");
	inOrder(root);
	printf("\nPostorder traversal is: ");
	postOrder(root);
	int k;
	printf("\nEnter k: ");
	scanf("%d",&k);
	if(k>n)
	{
		printf("\nThe value of k exceeds the number of roots. ");                          
	}
	else
	{
		printf("\nThe %d smallest no. is:",k);
	    min_k(root, k);
	}
	//printf("\nThe %d smallest no. is:",k);
	//min_k(root, k);
	//printf("\n");
	int l;
	printf("\nEnter l: ");
	scanf("%d",&l);
	struct node* new_root = find_and_change(root, l);
	printf("value at the root = %d ",new_root->data);
	printf("\nPreorder traversal of the new binary tree: ");
	preOrder(new_root);
	printf("\nInorder traversal of the new binary tree: ");
	inOrder(new_root);
	printf("\nPostorder traversal of the new binary tree: ");
	postOrder(new_root);
	return 0;
}