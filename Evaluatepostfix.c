/*Evaluate Postfix Exression.*/
#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct 
{
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
char stacktop(stack*s)
{
    if(isempty(s))
    {
        printf("\nStack is underflow.");
    }
    else
    {
        return s->a[s->top];
    }
}
int postfixvalue(char post[])
{
    stack s;
    s.top=-1;
    int i, op1, op2, v;
    char x;
    for(i=0; i<strlen(post);i++)
    {
        if(isoperand(post[i]))
        {
            push(&s, (int)post[i]-'0');
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            switch (post[i])
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
                }
            }
            push(&s, v);
        }
    }
    return pop(&s);
}
int main()
{
    stack s;
    s.top=-1;
    int P;
    char post[50];
    printf("\nEnter the expression:");
    gets(post);
    P=postfixvalue(post);
    printf("\nThe value of expression = %d", P);
    return 0;
}