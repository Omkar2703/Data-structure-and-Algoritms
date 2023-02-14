//implementing fcfs scheduling algorithm

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 10


//all data structres which are used inside the program
//pcb(process control block)
struct pcb
{
 int pid;
 int bt;
 int at;
 int ct;
 int rt;//remaining time(going to decrement every sec when it become 0 process is done)
 int tat;//ct-at
 int wt;//tat-bt
};
//ram like structure (new state)
vector<pcb>p;
//ready queue(ready state)
queue<pcb>qready;
//ram like structure(terminated state)
vector<pcb>ter;

//1 means cpu is free and 0 means cpu is not free	
int c=1;
//number of process(pcb's)
int n;
//global clock
int t=0;
//pointer inside the ram(memory) JOB QUEUE
int ptr=0;

//sorting 
//pcb according to arrival time
int sortat(pcb a, pcb b)
{
	if (a.at < b.at)
		return 1;
	else
		return 0;
}
//pcb according to burst time
int sortbt(pcb a, pcb b)
{
	if (a.bt < b.bt)
		return 1;
	else
		return 0;
}



//one's the global time reach the arrival time push inside the queue and once cpu is free send for execution

int main()
{
   
    cout<<"enter the number of process:";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        pcb temp;
        temp.ct=0;
        temp.pid=i+1;

        cout<<"enter the burst time of process "<<i+1<<"is:";
        cin>>temp.bt;
        cout<<"enter the arrival time of process"<<i+1<<"is:";
        cin>>temp.at;
        temp.rt=temp.bt;
        
        p.push_back(temp);
    }
    
    sort(p.begin(),p.end(),sortat);
  
	while(1)
    {
	  //terminating condition
      //when queue is emtpy and array is also empty and cpu is also free
  		if(ptr==n && qready.empty() && c==1)
  		{
  		break;
  		}
//--------------------------------------------------------------
	   //enqueu function
	  //enqueue inside the queue untill arrival time meet with actual time
	    while(1)
	    {
	  	//if pcb from array is finished
	  	if(ptr>=n)break;
	  
	    if(t==p[ptr].at)  
		{
		  qready.push(p[ptr]);
		  ptr=ptr+1;
		  //enqueue(&q,p[ptr]);	
		 }else{
			break;
	      }
        }
      
//-----------------------------------------------------------		
		//dequeu operation
		//if cpu is free(and ready queue is not empty then) then dequeue the pcb
		
		pcb store;

		if(c==1 && !qready.empty())
		{
		    store=qready.front();
		    qready.pop();
			//cpopedtime=0;
			//popedtime=0;
			c=0;//now cpu is under execution
		}
//--------------------------------------------------------------
        //cpu execution
        //cpopedtime++;//counting after popping
        t++;
        if(c==0)
        {
        store.rt--;
        if(store.rt==0)
        {
        store.ct=t;
        store.tat=store.ct-store.at;
        store.wt=store.tat-store.bt;
        /*cout<<"Completion time of process "<<store.pid<<" is:"<<store.ct<<"\n";*/
        ter.push_back(store);
	    c=1;//cpu is free now we can pop from the ready queue
        }
        }
	  }	
	

	//now printing the output of process
	cout<<"\t\tFCFS"<<endl;
    cout<<"PID\t"<<"BT\t"<<"AT\t"<<"CT\t"<<"WT\t"<<endl;
    
    for(int i=0;i<n;i++)
	{
		
		 cout<<ter[i].pid<<" \t"<<ter[i].bt<<"  \t"<<ter[i].at<<"  \t"<<ter[i].ct<<"  \t"<<ter[i].wt<<endl;
		
	}
    int waitingtime=0;
	for(int i=0;i<n;i++)
	{
		waitingtime=waitingtime+ter[i].wt;
	}

	cout<<"Avg Waiting for FCFS:"<<(float)(waitingtime/n)<<endl;
    return 0;
}