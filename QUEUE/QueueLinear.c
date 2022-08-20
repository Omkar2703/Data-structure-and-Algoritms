#include<stdio.h>
#define MAX 15
typedef struct 
{
    /* data */
    int a[MAX];
    int front, rear;
}queue;
void enqueue(queue*q, int ele)
{
    if(q->rear==MAX)
    {
        printf("\nQueue is overflow.");
        return ;
    }
    q->rear++;
    q->a[q->rear]=ele;
}
int isempty(queue*q)
{
    if(q->rear+1==q->front)
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
    if(isempty(q))
    {
        printf("\nQueue is underflow.");
    }
    else
    {
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\t", q->a[i]);
        }
        printf("\n");
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
        printf("\nMenu.\n1. Enqueue.\n2. Dequeue.\n3. Queue Front.\n4. Display.\n5. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        if(ch==5)
        {
            printf("\nExir satisfied.");
            break;
        }
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter th element to be enqueued:");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;
            }
            case 2:
            {
                ele=dequeue(&q);
                if(ele==-1)
                {
                    printf("\nQueue is undeflow.");
                }
                else
                {
                    printf("\n%d is dequeued.", ele);
                    break;
                }
            }
            case 3:
            {
                ele=queuefront(&q);
                if(ele==-1)
                {
                    printf("\nQueue is undeflow.");
                }
                else
                {
                    printf("\n%d is at front.", ele);
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