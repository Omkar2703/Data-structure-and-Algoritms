//Process Management
#include<bits/stdc++.h>
using namespace std;
#define max 10
//Process Control Block
struct PCB
{
    int PID; // process id
    int BT;  // burst time
    int AT;  // arrival time
    int CT;  // Completion time
    int RT;  // remaining time
    int TAT; // Turn Around Time
    int WT;  // Waiting Time
    int QT;
};
PCB block;//*
vector<PCB> pcb;   // to accept the process
queue<PCB> readyQ; // ready queue
vector<PCB> End;   // ended process
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
int c=1;//Means CPU is free
int n;
int t=0;
int p=0;//Queue Pointer
int qt;
void FCFS(){
    //FCFS Scheduling
    // cout<<"FCFS"<<endl;
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
	  
	    if(t==pcb[p].AT)  {
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
        t++;
        if(c==0){
        block.RT--;
        if(block.RT==0){
        block.CT=t;
        block.TAT=block.CT-block.AT;
        block.WT=block.TAT-block.BT;
        End.push_back(block);
	    c=1;//remove from ready queue as cpu is not nder execution
        }
        }
	  }	
	

	cout<<"\t\tFirst come First serve"<<endl;
    cout<<"PID\t"<<"BT\t"<<"AT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
    
    for(int i=0;i<n;i++){
		
		 cout<<"P"<<End[i].PID<<"\t"<<End[i].BT<<"  \t"<<End[i].AT<<"  \t"<<End[i].CT<<" \t"<<End[i].TAT<<"  \t"<<End[i].WT<<endl;
		
	}
    float waitingtime=0;
	for(int i=0;i<n;i++){
		waitingtime=waitingtime+End[i].WT;
	}
	float tat=0;
	for(int i=0; i<n; i++){
		tat+=End[i].TAT;
	}
	cout<<"\nAverage TAT for FCFS:"<<(float)(tat/n)<<endl;//avg tat
	cout<<"\nAverage Waiting for FCFS:"<<(float)(waitingtime/n)<<endl;//avg wt
}
void SJF(){
    //SJF Scheduling
    // cout<<"SJF"<<endl;
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
	  
	    if(t==pcb[p].AT)  {
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
		    //sort the ready queue according to burst time
            // cout<<"SJF"<<endl;
            vector<PCB>process;
            for(int i=0; i<p; i++){
                process.push_back(readyQ.front());
		        readyQ.pop();
            }
            sort(process.begin(), process.end(), sortbyburst);
            for(int i=0; i<p; i++){
                readyQ.push(process[i]);
                // cout<<"Omkar Patil";
            }
            process.clear();
            block=readyQ.front();
		    readyQ.pop();
			c=0;//CPU is not free
		}
		//calculating ct and wt
        t++;
        if(c==0){
        block.RT--;
            if(block.RT==0){
                block.CT=t;
                // cout<<"Omkar Patil";
                block.TAT=block.CT-block.AT;
                block.WT=block.TAT-block.BT;
                End.push_back(block);
                c=1;//remove from ready queue as cpu is not nder execution
            }
        }
	  }	
	

	cout<<"\t\tShortest Job First"<<endl;
    cout<<"PID\t"<<"BT\t"<<"AT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
    
    for(int i=0;i<n;i++){
		
		 cout<<"P"<<End[i].PID<<"\t"<<End[i].BT<<"  \t"<<End[i].AT<<"  \t"<<End[i].CT<<" \t"<<End[i].TAT<<"  \t"<<End[i].WT<<endl;
		
	}
    float waitingtime=0;
	for(int i=0;i<n;i++){
		waitingtime=waitingtime+End[i].WT;
	}
	float tat=0;
	for(int i=0; i<n; i++){
		tat+=End[i].TAT;
	}
	cout<<"\nAverage TAT for FCFS:"<<(float)(tat/n)<<endl;//avg tat
	cout<<"\nAverage Waiting for FCFS:"<<(float)(waitingtime/n)<<endl;//avg wt
}
void SRTN(){
    //SJF Preamptive (SRTN)
    // cout<<"SRTN"<<endl;
    sort(pcb.begin(), pcb.end(), sortbyarrival);

    while (1)
    {
        if (p == n && readyQ.empty() && c == 1)
        {
            break; // checking condition for Queue, vector and cpu underflow
        }
        while (1)
        {
            // enqueue process inside queue till at matches with actual time
            if (p >= n)
            {
                break; // when all processes in vector are completed
            }
            if (t == pcb[p].AT)
            {
                if (c == 1)
                {
                    //normal process for c==1
                    readyQ.push(pcb[p]);
                    p += 1;
                }
                else
                {
                    // means cpu is under execution
                    if (block.RT > pcb[p].BT)
                    { // shortest process will run
                        readyQ.push(block);
                        block = pcb[p];
                        p++;
                    }
                    else
                    {
                        readyQ.push(pcb[p]);
                        p = p + 1;
                    }
                }
            }
            else
            {
                break;
            }
        }

        // dequeue process from pcb if cpu is free

        // PCB block;//storing variable

        if (c == 1 && !readyQ.empty())
        {
            // sort the ready queue according to burst time
            vector<PCB> process;
            for (int i = 0; i < p; i++)
            {
                process.push_back(readyQ.front());
                readyQ.pop();
            }
            sort(process.begin(), process.end(), sortbyburst);
            for (int i = 0; i < p; i++)
            {
                readyQ.push(process[i]);
            }
            process.clear();
            block = readyQ.front();
            readyQ.pop();
            c = 0; // CPU is not free
        }
        // calculating ct and wt
        t++;
        if (c == 0)
        {
            block.RT--;
            if (block.RT == 0)
            {
                block.CT = t;
                block.TAT = block.CT - block.AT;
                block.WT = block.TAT - block.BT;
                End.push_back(block);
                c = 1; // remove from ready queue as cpu is not nder execution
            }
        }
    }

    cout << "\t\tShortest Remaining Time Next" << endl;
    cout << "PID\t"<< "BT\t"<< "AT\t"<< "CT\t"<< "TAT\t"<< "WT\t" << endl;

    for (int i = 0; i < n; i++)
    {

        cout << "P" << End[i].PID << "\t" << End[i].BT << "  \t" << End[i].AT << "  \t" << End[i].CT << " \t" << End[i].TAT << "  \t" << End[i].WT << endl;
    }
    float waitingtime = 0;
    for (int i = 0; i < n; i++)
    {
        waitingtime = waitingtime + End[i].WT;
    }
    float tat = 0;
    for (int i = 0; i < n; i++)
    {
        tat += End[i].TAT;
    }
    cout << "\nAverage TAT for FCFS:" << (float)(tat / n) << endl;             // avg tat
    cout << "\nAverage Waiting for FCFS:" << (float)(waitingtime / n) << endl; // avg wt
}
void RR(){
    //Round robin Scheduling
    // cout<<"RR"<<endl;
    cout<<"enter quantum time:";
    cin>>qt;
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
}
int main(){
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
    cout<<"\n\nMenu\n1. FCFS\n2. SJF(Non-Preamptive)\n3. SJF(Preamptive)\n4. Round Robin\n5. Exit\n\n";
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
        case 5:{
            cout<<"\nExit satisfied";
        }
        break;
        default:{
            cout<<"\nInvalid Inputs";
        }
    }
    return 0;
}