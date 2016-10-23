#include <iostream>

using namespace::std;

struct linked_list {
	int a;
	linked_list *next, *prev;
}*head=NULL, *tail=NULL, *nl, *sl;

void insert(int x) {
	nl = new linked_list;
	nl->a=x;
	nl->next=NULL;
	if(head==NULL) {
		head=tail=nl;
		head->next=NULL;
	}
	else {
		tail->next=nl;
		tail=nl;
	}
}

int print_linked_list() {
	nl = new linked_list;
	nl=head;
	if(head==NULL) {
		cout<<"\nEmpty linked list!!";
		return 0;
	}
	cout<<"This is the linked list:\n";
	while(nl!=NULL) {
		cout<<nl->a<<" -> ";
		nl=nl->next;
	}
	cout<<"NULL\n";
}

int search_list(int x) {
	nl = new linked_list;
	if(head==NULL) {
		cout<<"\nStack does not contain any elements!!..so search cant be performed!!\n";
	}
	else {
		nl=head;
		while(nl!=NULL) {
			if(nl->a==x) {
				cout<<"\nElement found!!\n";
				return 0;
			}
			nl=nl->next;
		}
		cout<<"\nElement not found!!";
	}
}

int remove(int x) {
	nl = new linked_list;
	if(head==NULL) {
		cout<<"\nThe linked list does not exist so deletion cannot be performed!!\n";
		return 0;
	}
	nl=sl=head;
	if(head->a==x) {
		nl=head;
		head=head->next;
		delete(nl);
	}
	else {
		while(nl!=NULL) {
			if(nl->a==x) {
				sl->next=nl->next;
				delete(nl);
				return 0;
			}
			sl=nl;
			nl=nl->next;
		}
	}
}

int main() {
	char ans='y';
	int n, ele, search, del;
	cout<<"Enter number of elements: ";
	cin>>n;
	for(int i=0; i<n; i++) {
		cout<<"\nEnter next element: ";
		cin>>ele;
		insert(ele);
	}
	print_linked_list();
	cout<<"\nSearch for element?(y-yes) ";
	cin>>ans;
	while(ans=='y' || ans=='Y') {
		cout<<"\nEnter element to be searched for: ";
		cin>>search;
		search_list(search);
		cout<<"\nSearch another element?(y-yes) ";
		cin>>ans;
	}
	cout<<"\nList after searching--> \n";
	print_linked_list();
	cout<<"\nDelete element?(y-yes) ";
	cin>>ans;
	while(ans=='y' || ans=='Y') {
		print_linked_list();
		cout<<"Enter element to be deleted: ";
		cin>>del;
		remove(del);
		print_linked_list();
		cout<<"\nDelete another element?(y-yes) ";
		cin>>ans;
	}
	cout<<"\nList after deletions--> \n";
	print_linked_list();
	return 0;
}
