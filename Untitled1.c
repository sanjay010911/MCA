#include <stdio.h>
struct priority
{
	int data;
	int pty;
}

struct priority p[10];
int f=-1,r=-1,n=5;

void enqueue(int data,int py)
{
	if((f==-1)&&(r==-1))
	{
		f++;
		r++;
		p[r].data=data;
		p[r].pty=py;	
	}
	else if(r==n-1)
		printf("\nPriority Queue Full\n");
	else
		{
			r++;
			p[r].data=data;
			p[r].pty=py;
		}
}
void dequeue()
{
	
}

void peek()
{
	int i=f;
	while(i<=r)
	{
		printf("%d : %d  ,",p[i].data,p[i].pty);
		i++;
	}
}

int main()
{
	
}
