#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 15
typedef struct
{
    int a[MAX];
    int top;
}stack;
void push(stack*s, int ele)
{
    s->top++;
    s->a[s->top]=ele;
}
int pop(stack*s)
{
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
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
int isoperand(char x)
{
    if(x >='0'&& x<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int evaluatepostfix(char post)
{
    stack s;
    s.top=-1;
    char x;
    int op1, op2, i, v;
    for(i=0;i<strlen(post);i++)
    {
        x=post[i];
        if (isoperand(x))
        {
            push(&s,(int)x-'0');
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            switch(x)
            {
                case '+':{
                    v=op1+op2;
                    break;
                }
                case '-':{
                    v=op1-op2;
                    break;
                }
                case '*':{
                    v=op1*op2;
                    break;
                }
                case '/':{
                    v=op1/op2;
                    break;
                }
                push(&s, v);
            }
        }
    }
    return pop(&s);
}
int main()
{
    char post[10];
    printf("\nEnter the postfix expression:");
    gets(post);
    printf("Result id %d",evaluatepostfix(post));
    return 0;
}