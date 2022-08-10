#include<stdio.h>
#define MAX 10
typedef struct
{
	int a[MAX];
	int top;
}stack;
void push(stack*s, int ele)
{
	if(s->top==MAX-1)
	{
		printf("\nStack is overflow.");
	}
	else
	{
	s->top++;
	s->a[s->top]=ele;
	}
}
int isempty(stack*s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pop(stack*s)
{
	int x;
	if (isempty(s))
	{
		return -1;
	}
	else
	{
		x=s->a[s->top];
		s->top--;
		return x;
	}
}
int stacktop(stack*s)
{
	if(isempty(s))
	{
		return -1;
	}
	else
	{
		return s->a[s->top];
	}
}
void display(stack*s)
{
	int i;
	if(isempty(s))
	{
		printf("\nStack is underflow.");
	}
	else
	{
		for(i=s->top;i>=0;i--)
		{
		printf("\n%d", s->a[i]);	
		}
	}
}
int main()
{
	stack s;
	s.top=-1;
	int ch, ele;
	do{
	printf("\n\nMenu\n\n1. Push.\n2. Pop.\n3. Stacktop.\n4. Display.\n5. Exit.");
	printf("\nEnter the choice:");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			{
				printf("\nEnter the element:");
				scanf("%d", &ele);
				push(&s, ele);
				break;
			}
			case 2:
				{
					ele = pop(&s);
					if(ele == -1)
					{
						printf("\nStack is underflow.");
					}
					else
					{
						printf("\n%d is poped.", ele);
						break;
					}
				}
				case 3:
					{
						ele = stacktop(&s);
						if (ele == -1)
						{
							printf("\nStack is underflow.");
						}
						else
						{
							printf("\n%d is poped.", ele);
							break;
						}
					}
					case 4:
						{
							display(&s);
							break;
						}
						case 5:
							{
								printf("\nExit satisfied.");
								break;
							}
							default:
								{
									printf("\nInvalid choice.");
								}
	}
	}while(ch!=5);
	return 0;
}
