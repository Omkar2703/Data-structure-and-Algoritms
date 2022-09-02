#include<stdio.h>
#include<stdlib.h>
void linearsearch(int a[], int n, int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(x == a[i])
        {
            printf("\nElement is found.");
            return;
        }
        printf("\nElement is not found.");
    }
}
int main()
{
    int *a, n, x, i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("\nEnter the elements:");
        scanf("%d", &a[i]);
    }
    printf("\nElements entered are..\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nEnter the elements to be search:");
    scanf("%d", &x);
    linearsearch( a, n, x);
    return 0;
}