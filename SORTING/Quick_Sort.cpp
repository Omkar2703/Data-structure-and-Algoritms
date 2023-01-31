//Quick Sort
#include<iostream>
using namespace std;
int Partition(int a[], int p, int q){
	//p and q are left and right.
	int i, j, X;
	//Left pivot Point
	X = a[p];
	i = p;
	for(j=p+1; j<=q; j++){
		if(a[j]<X){
			i=i+1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i];
	a[i] = a[p];
	a[p] = temp;
	return i;
}
int Quick_Sort(int a[], int p, int q){
	if(p<q){
		int m=Partition(a, p, q);
		Quick_Sort(a, p, m-1);
		Quick_Sort(a, m+1, q);
	}
}
int main(){
	int n;
	cout<<"Enter the numer of elements: ";
	cin>>n;
	int a[n];
	int i;
	for(i=0; i<n; i++){
		cout<<"Enter the element: ";
		cin>>a[i];
	}
	cout<<"\nSorted array\n"<<endl;
	Quick_Sort(a, 0, n-1);
	for(i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
