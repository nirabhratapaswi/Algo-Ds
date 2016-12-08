#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace::std;

struct node {
	int id;
	node *left, *right;
}*tree, *root;

int insert(int key) {
	if(root == NULL) {
		// cout<<"Root inserted!!\n";
		tree = new node;
		root = new node;
		tree->id = key;
		tree->left = NULL;
		tree->right = NULL;
		root = tree;
		return 0;
	}
	
	if(tree->id == key) {
		return 0;
	}	

	if(tree->id > key) {
		// cout<<"leftUpper, "<<key<<"\n";
		if(tree->left == NULL) {
			node *temp = new node;
			temp->id = key;
			temp->left = NULL;
                        temp->right = NULL;
			tree->left = temp;
			tree = root;
			// cout<<"Tree key after insertion: "<<tree->id<<endl;
			return 0;
		}
		else {
			// cout<<"left, "<<key<<"\n";
			tree = tree->left;
			insert(key);
		}
	}
	else if(tree->id < key) {
		// cout<<"rightUpper, "<<key<<"\n";
		if(tree->right == NULL) {
                        node *temp = new node;
                        temp->id = key;
			temp->left = NULL;
			temp->right = NULL;
                        tree->right = temp;
                        tree = root;
			// cout<<"Tree key after insertion: "<<tree->id<<endl;
                        return 0;
                }
                else {
                        // cout<<"right, "<<key<<"\n";
                        tree = tree->right;
                        insert(key);
                }
	}
}

void printTree(node *tree) {
	if(tree->left != NULL) {
		printTree(tree->left);
	}
	cout<<endl<<tree->id<<" ";
	if(tree->right != NULL) {
		printTree(tree->right);
	}
}

int main() {
        // cout<<endl<<"1 5 2 3 4"<<endl;
	insert(1);
	insert(5);
	insert(2);
	insert(3);
	insert(4);
	insert(4);
	insert(1);
	insert(3);
	printTree(root);
	return 0;
}
