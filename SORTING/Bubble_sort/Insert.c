// InsertionSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insert_Sort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    int *x;
    FILE *Rand, *Sort;
    float total;
    printf("\nHow many Inputs? ");
    scanf("%d", &n);
    x = (int *)malloc(sizeof(int) * n);
    Rand = fopen("arr_rand.txt", "w"); // This will open the file in given mode
    for (i = 0; i < n; i++)
    {
        fprintf(Rand, "%d\n", (rand())); // Writes random input in the input file
    }
    fclose(Rand);
    Rand = fopen("arr_rand.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(Rand, "%d", &x[i]); // this will place the value in array
    }
    start = clock();
    // Timer Started
    Insert_Sort(x, n);
    end = clock();
    // Timer Stoped
    Sort = fopen("arr_sort.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(Sort, "%d\n", x[i]); // writes all the input form array to arr_sort.txt file
    }
    // Calculate time
    total = (float)(end - start) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC is contant predefined in <time.h>
    printf("\nTime: %f", total);
    return 0;
}
