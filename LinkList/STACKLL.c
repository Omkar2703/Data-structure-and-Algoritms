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
    /*Same as InsertBegin Method in Singly LinkList.*/
    node*newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=l->start;
    l->start=newrec; 
}
int Pop(LL*l)
{
    /*Same as DeleteEnd Of SinglyLink List.*/
    node*p;
    if(l->start==NULL)
    {
        return -1;
    }
    else
    {
        p=l->start;
        l->start=p->next;
    }
    return p->data;
}
int StackTop(LL*l)
{
    /*To Print Stack top element.*/
    if(l->start==NULL)
    {
        return -1;
    }
    else
    {
        return l->start->data;
    }
}
void display(LL*l)
{
    node*p;
    if(l->start==NULL)
    {
        printf("\nStack is Underflow.");
    }
    else
    {
        p=l->start;
        while(p!=NULL)
        {
            printf("%d\n", p->data);
            p=p->next;
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
        printf("\nMenu\n1. Push\n2. Pop\n3. Stacktop\n4. Display\n5. Exit\n");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        if(ch==5)
        {
            printf("\nExit Satisfied.");
            break;
        }
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the Element to be Inserted:");
                scanf("%d", &ele);
                Push(&l, ele);
                display(&l);
            }
            break;
            case 2:
            {
                ele=Pop(&l);
                if(ele==-1)
                {
                    printf("\nStack is Underflow.");
                }
                else
                {
                    printf("\n%d is Deleted\n", ele);
                }
                
            }
            break;
            case 3:
            {
               ele=StackTop(&l);
                if(ele==-1)
                {
                    printf("\nStack is Underflow.");
                }
                else
                {
                    printf("%d is at stack top.", ele);
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
                printf("\nInvalid Choice.");
            }
        }
    }
    return 0;
}