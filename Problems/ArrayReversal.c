#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, a[10], i, temp;
    printf("\nNumber of elements in array:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the elements:");
        scanf("%d", &a[i]);
    }
    printf("\n\nOrignal array is...\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    printf("\n\nReversed array is....\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}