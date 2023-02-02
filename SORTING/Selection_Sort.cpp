//Selection Sort
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int a[n], i, j;
    for(i=0; i<n; i++){
        cout<<"Enter the element: ";
        cin>>a[i];
    }
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(a[j]<a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
//Output
//Enter the size: 5
//Enter the element: 12
//Enter the element: 45
//Enter the element: 8
//Enter the element: 31
//Enter the element: 52
//8 12 31 45 52 
