/*Ascanding Queue with Normal Delete*/
#include<stdio.h>
#define MAX 10
typedef struct
{
    int a[MAX];
    int front, rear;
}queue;
void enqueue(queue*q, int ele)
{
    int i, j;
    if (q->rear==MAX-1)
    {
        printf("\n Queue is overflow.");
    }
    else
    {
        for(i=q->front; i<=q->rear; i++)
        {
            if (q->a[i]<ele)
                break;
        }
        for (j= q->rear; j>=i; j--)
        {
            q->a[j+1]=q->a[j];
        }
        q->a[i] = ele ;
        q->rear++;
    }
}
int isempty(queue*q)
{
    if(q->front+1==q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue(queue*q)
{
	int x;
	if(isempty(q))
	{
		return -1;
	}
	else
	{
		x=q->a[q->front];
		q->front++;
		return x;
	}
}
int queuefront(queue*q)
{
    if(isempty(q))
    {
        return -1;
    }
    else
    {
        return q->a[q->front];
    }
}
void display(queue*q)
{
    int i;
    if (isempty(q))
    {
        printf("\nQueue is underflow.");
    }
    else
    {
        for(i=q->front; i<=q->rear; i++)
        {
            printf("%d\t", q->a[i]);
            
        }
    }
}
int main()
{
    queue q;
    q.front=0;
    q.rear=-1;
    int ch, ele;
    while(1)
    {
        printf("\nMenu\n\n1. Enqueue.\n2. Dequeue\n3. Queue Front.\n4. Display\n5. Exit.\n");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        if(ch==5)
        {
            break;
        }
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the element:");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;
            }
            case 2:
            {
                ele=dequeue(&q);
                if(ele==-1)
                {
                    printf("\nQueue is underflow.");
                }
                else
                {
                    printf("\n%d is Dequeued.",ele);
                    break;
                }
            }
            case 3:
            {
                ele=queuefront(&q);
                if(ele==-1)
                {
                    printf("\nQueue is underflow.");
                }
                else
                {
                    printf("\n%d is Queue Front.",ele);
                    break;
                }
            }
            case 4:
            {
                display(&q);
                break;
            }
            case 5:
            {
                printf("\nExit satisfied.");
            }
            default:
            {
                printf("\nInvalid choice.");
            }
        }
    }
    return 0;
}
