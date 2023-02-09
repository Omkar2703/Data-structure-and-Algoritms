// Quick Sort
#include <stdio.h >
int Partition(int a[], int p, int q)
{
    // p and q are left and right.
    int i, j, X, temp;
    // Left pivot Point
    X = a[p];
    i = p;
    for (j = p + 1; j <= q; j++)
    {
        if (a[j] < X)
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i];
    a[i] = a[p];
    a[p] = temp;
    return i;
}
int Quick_Sort(int a[], int p, int q)
{
    if (p < q)
    {
        int m = Partition(a, p, q);
        Quick_Sort(a, p, m - 1);
        Quick_Sort(a, m + 1, q);
    }
}
int main()
{
    int n;
    int a[n];
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }
    printf("\nSorted array\n");
	Quick_Sort(a, 0, n-1);
	for(i=0; i<n; i++){
        printf("%d\t", a[i]);
	}
	printf("\n");
	return 0;
}
