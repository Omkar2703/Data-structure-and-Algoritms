#include<stdio.h>
#define MAX 10
typedef struct{
    int a[MAX];
    int front, rear, count;
}cqueue;
void enqueue(cqueue*q, int ele){
    if(q->count==MAX){
        printf("\nQueue is overflow.");
    }
    else{
        q->count++;
        q->rear=((q->rear)+1)%MAX;
        q->a[q->rear]=ele;
    }
}
int isempty(cqueue*q){
    if(q->count==0){
        return 1;
    }
    else{
        return 0;
    }
}
int dequeue(cqueue*q){
    int x;
    if(isempty(q)){
        return -1;
    }
    else{
        x=q->a[q->front];
        q->front=((q->front)+1)%MAX;
        q->count--;
        return x;
    }
}
int queuefront(cqueue*q){
    if(isempty(q)){
        return -1;
    }
    else{
        return q->a[q->front];
    }
}
void display(cqueue*q){
    int i;
    if(isempty(q)){
        printf("\nQueue is underflow.");
    }
    else{
        i=q->front;
        while(1){
            printf("%d\t", q->a[i]);
            if(i==q->rear){
                break;
            }
            i=(i+1)%MAX;
        }
    }
}
int main()
{
    cqueue q;
    int ch, ele;
    q.front=0;
    q.rear=-1;
    do{
        printf("\nMenu.\n1. Enqueue.\n2. Dequeue.\n3. Queue Front.\n4. Display.\n5. Exit.\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("\nEnter the element to be insert:");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;
            }
            case 2:{
                ele=dequeue(&q);
                if(ele==-1){
                    printf("\nQueue is underflow.");
                }
                else{
                    printf("%d is dequeued.", ele);
                    break;
                }
            }
            case 3:{
                ele=queuefront(&q);
                if(ele==-1){
                    printf("\nQueue is underflow.");
                }
                else{
                    printf("%d is at front.", ele);
                    break;
                }
            }
            case 4:{
                display(&q);
                break;
            }
            case 5:{
                printf("\nExit satisfied.");
                break;
            }
            default:{
                printf("\nInvalid input.");
                break;
            }
        }
    }while(ch==5);
    return 0;
    
}
