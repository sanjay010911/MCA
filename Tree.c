#include<stdio.h>
#include<malloc.h>
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

typedef struct Tree tree;
tree *root=NULL;

void insert(int data)
{
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else		
	{
		tree *t=root,*x;
		while(t!=NULL)
		{
			x=t;
			if(data<t->data)
				t=t->left;
			else
				t=t->right;
		}
		if(data<x->data)
		{
			x->left=(tree *)malloc(sizeof(tree));
			x->left->data=data;
			x->left->left=NULL;
			x->left->right=NULL;
		}
	 	else if(data>x->data)
		{
			x->right=(tree *)malloc(sizeof(tree));
			x->right->data=data;
			x->right->left=NULL;
			x->right->right=NULL;
		}
		
	}
}

void postorder(tree *r)
{
	if(r!=NULL)
	{

			postorder(r->left);
		postorder(r->right);
		printf("%d ",r->data);
	}
}

int main()
{
	insert(200);
	insert(10);
	insert(250);
	insert(5);
	insert(100);
	insert(220);
	insert(150);
	insert(240);
	insert(120);
	insert(170);
	insert(235);
	insert(245);
	postorder(root);
	return 0;
}
	
