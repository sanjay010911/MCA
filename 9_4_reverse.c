#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
Node *head=NULL;

void insert(int data)
{
	Node *t;
	if(head==NULL)
	{
		t=(Node *)malloc(sizeof(Node));
		head=t;
		head->next=NULL;
		head->data=data;
	}
	else
	{
		//t=head;
		t=(Node *)malloc(sizeof(Node));
		t->next=head;
		t->data=data;
		head=t;	
	}
}

void disp()
{
	Node *t=head;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
}



int main()
{
	int n,i=1,data;
	printf("\nenter n\n");
	scanf("%d",&n);
	
	while(i<=n)
	{
		printf("\nenter the data\n");
		scanf("%d",&data);
		insert(data);
		i++;
	}
	
	disp();
	return 0;
}
