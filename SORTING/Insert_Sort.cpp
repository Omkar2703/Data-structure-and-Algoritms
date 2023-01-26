//Insertion Sort
#include<iostream>
using namespace std;
void Insert_Sort(int n, int a[]){
	int i, j;
	for(i=1; i<n; i++){
		int current = a[i];
		int j = i-1;
		while(a[j]>current && j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = current;
	}
	for(i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cout<<"Enter the elements: ";
		cin>>a[i];
	}
	cout<<"\nSorted Array"<<endl;
	Insert_Sort(n, a);
	return 0;
}
