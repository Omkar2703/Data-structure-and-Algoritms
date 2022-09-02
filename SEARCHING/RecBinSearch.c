#include<stdio.h>
#include<stdlib.h>
int Binarysearch(int a[], int high, int low, int x)
{
    int mid;
    mid = (low + high)/2;
    if(low<=high)
    {
        
        if(x==a[mid])
        {
            return 1;
        }
        else if (x<a[mid])
        {
            return Binarysearch(a, mid-1, low, x);
        }
        else
        {
            return Binarysearch(a, high,  mid+1, x);
        }
        mid = (low + high)/2;
    }
    return 0;
}
void bubblesort(int a[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(i=0; i<n-1; i++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int *a, n, x, i;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("\nEnter the elements:");
        scanf("%d", &a[i]);
    }
    printf("\nEnter the element to be search:");
    scanf("%d", &x);
    bubblesort(a, n);
    printf("\nElements entered are..\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    if(Binarysearch(a, n-1, 0, x))
    {
        printf("\nElement is found.");
    }
    else
    {
        printf("\nElement is not found.");
    }
    return 0;
}