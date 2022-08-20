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
int isoperand(char x)
{
    if((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(stack*s)
{
    char i;
    if(isempty(s))
    {
        printf("\nStack is overflow");
    }
    else
    {
        for(i=s->top;i>=0;i--)
        {
            printf("  %c  \n", s->a[i]);
        }
    }
}
int ICP(char ch)
{
    switch(ch)
    {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2; 
        case '*':
        case '/':
            return -2;
        case '%':
        default:
            return -1;
    }
}
void convert(char infix[], char postfix[])
{
    stack s;
    s.top=-1;
    int i, j, k=0, ele;
    for(i=0;i<strlen(infix);i++)
    {
        if(isoperand(infix[i]))
        {
            postfix[k++]=infix[i];
        }
        else if(isoperator(infix[i]))
        {
            push(&s, infix[i]);
        }
        else if(infix[i]=='(')
        {
            push(&s, infix[i]);
        }
        else if(infix[i]==')')
        {
            while(1)
            {
                ele=pop(&s);
                if(ele=='(')
                {
                    break;
                }
                postfix[k++]=ele;
            }
        }
        else if(isempty(&s))
        {
            push(&s, infix[i]);
        }
        else if (ICP(infix[i])>ICP(stacktop(&s)))
        {
            push(&s, infix[i]);
        }
        else
        {
            while((isempty(&s)==0)&&(ICP(infix[i])>ICP(stacktop(&s))))
            {
                ele=pop(&s);
                postfix[k++]=ele;
            }
            push(&s, infix[i]);
        }
    }
    display(&s);
    while(isempty(&s)==0)
    {
        ele=pop(&s);
        postfix[k++]=ele;
    }
    for(j=0;j<k;j++)
    {
        printf("%c ", postfix[j]);
    }
}
int main()
{
    stack s;
    char infix[20], postfix[20];
    printf("\nEnter the infix Expression:");
    gets(infix);
    convert(infix, postfix);
    return 0;
}