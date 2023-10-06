#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
Node *head=NULL;


void insbegin(int data)
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
		t=(Node *)malloc(sizeof(Node));
		t->next=head;
		head=t;
		head->data=data;
	}
}
void insend(int data)
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

void inspos(int data,int val)
{
	int i=1;
	Node *t,*prev;
	t=head;
	if(head==NULL)
	{
		t=(Node *)malloc(sizeof(Node));
		head=t;
		head->next=NULL;
		head->data=data;
	}
	else
	{
		while((t->data!=val)&&(t->next!=NULL))
		{
			t=t->next;
		}
		if((t->next==NULL)&&(t->data!=val))
			printf("\nElement Not Found");
		else if((t->data==val)&&(t->next!=NULL))
			
				
		
	}
}
void disp()
{
	Node *t=head;
	if(head==NULL)
		printf("\nLinked List Empty!!\n");
	else
	{
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
}
int menu()
{
	int ch,pos;
	printf("\nenter a choice \n1:INSERT AT BEGINNING\n2:INSERT AT END\n3:INSERT AFTER AN ELEMENT\n4:DISPLAY\n5:EXIT");
	scanf("%d",&ch);
	return ch;
}


int main()
{
	int ch,pos;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("\nenter the element\n");
					scanf("%d",&ch);
					insbegin(ch);
					break;
			case 2:printf("\nenter the element\n");
					scanf("%d",&ch);
					insend(ch);
					break;
			case 3:printf("\nenter the element\n");
					scanf("%d",&ch);
					printf("\nenter the element to search\n");
					scanf("%d",&pos);
					inspos(ch,pos);
					break;
			case 4:disp();
					break;
		}
	}
	return 0;
}
