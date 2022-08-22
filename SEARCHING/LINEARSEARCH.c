/*MY code for linear search😎😉🤞*/
#include<stdio.h>
#include<stdlib.h>
int linearsearch( int a[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            printf("\nElement found at %d", i);
        }
        else
        {
            printf("\nElement not found at %d", i);
        }
    }
}
int main()
{
    int *a, n, x, i;
    printf("\nEnter the number elements:");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("\nEnter the elements:");
        scanf("%d", &a[i]);
    }
    printf("\nEnter the element to be search:");
    scanf("%d", &x);
    printf("\nElements in array are....\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    linearsearch(a , n, x);
    return 0;
}