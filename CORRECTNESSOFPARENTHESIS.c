#include<stdio.h>
#include<string.h>
#define MAX 20
typedef struct 
{
    /* data */
    char a[MAX];
    int top;
}stack;
void push(stack*s, char ele)
{
    s->top++;
    s->a[s->top]=ele;
}
int pop(stack*s)
{
    char x;
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
char stacktop(stack*s)
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
int isopeningbracket(char x)
{
    if(x=='('||x=='['||x=='{')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isclosingbracket(char x)
{
    if(x==')'||x==']'||x=='}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkkaro(char s1[])
{
    stack s;
    s.top=-1;
    int i, x, ele;
    for(i=0; i<strlen(s1);i++)
    {
        if(isopeningbracket(s1[i]))
        {
            push(&s, s1[i]);
        }
        else if (isclosingbracket(s1[i]))
        {
            if(isempty(&s))
            {
                return 0;
            }
            else
            {
                ele=pop(&s);
                if(s1[i]==')'&&ele!='(')
                {
                    return 0;
                }
                if(s1[i]==']'&&ele!='[')
                {
                    return 0;
                }
                if(s1[i]=='}'&&ele!='{')
                {
                    return 0;
                }
            }
        }
    }
    if(isempty(&s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    stack s;
    char s1[20];
    printf("\nEnter the expression:");
    gets(s1);
    if(checkkaro(s1))
    {
        printf("\nParenthesis is correct.");
    }
    else
    {
        printf("\nParenthesis is not correct.");
    }
    return 0;
}