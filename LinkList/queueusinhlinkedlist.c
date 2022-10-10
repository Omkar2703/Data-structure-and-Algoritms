#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct LL
{
	node *start;
}LL;

void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("\nList is empty...");
	}
	else
	{
		p=l->start;
		while(p!=NULL)
		{
			printf("\n%d",p->data);
			p=p->next;
		}
	}
}

void enqueue(LL *l,int x)
{
	node *newrec,*p;
	newrec=(node *)malloc(sizeof(node));
	newrec->data=x;
	newrec->next=NULL;
	if(l->start==NULL)
	{
		l->start=newrec;
	}
	else
	{
		p=l->start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newrec;
	}
}

void dequeue(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("\nDeletion not possible...");
	}
	else
	{
		p=l->start;
		l->start=l->start->next;
		free(p);
	}
}

int main()
{
	int ch,x;
	LL l;
	l.start=NULL;
	while(1)
	{
	printf("\nMenu:\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-EXIT\nEnter Choice=");
	scanf("%d",&ch);
	if(ch==4)
		break;
	switch(ch)
	{
		case 1:
			{
				printf("\nEnter element to be inserted=");
				scanf("%d",&x);
				enqueue(&l,x);
				display(&l);
			}
			break;
		case 2:
			{
				dequeue(&l);
				display(&l);
			}
			break;
		case 3:
			{
				display(&l);
			}
			break;
		default:
			{
				printf("\nInvalid Choice...");
			}
	}
	}
	return 0;
}

