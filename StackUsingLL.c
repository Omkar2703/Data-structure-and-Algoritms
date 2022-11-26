#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}node;
typedef struct LL
{
	node*start;
}LL;
void Push(LL*l, int ele)
{
	node*newrec, *p;
	newrec->data=ele;
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
void display(LL*l)
{
	node*p;
	if(l->start==NULL)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		p=l-start;
		while(p->next!=NULL)
		{
			printf("%d\n",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
int Pop(LL*l)
{
	node*p;
	if(l->start==NULL)
	{
		return -1;
	}
	else
	{
		p=l->start;
		l->start=p->next;
		return p->data;
	}
	
}
int stacktop(LL*l)
{
	if(l->start==NULL)
	{
		return -1;
	}
	else
	{
		return l->start->data;
	}
}
int main()
{
	LL l;
	l.start=NULL;
	int ch, ele;
	while(1)
	{
		printf("\nMenu\n1. Push\n2. Pop\n3. StackTop\n4. Display\n5. Exit\n");
		printf("\nEnter the choice:");
		scanf("%d", &ch);
		if(ch==5)
		{
			printf("\nExit Satisfied");
			break;
		}
		switch(ch)
		{
			case 1:
				{
					printf("\Enter the number to be inserted:");
					scanf("%d", &ele);
					Push(&l, ele);
				}
				break;
				case 2:
				{
					ele=Pop(&l);
					if(ele==-1)
					{
						printf("\nStack is empty");
					}
					else
					{
						printf("%d is Poped", ele);
					}
				}
				break;
				case 3:
				{
					ele=stacktop(&l);
					if(ele==-1)
					{
						printf("\nStack is empty");
					}
					else
					{
						printf("%d is at top", ele);
					}
				}
				break;
				case 4:
				{
				   display(&l);
				}
				break;
				default:
				{
				   printf("Invalid Choice.");
				}
		}
	}
	return 0;
}
