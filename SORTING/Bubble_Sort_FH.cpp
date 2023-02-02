// AOA Practical No 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubblesort(int x[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;
            }
        }
    }
}
int main()
{
    int *arr, i, j;
    FILE *random, *sorted;
    float total;
    clock_t start, end;
    random = fopen("random.txt", "w");
    sorted = fopen("sorted.txt", "w");
    for (i = 5000; i <= 25000; i = i + 5000)
    {
        arr = (int *)(malloc(i * sizeof(int)));
        printf("\nFor n = %d\n", i);
        // write i numbers of randam values from 0 to i in random file
        for (j = 0; j < i; j++)
        {
            fprintf(random, "%d ", rand() % i);
        }
        fclose(random);

        random = fopen("random.txt", "r");

        // read the i numbers of random values and store them in array of int
        for (j = 0; j < i; j++)
        {
            fscanf(random, "%d", &arr[j]);
        }
        start = clock();

        bubblesort(arr, i);

        end = clock();
        total = (float)(end - start) / CLOCKS_PER_SEC;
        for (j = 0; j < i; j++)
        {
            fprintf(sorted, "%d ", arr[j]);
        }
        printf("Time : %f\n\n", total);
    }
    fclose(random);
    fclose(sorted);
    return 0;
}
