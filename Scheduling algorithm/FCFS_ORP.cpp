//FCFS
#include<bits/stdc++.h>
using namespace std;
#define max 10
//Process Control Block
struct PCB{
 int PID;//process id
 int BT;//burst time
 int AT;//arrival time
 int CT;//Completion time
 int RT;//remaining time
 int TAT;//Turn Around Time
 int WT;//Waiting Time
};
vector<PCB>pcb;//to accept the process
queue<PCB>readyQ;//ready queue
vector<PCB>End;//ended process
//Sort processes according to their burst time
int sortbyarrival(PCB a, PCB b){
	if (a.AT < b.AT)
		return 1;
	else
		return 0;
}
//Sort processes according to their arrival time
int sortbyburst(PCB a, PCB b){
	if (a.BT < b.BT)
		return 1;
	else
		return 0;
}
int main(){
	int c=1;//Means CPU is free
	int n;
	int clock=0;//clock
	int p=0;//Queue Pointer
    cout<<"Enter the number of process:";
    cin>>n;
    for(int i=0;i<n;i++){
        PCB process;
        process.CT=0;
        process.PID=i+1;
		//accepting processes
        cout<<"Enter the burst time and arrival time of P"<<i+1<<" : ";
        cin>>process.BT>>process.AT;
        process.RT=process.BT;
        pcb.push_back(process);//pushing all processes into vector pcb
    }
    
    sort(pcb.begin(),pcb.end(),sortbyarrival);
  
	while(1){
  		if(p==n && readyQ.empty() && c==1){
  		break;//checking condition for Queue, vector and cpu underflow
  		}
	    while(1){
	  	//enqueue process inside queue till at matches with actual time
	  	if(p>=n){
			break;//when all processes in vector are completed
		}
	  
	    if(clock==pcb[p].AT)  {
		  readyQ.push(pcb[p]);
		  p=p+1;
		 }
		 else{
			break;
	      }
        }
      
		//dequeue process from pcb if cpu is free
		
		PCB block;//storing variable

		if(c==1 && !readyQ.empty()){
		    block=readyQ.front();
		    readyQ.pop();
			c=0;//now cpu is not free
		}
		//calculating ct and wt
        clock++;
        if(c==0){
        block.RT--;
        if(block.RT==0){
        block.CT=clock;
        block.TAT=block.CT-block.AT;
        block.WT=block.TAT-block.BT;
        End.push_back(block);
	    c=1;//remove from ready queue as cpu is not nder execution
        }
        }
	  }	
	

	cout<<"\t\tFirst come First serve"<<endl;
    cout<<"PID\t"<<"BT\t"<<"AT\t"<<"CT\t"<<"WT\t"<<endl;
    
    for(int i=0;i<n;i++){
		
		 cout<<"P"<<End[i].PID<<"\t"<<End[i].BT<<"  \t"<<End[i].AT<<"  \t"<<End[i].CT<<"  \t"<<End[i].WT<<endl;
		
	}
    float waitingtime=0;
	for(int i=0;i<n;i++){
		waitingtime=waitingtime+End[i].WT;
	}
	float tat=0;
	for(int i=0; i<n; i++){
		tat+=End[i].TAT;
	}
	cout<<"\nAverage TAT for FCFS:"<<(float)(tat/n)<<endl;
	cout<<"\nAverage Waiting for FCFS:"<<(float)(waitingtime/n)<<endl;
    return 0;
}
