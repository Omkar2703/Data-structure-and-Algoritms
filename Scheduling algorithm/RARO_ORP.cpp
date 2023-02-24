//implementing rr scheduling algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 10



struct PCB
{
 int PID;
 int BT;
 int AT;
 int CT;
 int RT;
 int TAT;
 int WT;
 int QT;
};
//pcb which inside cpu is stored here
PCB block;
//ram like structure (new state)
vector<PCB>pcb;
//ready queue(ready state)
queue<PCB>readyQ;
//ram like structure(terminated state)
vector<PCB>End;

//1 means cpu is free and 0 means cpu is not free	
int c=1;
//number of process(pcb's)
int n;
//global clock
int t=0;
//pointer inside the ram(memory) JOB QUEUE
int p=0;
//quantum time
int qt;

//sorting 
//pcb according to arrival time
int sortbyarrival(PCB a, PCB b)
{
	if (a.AT < b.AT)
		return 1;
	else
		return 0;
}
//pcb according to burst time
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
   
    cout<<"enter the number of process:";
    cin>>n;
    cout<<"enter quantum time:";
    cin>>qt;
    
    for(int i=0;i<n;i++)
    {
        PCB process;
		process.CT = 0;
		process.PID = i + 1;
		// accepting processes
		cout << "Enter the burst time and arrival time of P" << i + 1 << " : ";
		cin >> process.BT >> process.AT;
		process.RT = process.BT;
		process.QT=qt;
		pcb.push_back(process); // pushing all processes into vector pcb
    }
    
    sort(pcb.begin(),pcb.end(),sortbyarrival);
  
	while(1)
    {
	  //terminating condition
      //when queue is emtpy and array is also empty and cpu is also free
  		if(p==n && readyQ.empty() && c==1)
  		{
  		break;
  		}
//--------------------------------------------------------------
	   //enqueu function
	  //enqueue inside the queue untill arrival time meet with actual time
while(1)
{
	 //if pcb from array is finished
	  	if(p>=n)break;
	  
	    if(t==pcb[p].AT)  
		{
		  readyQ.push(pcb[p]);
		  p=p+1;
		  //enqueue(&q,p[ptr]);	
		 }else{
			break;
	      }
}
      
//-----------------------------------------------------------		
		//dequeu operation
		//if cpu is free(and ready queue is not empty then) then dequeue the pcb
		
		//pcb store;

		if(c==1 && !readyQ.empty())
		{
		    block=readyQ.front();
		    readyQ.pop();
			c=0;//now cpu is under execution
		}
//--------------------------------------------------------------
     //preemption logic
     //1)when rqt(remaining quantaum time is 0 then preempte)
     //2)when process will done (NO NEED TO WORRY)
     if(c==0)
     {//meaning cpu is running
      if(block.QT==0)
      {
          //means we have to preempt
          block.QT=qt;
          readyQ.push(block);
          block=readyQ.front();
          readyQ.pop();
      }
     }
//--------------------------------------------------------------
        //cpu execution
        //cpopedtime++;//counting after popping
        t++;
        if(c==0)
        {
        block.RT--;
        block.QT--;
        if(block.RT==0)
        {
        block.CT=t;
        block.TAT=block.CT-block.AT;
        block.WT=block.TAT-block.BT;
        /*cout<<"Completion time of process "<<store.pid<<" is:"<<store.ct<<"\n";*/
        End.push_back(block);
	    c=1;//cpu is free now we can pop from the ready queue
        }
        }

     
	  }	
	

	//now printing the output of process
	cout << "\t\tRound Robin" << endl;
	cout << "PID\t"
		 << "BT\t"
		 << "AT\t"
		 << "CT\t"
		 << "TAT\t"
		 << "WT\t" << endl;

	for (int i = 0; i < n; i++)
	{

		cout << "P" << End[i].PID << "\t" << End[i].BT << "  \t" << End[i].AT << "  \t" << End[i].CT << " \t" << End[i].TAT << "  \t" << End[i].WT << endl;
	}
	float waitingtime = 0;
	for (int i = 0; i < n; i++)
	{
		waitingtime = waitingtime + End[i].WT;
	}
	float TAT = 0;
	for (int i = 0; i < n; i++)
	{
		TAT += End[i].TAT;
	}
	cout << "\nAverage TAT for FCFS:" << (float)(TAT / n) << endl;			   // avg TAT
	cout << "\nAverage Waiting for FCFS:" << (float)(waitingtime / n) << endl; // avg WT
	return 0;
}