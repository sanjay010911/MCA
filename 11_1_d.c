#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node node;
node *f=NULL,*r=NULL;

void insert(int data)
{
	if((f==NULL)&&(r==NULL))
	{
		r=(node *)malloc(sizeof(node));
		r->data=data;
		f=r;
		r->next=r;	
	}
	else{
		node *t=f;
		while(t->next!=f)
		{
			t=t->next;
		}
		t->next=(node *)malloc(sizeof(node));
		t->next->data=data;
		t->next->next=f;
		r=t->next;
	}
}

void disp()
{
	node *t=f;
	if((f==NULL)&&(r==NULL))
		printf("\nCircular Linked Queue Empty");
	else
	{
		while(t->next!=f)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("%d ",t->data);
	}
}	

void delete()
{
	if((f==NULL)&&(r==NULL))
		printf("\nCircular Linked Queue Empty");
	else
	{
		printf("Dequeued Element is : %d",f->data);
		if(f==r)
			f=r=NULL;
		else
		{
			f=f->next;
			r->next=f;
		}
	}
}

int menu()
{
	int ch;
	printf("\nenter the choice 1:ENQUEUE 2:DEQUEUE 3:DISPLAY 4:EXIT");
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
			case 2:delete();
					break;
			case 3:	disp();
					break;
		}
	}
	return 0;
}
