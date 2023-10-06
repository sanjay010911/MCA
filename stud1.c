#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node tree;

tree *r=NULL;

void insert(int data)
{
	if(r==NULL)
	{
		r=(tree *)malloc(sizeof(tree));
		r->data=data;
		r->left=NULL;
		r->right=NULL;
	}
	else
	{
		tree *t,*x;
		t=r;
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
		else
		{
			x->right=(tree *)malloc(sizeof(tree));
			x->right->data=data;
			x->right->left=NULL;
			x->right->right=NULL;
		}	
	}
}

void inorder(tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}

void delete(int data)
{
	tree *t,*x=NULL;
	t=r;
	while(t!=NULL)
	{
		x=t;
		if(t->data==data)
			break;
		else if(data<t->data)
			t=t->left;
		else
			t=t->right;
	}
	if(t==NULL)
		printf("\nElement Not Found");
	
	
	if(t->left==NULL && t->right==NULL) //Node with no child
	{
		if(t==r)
			t=NULL;
		else if(x->left==t)
			x->left=NULL;
		else
			x->right=NULL;
	}
	
	if(t->left==NULL || t->right==NULL) //node with one child
	{
		if(t==r)
			r=(t->right!=NULL)? t->right:t->left;
		else if(x->right==t)
		{
			if(t->right!=NULL)
				x->right=t->right; //right right
			else
				x->right=t->left;//right left;
		}
		else
		{
			if(t->left!=NULL)
				x->left=t->left; //left right
			else
				x->left=t->right; //left left
		}
	}
	if(t->left!=NULL && t->right!=NULL) //node with two child
	{ //node with two children
	
				tree *s=t->right;
				while(s->left!=NULL)
					s=s->left;
				delete(s->data);
				x->data = t->data;
	}
}
int main()
{
	insert(50);
	insert(10);
	insert(100);
	insert(5);
	insert(20);
	insert(70);
	insert(150);
	 delete(150);
	 delete(20);
	inorder(r);
	return 0;
	
	
}
