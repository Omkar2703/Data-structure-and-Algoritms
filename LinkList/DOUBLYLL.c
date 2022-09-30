/*free(p) is used to De-Alocate the Memory Dynamically*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next, *prev;
}node;
typedef struct LL
{
    node*start;
}LL;
void InsertBegin(LL*l, int ele)
{   /*Put elements at Beginning.*/
    node*newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=l->start;
    l->start=newrec;
}
void InsertEnd(LL*l, int ele)
{
    /*Put elements at End.*/
    node*newrec, *p;
    newrec=(node*)malloc(sizeof(node));
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
void DeleteBegin(LL*l)
{
    node*p;
    if(l->start==NULL)
    {
        printf("\nLink list is empty.");
    }
    else
    {
        p=l->start;
        l->start=p->next;
        l->start->prev=NULL;
        free(p);
    }
}
void DeleteEnd(LL*l)
{
    node*p, *q;
    if(l->start==NULL)
    {
        printf("\nLinklist is empty.");
    }
    else if(l->start->next==NULL)
    {
        p=l->start;
        l->start=NULL;
        free(p);
    }
    else
    {
        q=l->start;
        while(q->next->next!=NULL)
        {
            q=q->next;
        }
        p=q->next;
        q->next=NULL;
        p->next=NULL;
        free(p);
    }
}
void display(LL*l)
{
    node*p;
    int c;
    if(l->start==NULL)
    {
        printf("\nLinkList is empty.");
    }
    else
    {
        printf("\n1. Forward direction.\n2. backward Direcction.");
        printf("\nEnter the choice:");
        scanf("%d", &c);
        if(c==1)
        {
            p=l->start;
            while(p!=NULL)
            {
                printf("%d\t", p->data);
                p=p->next;
            }
        }
        else if(c==2)
        {
            p=l->start;
            while(p->next!=NULL)
            {
                printf("%d\n", p->data);
                p=p->next;
            }
        }
        else
        {
            printf("\nInvalid Choice.");
        }
    }
}
int main()
{
    LL l;
    l.start=NULL;
    int ch, ele;
    while(1)
    {
        printf("\nDoubly Linklist\n");
        printf("\n\nMenu\n1. InsertBegin\n2. InsertEnd\n3. Deletebegin\n4. DeleteEnd\n5. Display\n6. Exit\n");
        printf("\nEnter the choice:");
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
                printf("\nEnter the element to be inserted:");
                scanf("%d", &ele);
                InsertBegin(&l, ele);
                display(&l);
            }
            break;
            case 2:
            {
                printf("\nEnter the element to be inserted:");
                scanf("%d", &ele);
                InsertEnd(&l, ele);
                display(&l);
            }
            break;
            case 3:
            {
                DeleteBegin(&l);
                display(&l);
            }
            break;
            case 4:
            {
                DeleteEnd(&l);
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
                printf("\nInvalid Choice.");
            }
        }
    }
    return 0;
}