//Vector 
#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int i, n, x;
	cout<<"Enter the number of elements: ";
	cin>>n;
	vector<int>p;
	for(i=0; i<n; i++){
		cout<<"\nEnter the element: ";
		cin>>x;
		p.push_back(x);
	}
	cout<<"\nEntered elements are...\n";
	display(p);
}
