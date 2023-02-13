//Merge Sort
#include<stdio.h>

//Function for simple Merge
void Merge(int a[], int l, int mid, int r){
		 int k = l;
		 int i = l;
		 int j = mid+1;
		 int temp[r+1];
		 while(i<=mid && j<=r){
		 	if(a[i]<a[j]){
		 		temp[k] = a[i];
		 		k++; i++;
			 }
			 else{
			 	temp[k] = a[j];
			 	k++; j++;
			 }
		 }
		 while(i<=mid){
		 	temp[k] = a[i];
		 	k++; i++;
		 }
		 while(j<=r){
		 	temp[k] = a[j];
		 	k++; j++;
		 }
		 //copy temp to a
		 for(i=l; i<=r; i++){
		 	a[i] = temp[i];
		 }
		 
}
//function for merge sort
void MergeSort(int a[], int l, int r){
	if(l<r){
		//taking mid point
		int mid = (l+r)/2;
		MergeSort(a, l, mid);
		MergeSort(a, mid+1, r);
		Merge(a, l, mid, r);
	}
}
int main(){
	int n;
	//Accepting size of array
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int a[n];
	int i;
	//Accepting element in array
	for(i=0; i<n; i++){
		printf("Enter the elements: ");
		scanf("%d", &a[i]);
	}
	//Calling merge sort function
	MergeSort(a, 0, n-1);
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}