#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10
typedef struct 
{
    int a[MAX];
    int top;
}stack;
//Function to insert the element into stack.
void push(stack*s, int ele)
{
    s->top++;
    s->a[s->top]=ele;
}
//Function to delete element from stack.
int pop(stack*s)
{
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
}
//Function to check operand.
int isoperand(char a)
{
    if(a>='0'&&a<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*Function to evaluate postfix operation.*/
int evaluatepost(char post[])
{
    stack s;
    s.top=-1;
    int op1, op2, v;
    char y, a;
    for (int i = 0; i < strlen(post); i++)
    {
        y=post[i];
        if (isoperand(a))
        {
            push(&s, (int)a-'0');
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            switch (y)
            {
            case '+':
            {
                v=op1+op2;
                break;
            }
            case '-':
            {
                v=op1-op2;
                break;
            }
            case '*':
            {
                v=op1*op2;
                break;
            }
            case '/':
            {
                v=op1/op2;
                break;
            }
            case '%':
            {
                v=op1%op2;
                break;
            }
            default:
            {
                printf("\nInvalid choice.");
                break;
            }
            }
            push(&s, v);
        }
        
    }
    return pop(&s);
}
int main()
{
    char post[10];
    printf("\nEnter the postfix expression:");
    gets(post);
    printf("result = %d",evaluatepost(post));
    return 0;
}