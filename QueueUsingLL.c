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
void EnQueue(LL*l, int ele)
{
	node*newrec, *p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=NULL;
	if(l->start==NULL){
	    l->start=newrec;
	}
	else{
	    p=l->start;
	    while(p->next!=NULL){
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
		printf("\nQueue is Empty\n");
	}
	else
	{
		p=l->start;
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
int DeQueue(LL*l)
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
int QueueFront(LL*l)
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
		printf("\nMenu\n1. EnQueue\n2. DeQueue\n3. QueueFront\n4. Display\n5. Exit\n");
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
					printf("\nEnter the number to be inserted:");
					scanf("%d", &ele);
					EnQueue(&l, ele);
				}
				break;
				case 2:
				{
					ele=DeQueue(&l);
					if(ele==-1)
					{
						printf("\nQueue is empty");
					}
					else
					{
						printf("%d is DeQueue", ele);
					}
				}
				break;
				case 3:
				{
					ele=QueueFront(&l);
					if(ele==-1)
					{
						printf("\nQueue is empty");
					}
					else
					{
						printf("%d is at Front", ele);
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
