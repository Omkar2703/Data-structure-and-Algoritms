#include<iostream>
#include<list>
using namespace std;
void display(list<int> &lst){
    list<int> :: iterator it;
    for(it = lst.begin(); it!=lst.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
    list<int>l1;//list of n length
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(15);
    l1.push_back(8);
    l1.push_back(23);
    display(l1);
    return 0;
}