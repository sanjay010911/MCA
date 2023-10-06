#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;
node *f=NULL,*r=NULL;

void enqueue(int data)
{
	if(r==NULL)
	{
		r=(node *)malloc(sizeof(node));
		r->data=data;
		r->next=NULL;
		f=r;
	}
	else
	{
		r->next=(node *)malloc(sizeof(node));
		r->next->data=data;
		r->next->next=NULL;
		r=r->next;
	}
}

void dequeue()
{
	if(f==NULL)
		printf("\nQueue Empty");
	else
	{
		printf("\nDequeued Element is %d",f->data);
		if(f==r)
			f=r=NULL;
		else
			f=f->next;
	}
}

void disp()
{
	node *t=f;
	if(f==NULL)
		printf("\nQueue Empty");
	else
	{
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
	}
}
int menu()
{
	int ch;
	printf("\nenter the choice 1:ENQUEUE 2:DEQUEUE 3:DISPLAY 4:EXIT\n");
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
			case 1:printf("\nenter the element to enqueue\n");
					scanf("%d",&ch);
					enqueue(ch);
					break;
			case 2:	dequeue();
					break;
			case 3:	disp();
					break;
		}
	}
	return 0;
}

