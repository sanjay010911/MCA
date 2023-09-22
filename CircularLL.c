#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;
node *head=NULL;

void insert(int data)
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		head->data=data;
		head->next=head;
	}
	else
	{
		node *t;
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=data;
		t->next->next=head;
	}
 } 
 
 void delete(int data)
 {
 	if((head->data==data)&&(head->next==head))
 	{
 		head=NULL;
	 }
	 else if((head->data==data)&&(head->next!=head))
	 {
	 	node *t=head;
	 	while(t->next!=head)
	 	{
	 		t=t->next;
		}
		t->next=head->next;
		head=head->next; 
	 }
	 else if(head==NULL)
	 	printf("\nCircular LL empty");
 	else
	{
		node *t;
		t=head;
		node *prev;
		while((t->data!=data)&&(t->next!=head))
		{
			prev=t;
			t=t->next;
		}
		if(t->next==head)
		
		prev->next=t->next;
	}
 }
 
 void disp()
 {
 	if(head==NULL)
 		printf("\nCircular LL empty");
 	else
 	{
 		node *t=head;
 		while(t->next!=head)
 		{
 			printf("%d ",t->data);
 			t=t->next;
	 	}
	 	printf("%d",t->data);
	}
}
int menu()
{
	int ch;
	printf("\nenter the choice 1:INSERT 2:DELETE 3:DISPLAY 4:EXIT");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("\nenter the element\n");
					scanf("%d",&ch);
					insert(ch);
					break;
			case 2:printf("\nenter the element to delete\n");
					scanf("%d",&ch);
					delete(ch);
					break;
			case 3:	disp();
					break;
		}
	}
	return 0;
}
