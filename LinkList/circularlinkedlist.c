#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct LL
{
	node *last;
}LL;

void insertbegin(LL *l,int x)
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=x;
	newrec->next=NULL;
	if(l->last==NULL)
	{
		newrec->next=newrec;
		l->last=newrec;
	}
	else
	{
		newrec->next=l->last->next;
		l->last->next=newrec;
	}
}

void insertend(LL *l,int x)
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=x;
	newrec->next=NULL;
	if(l->last==NULL)
	{
		newrec->next=newrec;
		l->last=newrec;
	}
	else
	{
		newrec->next=l->last->next;
		l->last->next=newrec;
		l->last=newrec;
	}
}

void deletebegin(LL *l)
{
	node *p;
	if(l->last==NULL)
	{
		printf("\nDeletion not possible...");
	}
	else
	{
		p=l->last->next;
		if(p->next==p)//only one node
		{
			l->last=NULL;
		}
		else
		{
			l->last->next=p->next;
		}
		free(p);
	}
}

void deleteend(LL *l)
{
	node *p,*q;
	if(l->last==NULL)
	{
		printf("\nDeletion not possible...");
	}
	else
	{
		p=l->last;
		if(p->next==p)//only one node
		{
			l->last=NULL;
		}
		else
		{
			q=l->last->next;
			while(q->next!=l->last)
			{
				q=q->next;
			}
			q->next=p->next;
			l->last=q;
		}
		free(p);
	}
}

void display(LL *l)
{
	node *p;
	if(l->last==NULL)
	{
		printf("\nList is empty...");
	}
	else
	{
		p=l->last->next;
		do
		{
			printf("\n%d",p->data);
			p=p->next;
		}
		while(p!=l->last->next);
	}
}

int main()
{
	int ch,x;
	LL l;
	l.last=NULL;
	while(1)
	{
		printf("\nMenu:\n1-Insert at beginning\n2-Insert at end\n3-Delete at beginning\n4-Delete at end\n5-Display\n6-EXIT\nEnter Choice=");
		scanf("%d",&ch);
		if(ch==6)
			break;
		switch(ch)
		{
			case 1:
				{
					printf("\nEnter element to be inserted=");
					scanf("%d",&x);
					insertbegin(&l,x);
					display(&l);
				}
				break;
			case 2:
				{
					printf("\nEnter element to be inserted=");
					scanf("%d",&x);
					insertend(&l,x);
					display(&l);
				}
				break;
			case 3:
				{
					deletebegin(&l);
					display(&l);
				}
				break;
			case 4:
				{
					deleteend(&l);
					display(&l);
				}
				break;
			case 5:
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
















