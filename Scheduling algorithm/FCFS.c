//First comes First Serves Scheduling Algorithm
#include<stdio.h>
#include<stdlib.h>
//node => process
typedef struct node
{
    int PID, AT, BT;
    struct node*next;
}node;
typedef struct LL{
    node*start;
}LL;
//Let us add process in the queue made using linklist
void ProcessQueue(LL*l, int pid, int at, int bt){
    node*newrec, *p;
    newrec = (node*)malloc(sizeof(node));
    newrec->PID = pid;
    newrec->AT = at;
    newrec->BT = bt;
    newrec->next=NULL;
    if(l->start==NULL)
	{
		l->start=newrec;
	}
	else
	{
		p=l->start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newrec;
	} 
}
void display(LL*l)//Displays all Processes present in Queue.
{
    node*p;
    if(l->start==NULL)
    {
        printf("\nNo Process");
    }
    else
    {
        p=l->start;
        while(p!=NULL)
        {
            printf("\nProcess_ID: %d\t", p->PID);
            printf("Arrival_Time: %d\t", p->AT);
            printf("Burst_Time: %d\t\n", p->BT);
            p=p->next;
        }
        printf("\n");
    }
}
int main(){
    LL l;
    l.start=NULL;
    int pid, at, bt, ct, n, i;
    // ProcessQueue(&l, 1, 6, 1);
    // ProcessQueue(&l, 2, 8, 1);
    // ProcessQueue(&l, 4, 3, 3);
    printf("\nEnter the number of process: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nEnter the process Id, Arrival Time, Burst Time: ");
		scanf("%d%d%d", &pid, &at, &bt);
		ProcessQueue(&l, pid, at, bt);
	}
    display(&l);
    return 0;
}