/*Circular Queue*/
#include<stdio.h>
#define MAX 20
typedef struct
{
    int a[MAX];
    int front, rear;
    int count;
}cqueue;
void enqueue(cqueue*q, int ele)
{
    if(q->count==MAX)
    {
        printf("\nQueue is overflow.");
        return ;
    }
    q->count++;
    q->rear=(q->rear+1)%MAX;
    q->a[q->rear]=ele;
}
int isempty(cqueue*q)
{
    if(q->count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue(cqueue*q)
{
    int x;
    if(isempty(q))
    {
        return -1;
    }
    else
    {
        x=q->a[q->front];
        q->front=(q->front+1)%MAX;
        q->count--;
        return x;
    }
}
int queuefront(cqueue*q)
{
  int x;
    if(isempty(q))
    {
        return -1;
    }
    else
    {
        return q->a[q->front];
    }  
}
void display(cqueue*q)
{
    int i;
    if(isempty(q))
    {
        printf("\nQueue  is underflow.");
    }
    else
    {
        i=q->front;
        while(1)
        {
            printf("%d\t", q->a[i]);
            if(i==q->rear)
            {
                break;
            }
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}
int main()
{
    cqueue q;
    q.front=0;
    q.rear=MAX-1;
    q.count=0;
    int ch, ele;
    while(1)
    {
        printf("\nMENU\n\n1. ENQUEUE\n\n2. DEQUEUE\n\n3. QUEUEFRONT\n\n4. DISPLAY\n\n5. EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        if(ch==5)
        {
            printf("\nExit satisfied.");
            break;
        }
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the element to be Enqueue:");
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
                    printf("%d is dequeued.", ele);
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
                    printf("%d is at front.", ele);
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
                printf("\nInvaild choice.");
            }
        }
    }
    return 0;
}
