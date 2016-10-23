#include <iostream>

using namespace::std;

struct queue {
	int a;
	queue *next;
}*head=NULL, *tail=NULL, *np=NULL;

void enqueue(int x) {
	np = new queue;
	np->a = x;
	if(head==NULL) {
		head=tail=np;
		tail->next=NULL;
	}
	else {
		tail->next=np;
		tail=np;
		tail->next=NULL; 
	}
}

void dequeue() {
	queue *n = new queue;
	if(head==NULL) {
		cout<<"Underflow";
	}
	else {
		n=head;
		head=head->next;
		delete(n);
		cout<<"Element deleted: "<<n->a;
	}
}

int print_queue() {
	if(head==NULL) {
		cout<<"Empty queue";
		return 0;
	}
	queue *n = head;
	cout<<"\nThe queue is: ";
	while(n!=NULL) {
		cout<<n->a<<" ";
		n=n->next;
	}
	return 0;
}

int main() {
	char ans='y';
	int n, ele;
	cout<<"Enter number of elements to insert: ";
	cin>>n;
	for(int i=0; i<n; i++) {
		cout<<"\nEnter the element: ";
		cin>>ele;
		enqueue(ele);
	}
	print_queue();
	cout<<"\n"<<"Want to dequeue element? ";
	cin>>ans;
	while(ans=='y' || ans=='Y') {
		dequeue();
		print_queue();
		cout<<"\n"<<"Want to dequeue another element? ";
		cin>>ans;
	}
	cout<<"\nFinal-->";
	print_queue();
	return 0;
}
