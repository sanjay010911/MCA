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
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(Node *)malloc(sizeof(Node));
		t->next->data=data;
		t->next->next=NULL;
	}
}

void rev(Node *t)
{
	if(t->next!=NULL)
		rev(t->next);
	printf("%d",t->data);
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
	
	rev(head);
	return 0;
}
