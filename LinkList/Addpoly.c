#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int c, e;
	struct node*next;
}node;
typedef struct LL{
	node*start;
}LL;
/*To Insert elements at the end.*/
void insertend(LL*l, int cc, int ee){
	node*newrec, *p;
	newrec=(node*)malloc(sizeof(node));
	newrec->c=cc;
	newrec->e=ee;
	newrec->next=NULL;
	if(l->start==NULL){
		l->start=newrec;
	}
	else{
		p=l->start;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=newrec;
	}
}
/*To accept number of terms, coiffeint as well ass their exponent. */
void read(LL*l){
	int i, n, cc, ee;
	printf("\nEnter the number of terms:");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\nEnter the coiefficent and exponent:");
		scanf("%d%d", &cc, &ee);
		insertend(l, cc, ee);
	}
}
/*To display*/
void display(LL*l){
	node*p;
	if(l->start==NULL){
		printf("\nLinked list is empty.");
	}
	else{
		p=l->start;
		while(p!=NULL){
			printf("%dX^%d ", p->c, p->e);
			p=p->next;
		}
	}
}
/*To add two polynomial*/
void add(LL*l1, LL*l2, LL*l3){
	node*p, *q;
	p=l1->start;
	q=l2->start;
	while(p!=NULL&&q!=NULL){
		if(p->e>q->e){
			insertend(l3, p->c, p->e);
			p=p->next;
		}
		else if(q->e>p->e){
			insertend(l3, q->c, q->e);
			p=p->next;
		}
		else{
			insertend(l3, p->c+q->c, p->e);
			p=p->next;
			q=q->next;
		}
	}
	while(p!=NULL){
		insertend(l3, p->c, p->e);
		p=p->next;
	}
	while(q!=NULL){
		insertend(l3, q->c, q->e);
		p=p->next;
	}
}
int main(){
	LL l1, l2, l3;
	l1.start=NULL;
	l2.start=NULL;
	l3.start=NULL;
	read(&l1);
	read(&l2);
	add(&l1, &l2, &l3);
	display(&l1);
	display(&l2);
	printf("\n");
	display(&l3);
	return 0;
}
