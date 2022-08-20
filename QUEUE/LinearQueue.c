/*WAP for making linear queue*/
#include<stdio.h>
#define MAX 5
typedef struct 
{
    int a[MAX];
    int front, rear;
}queue;
/*Function to insert element.*/
void enqueue(queue*q, int ele)
{
    if(q->rear==MAX)
    {
        printf("\nQueue is overflow.");
    }
    else
    {
        q->rear++;
        q->a[q->rear]=ele;
    }
}
/*Function to check whether the queue is empty or not.*/
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
/*Function to delete element.*/
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
        q->front--;
        return x;
    }
}
/*Function to show element present at front end.*/
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
/*Function to display entire queue.*/
void display(queue*q)
{
    int i;
    if(isempty(q))
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
/*Now all functions need to be call in main*/
int main()
{
    /*Call queue here*/
    queue q;
    /*Initialize front and rear end*/
    q.front=0;
    q.rear=-1;
    int ch, ele;
    /*'ch' is choice in menu.*/
    /*Perform switch case in while loop by by true condition.*/
    do
    {
        printf("\nMenu\n1. Enqueue.\n2. Dequeue\n3. Queue front\n4. Display.\n5.Exit.");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the elements:");
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
                    printf("%d is dequeue.", ele);
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