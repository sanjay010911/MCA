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
}

void delbegin()
{
	Node *t=head;
	if(head==NULL)
		printf("\nLinked List Empty!!\n");
	else{
		head=head->next;
		t->next=NULL;
	}
}

void delend()
{
	Node *t=head;
	if(head==NULL)
		printf("\nLinked List Empty!!\n");
	else if(head->next==NULL)
		head=NULL;
	else
	{	
		while(t->next->next!=NULL)
		{
			t=t->next;
		}
		t->next=NULL;
	}
}

void delpos(int val)
{
	int i=1;
	Node *t=head,*prev;
	if(head==NULL)
		printf("\nLinked List Empty!!\n");
	else
	{
			
		while((t->next->data!=val)&&(t->next!=NULL))
		{
			prev=t;
			t=t->next;
			i++;
		}
		
		t->next=t->next->next;
	}
}
int menu()
{
	int ch,pos;
	printf("\nenter a choice \n1:INSERT\n2:DELETE AT BEGINNING\n3:DELETE AT END\n4:DELETE AN ELEMENT\n5:DISPLAY\n6:EXIT");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	int ch,pos;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("\nenter the element\n");
					scanf("%d",&ch);
					insert(ch);
					break;
			case 2:	delbegin();
					break;
			case 3:delend();
					break;
			case 4:printf("\nenter the pos\n");
					scanf("%d",&ch);
					delpos(ch);
					break;
			case 5:disp();
					break;
		}
	}
	return 0;
}


