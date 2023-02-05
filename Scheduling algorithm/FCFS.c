//First comes First Serves Scheduling Algorithm
#include<stdio.h>
#include<stdlib.h>
//node => process
typdef struct node{
    int PID;
    int AT;
    int BT;
    int CT;
    struct node*next;
};
typedef struct LL{
    node*start;
}LL;
//Let us add process in the queue made using linklist
void ProcessQueue(LL*l, int pid, int at, int bt){
    node*newrec, *p;
    newrec = (node*)malloc(sizeof(node));
    newrec->PID = pid;
    newrec->at = AT;
    newrec->bt = BT;
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