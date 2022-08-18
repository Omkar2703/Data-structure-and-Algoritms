#include<stdio.h>
#define MAX 15
typedef struct
{
    /* data */
    int a[MAX];
    int top;
}stack;
void push(stack*s, int ele)
{
    if(s->top==MAX)
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
    if(isempty(s))
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
    printf("\n");
}
int main()
{
    stack s;
    int ch, ele;
    s.top=-1;
    while (1)
    {
        /* code */
        printf("\nMenu.\n1. Push.\n2. Pop.\n3. Stacktop.\n4. Display.\n5. Exit.\n");
        printf("\nEnter the choice:");
        scanf("%d", &ch);
        if(ch==5)
        {
            printf("\nExit satisfied.");
            break;
        }
        switch (ch)
        {
            case 1:
            {
                printf("\nEnter the element to be pushed:");
                scanf("%d", &ele);
                push(&s, ele);
                break;
            }
            case 2:
            {
                ele=pop(&s);
                if(ele==-1)
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
                ele=stacktop(&s);
                if(ele==-1)
                {
                    printf("\nStack is underflow.");
                }
                else
                {
                    printf("\n%d is at top.", ele);
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
                break;
            }
            default:
            {
                printf("Invalid choice.");
                break;
            }
        }
    }
    return 0;
}