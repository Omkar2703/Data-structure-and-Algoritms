#include<bits/stdc++.h>
using namespace std;
#define MAX 10

struct PCB{
    //Process Control Block
    int PID;//process id
    int AT;//arrival time
    int BT;//burst time
    int RT;//remaining time
    int CT;//Completion time
    int TAT;//Turn Around Time
    int WT;//Waiting Time
};


vector<PCB>pcb;//to accept the process
queue<PCB>readyQ;//ready queue
vector<PCB>End;//ended process

//Sort processes according to their burst time
int SortbyBurst(PCB a, PCB b){
    if(a.BT<b.BT){
        return 1;
    }
    else{
        return 0;
    }
}

//Sort processes according to their arrival time
int Sortbyarrival(PCB a, PCB b){
    if(a.AT<b.AT){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    int c = 1;//Means CPU is free
    int clock = 0;
    int p = 0;//Queue Pointer
    cout<<"\nEnter the number of processes: ";
    cin>>n;
    //accepting processes
    for(int i=0; i<n; i++){
        PCB process;
        process.CT=0;
        process.PID=i+1;
		cout<<"\nEnter the Burst Time and Arrival Time of P"<<i+1<<" : ";
		cin>>process.BT>>process.AT;
        process.RT=process.BT;
		pcb.push_back(process);//pushing all processes into vector pcb
    }
    sort(pcb.begin(), pcb.end(), Sortbyarrival);
    while(1){
        if(p==n&&readyQ.empty()&&c==1){
            break;//checking condition for Queue, vector and cpu underflow
        }
        while(1){
            //enqueue process inside queue till at matches with actual time
            if(p>=n){
                break;//when all processes in vector are completed
            }
            if(clock==pcb[p].AT){
                readyQ.push(pcb[p]);
                p+=1;
            }
            else{
                break;
            }
        }
        //dequeue process from pcb if cpu is free
        PCB block;//storing variable
        if(c==1&&!readyQ.empty()){
            block=readyQ.front();
            readyQ.pop();
            //now cpu is not free
            c=0;
        }
        clock++;
        if(c=0){
            block.RT--;
            if(block.RT==0){
                //calculating ct and wt
                block.CT=clock;
                block.TAT=block.CT-block.AT;
                block.WT=block.TAT-block.BT;
                End.push_back(block);
                c=1;
                //remove from ready queue as cpu is not nder execution
            }
        }

    }
    cout << "\t\tFirst Come first serve\n";
	for(int i=0; i<n; i++){
		cout<<"P"<<i+1<<"\t"<<"BT: "<< End[i].BT << "  \t" <<"AT: "<< End[i].AT << "  \t" <<"CT: "<< End[i].CT << "\t" <<"WT: "<< End[i].WT << endl;
	}
    int waitingtime=0;
    for(int i=0; i<n; i++){
        waitingtime+=End[i].WT;
    }
    cout<<"Average Waiting time: "<< (float)(waitingtime/n);
    return 0;
}