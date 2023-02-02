//AOA Practical 1
//Bubble Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int a[], int n){
    //Sorting Function
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    clock_t start, end;
    int *x;
    FILE *Rand, *Sort;
    float total; 
    printf("\nEnter the size: ");
    scanf("%d", &n);
    x = (int*)malloc(sizeof(int)*n);
    Rand = fopen("arr_rand.txt", "w"); //This will open the file in given mode
    for(i=0; i<n; i++){
        fprintf(Rand,"%d\n",(rand())); // Writes random input in the input file
    }
    fclose(Rand);
    Rand = fopen("arr_rand.txt", "r");
    for(i=0; i<n; i++){
        fscanf(Rand,"%d",&x[i]); //this will place the value in array
    }
    start = clock();
    //Timer Started
    bubbleSort(x, n);
    end = clock();
    //Timer Stoped
    Sort = fopen("arr_sort.txt", "w");
    for(i=0; i<n; i++){
        fprintf(Sort,"%d\n",x[i]); // writes all the input form array to arr_sort.txt file
    }
    total = (float)(end - start) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC is contant predefined in <time.h>
    printf("\nTime: %f", total);
    return 0;
}