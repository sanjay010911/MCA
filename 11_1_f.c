#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node
{
	struct node *prev;
	char data[30];
	struct node *next;
};

typedef struct node node;
node *head=NULL;

void insert(char data[30])
{
	if(head==NULL)
	{
		head=(node *)malloc(sizeof(node));
		strcpy(head->data,data);
		head->next=head;
		head->prev=head;
	}
	else
	{
		node *t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		strcpy(t->next->data,data);
		t->next->prev=t;
		t->next->next=head;
		head->prev=t->next;	
	}
}

void delete(char data[30])
{
	if(head==NULL)
		printf("\nCircular DL List Empty");
	else if(strcmp(head->data,data)==0 && (head->next==head))
		head=NULL;
	else if(strcmp(head->data,data)==0 && (head->next!=head))
	{
		node *t=head,*temp;
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next;
	}
	else
	{
		node *t=head;
		while(strcmp(t->data,data)!=0 && (t->next!=head))
		{
			t=t->next;
		}
		if(strcmp(t->data,data)!=0 && (t->next==head))
			printf("\nElement Not Found");
		else 
		{
			t->prev->next=t->next;
			t->next->prev=t->prev;
		}
	}
}

void display()
{
	node *t=head;
	if(head==NULL)
		printf("\nCircular DL List Empty");
	else
	{
		printf("\n");
		printf("%s ",t->data);
		t=t->next;
		while(t!=head)
		{
			printf("%s ",t->data);
			t=t->next;
		}
	}
	
}

int menu()
{
	int ch,pos;
	printf("\n\nenter a choice \n1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT");
	scanf("%d",&ch);
	return ch;
}


int main()
{
	int ch;
	char a[30];
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("\nenter the element\n");
					scanf("%s",&a);
					insert(a);
					break;
			case 2:printf("\nenter the element\n");
					scanf("%s",&a);
					delete(a);
					break;
			case 3:display();
					break;
		}
	}
	return 0;
}
