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

int deleteNode (node *tree, int key) {
	node *prevNode = new node;
	bool left = true;
	if (tree == NULL) {
		cout << "Tree is empty!!\n";
		return 0;
	}
	while (true) {
		cout << "Key: " << tree->id << endl;
		if (tree == NULL) {
			cout << "Key not found!!\n";
			break;
		}

		else if (tree->id == key) {

			if (tree->left == NULL && tree->right == NULL) {
				cout << "Both children are NULL\n";
				delete tree;
				if (left) {
					prevNode->left = NULL;
				}
				else {
					prevNode->right = NULL;
				}
			}
			else if ((tree->left == NULL && tree->right != NULL) || (tree->left != NULL && tree->right == NULL)) {
				cout << "One children is NULL-";
				if (tree->left == NULL) {
					cout << "-left-";
					if (left) {
						cout << "-1-";
						prevNode->left = tree->right;
					}
					else {
						cout << "-2-";
						prevNode->right = tree->right;
					}
				}
				else {
					cout << "-right-";
					if(left) {
						cout << "-1-";
						prevNode->left = tree->left;
					}
					else {
						cout << "-2-";
						prevNode->right = tree->left;
					}
				}
				delete tree;
			}
			else {
				cout << "Both children not NULL-";
				node *newPrevNode = new node;
				prevNode = tree;
				newPrevNode = tree;
				tree = tree->right;
				cout << "\n#start tree value: " << tree->id << "\n";
				while (true) {
					if (tree->left == NULL) {
						cout << "##tree value: " << tree->id << "##\n";
						if (tree->right != NULL) {
							cout << "-1\n";
							if (newPrevNode == prevNode) {
								newPrevNode->right = tree->right;
							}
							else {
								newPrevNode->left = tree->right;
							}
						}
						else {
							cout << "-2\n";
							if (newPrevNode == prevNode) {
								newPrevNode->right = NULL;
							}
							else {
								newPrevNode->left = NULL;
							}
						}
						prevNode->id = tree->id;
						delete tree;
						break;
					}
					newPrevNode = tree;
					tree = tree->left;
				}
			}
			break;

		}

		prevNode = tree;
		if (key < tree->id) {
			tree = tree->left;
			left = true;
			continue;
		}
		else {
			tree = tree->right;
			left = false;
			continue;
		}
	}
}

int main() {
        cout<<endl<<"0 5 2 3 1"<<endl;
	insert(0);
	insert(20);
	insert(10);
	insert(4);
	insert(2);
	insert(17);
	insert(14);
	insert(12);
	insert(19);
	printTree(root);
	deleteNode(root, 10);
	printTree(root);
	return 0;
}
