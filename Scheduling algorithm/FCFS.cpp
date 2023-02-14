//implementing fcfs scheduling algorithm

#include<bits/stdc++.h>
using namespace std;
#define max 10


//all dATa struCTres which are used inside the program
//PCB(process control block)
struct PCB
{
 int PID;
 int BT;
 int AT;
 int CT;
 int RT;//remaining time(going to decrement every sec when it become 0 process is done)
 int TAT;//CT-AT
 int WT;//TAT-BT
};
//ram like struCTure (new sTATe)
vector<PCB>pcb;
//ready queue(ready sTATe)
queue<PCB>readyQ;
//ram like struCTure(EndminATed sTATe)
vector<PCB>End;

//1 means cpu is free and 0 means cpu is not free	
int c=1;
//number of process(PCB's)
int n;
//global clock
int t=0;
//poinEnd inside the ram(memory) JOB QUEUE
int p=0;

//soRTing 
//PCB according to arrival time
int sortbyarrival(PCB a, PCB b)
{
	if (a.AT < b.AT)
		return 1;
	else
		return 0;
}
//PCB according to burst time
int sortbyburst(PCB a, PCB b)
{
	if (a.BT < b.BT)
		return 1;
	else
		return 0;
}



//one's the global time reach the arrival time push inside the queue and once cpu is free send for execution

int main()
{
   
    cout<<"Enter the number of process:";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        PCB process;
        process.CT=0;
        process.PID=i+1;

        cout<<"enEnd the burst time of process "<<i+1<<"is:";
        cin>>process.BT;
        cout<<"enEnd the arrival time of process"<<i+1<<"is:";
        cin>>process.AT;
        process.RT=process.BT;
        
        pcb.push_back(process);
    }
    
    sort(pcb.begin(),pcb.end(),sortbyarrival);
  
	while(1)
    {
	  //EndminATing condition
      //when queue is emtpy and array is also empty and cpu is also free
  		if(p==n && readyQ.empty() && c==1)
  		{
  		break;
  		}
//--------------------------------------------------------------
	   //enqueu funCTion
	  //enqueue inside the queue untill arrival time meet with aCTual time
	    while(1)
	    {
	  	//if PCB from array is finished
	  	if(p>=n)break;
	  
	    if(t==pcb[p].AT)  
		{
		  readyQ.push(pcb[p]);
		  p=p+1;
		  //enqueue(&q,p[p]);	
		 }else{
			break;
	      }
        }
      
//-----------------------------------------------------------		
		//dequeu operATion
		//if cpu is free(and ready queue is not empty then) then dequeue the PCB
		
		PCB block;

		if(c==1 && !readyQ.empty())
		{
		    block=readyQ.front();
		    readyQ.pop();
			//cpopedtime=0;
			//popedtime=0;
			c=0;//now cpu is under execution
		}
//--------------------------------------------------------------
        //cpu execution
        //cpopedtime++;//counting afEnd popping
        t++;
        if(c==0)
        {
        block.RT--;
        if(block.RT==0)
        {
        block.CT=t;
        block.TAT=block.CT-block.AT;
        block.WT=block.TAT-block.BT;
        /*cout<<"Completion time of process "<<block.PID<<" is:"<<block.CT<<"\n";*/
        End.push_back(block);
	    c=1;//cpu is free now we can pop from the ready queue
        }
        }
	  }	
	

	//now printing the output of process
	cout<<"\t\tFCFS"<<endl;
    cout<<"PID\t"<<"BT\t"<<"AT\t"<<"CT\t"<<"WT\t"<<endl;
    
    for(int i=0;i<n;i++)
	{
		
		 cout<<End[i].PID<<" \t"<<End[i].BT<<"  \t"<<End[i].AT<<"  \t"<<End[i].CT<<"  \t"<<End[i].WT<<endl;
		
	}
    int waitingtime=0;
	for(int i=0;i<n;i++)
	{
		waitingtime=waitingtime+End[i].WT;
	}

	cout<<"Avg Waiting for FCFS:"<<(float)(waitingtime/n)<<endl;
    return 0;
}