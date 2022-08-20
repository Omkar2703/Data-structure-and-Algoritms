#include<stdio.h>
#define MAX 10
typedef struct
{
    int a[MAX];
    int front, rear;
}queue;
void enqueuerear(queue*q, int ele)
{
    if(q->rear==MAX-1)
    {
        printf("\nQueue is overflow.");
        return;
    }
    q->rear++;
    q->a[q->rear]=ele;
}
void enqueuefront(queue*q, int ele)
{
    if(q->front==-1)
    {
        printf("\nQueue is overflow.");
        return;
    }
    q->a[q->front]=ele;
    q->front--;
}
int isempty(queue*q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeuerear(queue*q)
{
    int x;
    if(isempty(q))
    {
        return -1;
    }
    x=q->a[q->rear];
    q->rear--;
    return x;
}
int dequeuefront(queue*q)
{
    int x;
    if(isempty(q))
    {
        return -1;
    }
    q->front++;
    x=q->a[q->front];
    return x;
}
void display(queue*q)
{
    int i;
    if(isempty(q))
    {
        printf("\nQueue is underflow.");
    }
    else
    {
        for (i=q->front+1;i<=q->rear;i++)
        {
            printf("%d\t", q->a[i]);   
        }
        printf("\n");
    }
}
int main()
{
    queue q;
    q.front=MAX/2;
    q.rear=MAX/2;
    int ch, ele;
    while(1)
    {
        printf("\nMenu.\n1. EnQueue rear.\n2. EnQueue front.\n3. DeQueue rear.\n4. DeQueue front.\n5. Display.\n6. Exit.\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        if(ch==6)
        {
            printf("\nExit satisfied.");
            break;
        }
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the element:");
                scanf("%d", &ele);
                enqueuerear(&q, ele);
                break;
            }
            case 2:
            {
                printf("\nEnter the element:");
                scanf("%d", &ele);
                enqueuefront(&q, ele);
                break;
            }
            case 3:
            {
                ele=dequeuerear(&q);
                if(ele==-1)
                {
                    printf("\nQueue is underflow.");
                }
                else
                {
                    printf("\n%d is dequeued.", ele);
                    break;
                }
            }
            case 4:
            {
                ele=dequeuefront(&q);
                if(ele==-1)
                {
                    printf("\nQueue is underflow.");
                }
                else
                {
                    printf("\n%d is dequeued.", ele);
                    break;
                }
            }
            case 5:
            {
                display(&q);
                break;
            }
            case 6:
            {
                break;
            }
            default:
            {
                printf("\nInvalid choice.");
            }
        }
    }
    return 0;
}