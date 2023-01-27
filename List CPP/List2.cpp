#include<iostream>
#include<list>
using namespace std;
void display(list<int>&lst){
    list<int> :: iterator it;
    for(it = lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    list<int>l1;
    int c;
    while(1){
        int x;
        cout<<"\n1. Push\n2. Exit\n3. display\n4. Sort\n5. Pop\n";
        cout<<"\nEnter the choice: ";
        cin>>c;
        if(c==1){
            cout<<"Enter the element: ";
            cin>>x;
            l1.push_back(x);
        }
        else if(c==2){
            break;
        }
        else if(c==3){
            display(l1);
        }
        else if(c==4){
            l1.sort();
        }
        else if(c==5){
            l1.pop_back();
        }
        else{
            cout<<"\nInvalid Input\n";
        }
    }
    return 0;
}