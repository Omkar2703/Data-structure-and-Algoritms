#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}node;
typedef struct LL{
	node*start;	
}LL;
void push(LL*l, int ele){
	node*newrec, *p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	newrec->next=l->start;
	l->start=newrec;
}
int pop(LL*l){
	node*p;
	if(l->start==NULL){
		return -1;
	}
	else{
		p=l->start;
		l->start=p->next;
		return p->data;
	}
}
int top(LL*l){
	node*p;
	if(l->start==NULL){
		return -1;
	}
	else{
		return l->start->data;
	}
}
void display(LL*l){
	node*p;
	if(l->start==NULL){
		printf("\nLinked list is Empty.");
	}
	else{
		p=l->start;
		while(p!=NULL){
			printf("\n%d", p->data);
			p=p->next;
		}
		printf("\n");
	}
}
int main(){
	LL l;
	l.start=NULL;
	int ch, ele;
	while(1){
		printf("\nMENU\n1. PUSH\n2. POP\n3. STACKTOP\n4. DISPLAY\n5. EXIT.\n");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		if(ch==5){
			break;
		}
		switch(ch){
			case 1:{
				printf("\nEnter the element:");
				scanf("%d", &ele);
				push(&l, ele);
			}
			break;
			case 2:{
				ele=pop(&l);
				if(ele==-1){
					printf("\nLinked list is empty.");
				}
				else{
					printf("\n%d is Poped.", ele);
				}
			}
			break;
			case 3:{
				ele=top(&l);
				if(ele==-1){
					printf("\nLinked list is empty.");
				}
				else{
					printf("\n%d is at Top.", ele);
				}
			}
			break;
			case 4:{
				display(&l);
			}
			break;
			default:{
				printf("\nInvalid choice.");
			}
			break;
		}
	}
	return 0;
}
