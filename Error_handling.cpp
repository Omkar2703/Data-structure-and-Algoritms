//Error handling(Data link layer)
#include<iostream>
#include<vector>
using namespace std;
//Parity check function
void parityCheck(){
    cout<<"Parity Check technique\n";
}


/*-------------------------*/
//Check Sum function

void accept_Bits(vector<int> &f){
    cout<<"\nEnter the 8 bit binary: ";
    for(int i = 0; i<8; i++){
        cin>>f[i];
    }
    cout << "\nf: ";
    for(int i = 0; i<8; i++){
        cout<<f[i];
    }
}
void divide(vector<int>& f, vector<int>& f1, vector<int>& f2) {
    for (int i = 0; i < 4; i++) {
        f1.push_back(f[i]);
    }
    for (int i = 4; i < 8; i++) {
        f2.push_back(f[i]);
    }
    cout << "\nf1: ";
    for (int i = 0; i < f1.size(); i++) {
        cout << f1[i];
    }
    cout << "\nf2: ";
    for (int i = 0; i < f2.size(); i++) {
        cout << f2[i];
    }
}
void binaryAddition(vector<int>& f1, vector<int>& f2, vector<int> &result) {
    int carry = 0;
    for (int i = 3; i >= 0; i--) {
        int sum = f1[i] + f2[i] + carry;
        if (sum == 0) {
            result[i] = 0;
            carry = 0;
        } else if (sum == 1) {
            result[i] = 1;
            carry = 0;
        } else if (sum == 2) {
            result[i] = 0;
            carry = 1;
        } else { // sum == 3
            result[i] = 1;
            carry = 1;
        }
    }
}
void binaryComplement(vector<int> &Bin_result, vector<int> &Comp){
    for(int i = 0; i<Bin_result.size(); i++){
        if(Bin_result[i] == 1){
            Bin_result[i] = 0;
        }
        else if(Bin_result[i] == 0){
            Bin_result[i] = 1;
        }
        Comp.push_back(Bin_result[i]);
    }
    cout << "\nComplement of Binary Addition: ";
    for (int i = 0; i < Comp.size(); i++) {
        cout << Comp[i];
    }
}
void CheckSumRecivers(vector<int> &f, vector<int> &Bin_result){
    vector<int> Rf1;
    vector<int> Rf2;
    vector<int> Rf3;
    vector<int> RBin_result(4, 0);
    for (int i = 0; i < 4; i++) {
        Rf1.push_back(f[i]);
    }
    for (int i = 4; i < 8; i++) {
        Rf2.push_back(f[i]);
    }
    for (int i = 8; i < 12; i++) {
        Rf3.push_back(f[i]);
    }
    cout << "\nRf1: ";
    for (int i = 0; i < Rf1.size(); i++) {
        cout << Rf1[i];
    }
    cout << "\nRf2: ";
    for (int i = 0; i < Rf2.size(); i++) {
        cout << Rf2[i];
    }
    cout << "\nRf3: ";
    for (int i = 0; i < Rf3.size(); i++) {
        cout << Rf3[i];
    }
    binaryAddition(Rf1, Rf2, Bin_result);
    binaryAddition(Bin_result, Rf3, RBin_result);
    cout << "\nBinaryAddition: ";
    for (int i = 0; i < RBin_result.size(); i++) {
        cout << RBin_result[i];
    }
    int count = 0;
    int i = 0;
    for( ; i< RBin_result.size(); i++){
        if(RBin_result[i] == 1){
            count++;
        }
    }
    cout<<"\n\nFinal Output: ";
    if((count%2) == 0){
        cout<<"No error\n";
    }
    else{
        cout<<"Error\n";
    }
}
void checkSum(){
    cout<<"Check Sum technique\n";
    vector<int> f(8);
    vector<int> f1;
    vector<int> f2;
    vector<int> Comp;
    accept_Bits(f); //accepts the 8 bits binary message
    divide(f, f1, f2); //Divides main binary message to 4 bits two frames
    vector<int> Bin_result(4, 0);
    cout<<"\n\nSender's Side calculations =>\n";
    binaryAddition(f1, f2, Bin_result);
    cout << "\nBinaryAddition: ";
    for (int i = 0; i < Bin_result.size(); i++) {
        cout << Bin_result[i];
    }
    binaryComplement(Bin_result, Comp);
    cout<<"\n";
    f.insert(f.end(), Comp.begin(), Comp.end());
    cout<<"Data + Complement: ";
    for(int i = 0; i<f.size(); i++){
        cout<<f[i];
    }
    cout<<"\n\nReciever's Side calculations =>\n";
    CheckSumRecivers(f, Bin_result);
    
}


/*-------------------------*/
//CRC function
void CRC(){
    cout<<"CRC technique\n";
}


/*-------------------------*/

int main(){
    int Choice;
    while(true){
        cout<<"\nMenu\n1. Parity check\n2. checkSum\n3. CRC\n";
        cout<<"\nEnter the choice: ";
        cin>>Choice;
        
        switch (Choice)
        {
        case 1:
            parityCheck();
            break;
        case 2:
            checkSum();
            break;
        case 3:
            CRC();
            break;
        default:
            break;
        }
    }
    return 0;
}