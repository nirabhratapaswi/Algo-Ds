#include <iostream>

using namespace::std;

struct stack {
	int a;
	stack *next;
}*top=NULL, *st=NULL;

void push(int x) {
	st = new stack;
	st->a=x;
	if(top==NULL) {
		top=st;
		top->next=NULL;
	}
	else {
		st->next=top;
		top=st;
	}
}

void pop() {
	st = new stack;
	if(top==NULL) {
		cout<<"\nUnderflow!!";
	}
	else {
		st=top;
		top=top->next;
		cout<<"\nElement deleted: "<<st->a;
		delete(st);
	}
}

int print_stack() {
	if(top==NULL) {
		cout<<"\nEmpty stack!!";
		return 0;
	}
	st=top;
	cout<<"\nThis is the stack:\n";
	while(st!=NULL) {
		cout<<st->a<<"\n";
		st=st->next;
	}
	cout<<"\n";
}

int main() {
	char ans='y';
	int n, ele;
	cout<<"Enter number of elements to insert: ";
	cin>>n;
	for(int i=0; i<n; i++) {
		cout<<"\nEnter next element: ";
		cin>>ele;
		push(ele);
	}
	print_stack();
	cout<<"\nPop element? ";
	cin>>ans;
	while(ans=='y' || ans=='Y') {
		pop();
		print_stack();
		cout<<"\nPop another element? :";
		cin>>ans;
	}
	cout<<"\nFinal--> ";
	print_stack();
	return 0;
}
