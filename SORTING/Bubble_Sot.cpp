#include<iostream>
using namespace std;
void Bubble_sort(int n, int a[]){
    int counter=1;
    int i;
    while(counter<n){
        for(i=0; i<n-counter; i++){
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        counter++;
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
    int i;
    int a[n];
    for(i=0; i<n; i++){
        cout<<"Enter the elements: ";
        cin>>a[i];
    }
    cout<<"\nSorted array"<<endl;
    Bubble_sort(n, a);
    return 0;
}