#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct name
{
	char n[30];
	struct name *next;
};
typedef struct name name;
name *head=NULL;
int count=0;
void insert(char d[30])
{
	if(head==NULL)
	{
		head=(name *)malloc(sizeof(name));
		strcpy(head->n,d);
		head->next=NULL;
		count++;
	}
	else
	{
		name *t;
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(name *)malloc(sizeof(name));
		strcpy(t->next->n,d);
		t->next->next=NULL;
		count++;
	}
}

void delete(char d[30])
{
	name *t,*prev;
	t=head;
	if(head==NULL)
		printf("\nLinked List Empty\n");
	else if(strcmp(head->n,d)==0)
	{
		head=head->next;
		count--;
	}
	else 
	{
		while((strcmp(t->n,d)!=0)&&(t->next!=NULL))
		{
			prev=t;
			t=t->next;
		}
		if((strcmp(t->n,d)!=0)&&(t->next==NULL))
			printf("\nElement Not Found\n");
		else
		{
			prev->next=t->next;
			count--;
		}
	}
}

void display()
{
	name *t=head;
	if(head==NULL)
		printf("\nLinked List Empty\n");
	else
	{
		while(t!=NULL)
		{
			printf("%s ",t->n);
			t=t->next;
		}
	}
}

void rev(name *t)
{
	if(t->next!=NULL)
		rev(t->next);
	printf("%s ",t->n);
}

void sort()
{
	name *t,*j,*i;
	//int i,j;
	for(t=head;t->next!=NULL;t=t->next)
		for(j=t->next;j!=NULL;j=j->next)
		if(strcmp(t->n,j->n)>0)
		{
			strcpy(i->n,t->n);
			strcpy(t->n,j->n);
			strcpy(j->n,i->n);
		}
}


int menu()
{
	int ch,pos;
	char a[30];
	printf("\nenter a choice \n1:INSERT\n2:DELETE\n3:SORT\n4:DISPLAY\n5:COUNT\n6:REVERSE\n7:EXIT\n");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch,pos;
	char a[30];
	for(ch=menu();ch!=7;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("\nenter the name\n");
					scanf("%s",a);
					insert(a);
					break;
			case 2:printf("\nenter the name to delete\n");
					scanf("%s",a);
					delete(a);
					break;
			case 3:sort();
					break;
			case 4:display();
					break;
			case 5:printf("\n%d",count);
					break;
			case 6:rev(head);
					break;
		}
	}
	return 0;
}
