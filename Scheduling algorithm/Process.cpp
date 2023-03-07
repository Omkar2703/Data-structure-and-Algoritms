//Process Management
#include<bits/stdc++.h>
using namespace std;
void FCFS(){
    //FCFS Scheduling
    cout<<"FCFS"<<endl;
}
void SJF(){
    //SJF Scheduling
    cout<<"SJF"<<endl;
}
void SRTN(){
    //SJF Preamptive (SRTN)
    cout<<"SRTN"<<endl;
}
void RR(){
    //Round robin Scheduling
    cout<<"RR"<<endl;
}
int main(){
    cout<<"\n\nMenu\n1. FCFS\n2. Shortest Job First\n3. SJF(Preamptive)\n4. Round Robin\n\n";
    int choice;
    cout<<"\nEnter the choice: ";
    cin>>choice;
    switch(choice){
        case 1:{
            FCFS();
        }
        break;
        case 2:{
            SJF();
        }
        break;
        case 3:{
            SRTN();
        }
        break;
        case 4:{
            RR();
        }
        break;
        default:{
            cout<<"\nInvalid Inputs";
        }
    }
    return 0;
}