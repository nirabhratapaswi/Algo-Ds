#include <iostream>

using namespace::std;

struct node {
	int  key, height;
	node *left;
	node *right;
}*root;


node *newNode(int key) {
    // cout << "newNode called\n";
    node *tree = new node;
    tree->key = key;
    tree->height = 1;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int height (node *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->height;
}

int maxHeight (node *tree1, node *tree2) {
    if (height(tree1) > height(tree2)) {
        return tree1->height;
    }
    else {
        return tree2->height;
    }
}

int max (int a, int b) {
	return (a > b)? a : b;
}

node *rotateRight(node *treeNode) {
	cout << "right rotation called for node: " << treeNode->key << "\n";
	node *currentLeft = treeNode->left;
	node *lowerRight = currentLeft->right;

	currentLeft->right = treeNode;
	treeNode->left = lowerRight;

	currentLeft->height = max(height(currentLeft->left), height(currentLeft->right)) + 1;
	treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;

	return currentLeft;
}

node *rotateLeft(node *treeNode) {
	cout << "left rotation called for node: " << treeNode->key << "\n";
	node *currentRight = treeNode->right;
	node *lowerLeft = currentRight->left;

	currentRight->left = treeNode;
	treeNode->right = lowerLeft;

	currentRight->height = max(height(currentRight->left), height(currentRight->right)) + 1;
	treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;
	
	return currentRight;
}

node *insertNode (node *tree, int key) {
    // cout << "insertNode called\n";
    if (tree == NULL) {
        // cout << "root was NULL\n";
        return newNode(key);
    }
    else if (key < tree->key) {
        tree->left = insertNode(tree->left, key);
    }
    else if (key > tree->key) {
        tree->right = insertNode(tree->right, key);
    }
    else {
        return tree;
    }

    tree->height = 1 + max(height(tree->left), height(tree->right));

    int balance = height(tree->left) - height(tree->right);
	cout << "Tree key: " << tree->key << ", height: " << tree->height << ", balance: " << balance << "\n";

    if (balance > 1 && key < tree->left->key) {
    	cout << "Left Left\n";
    	return rotateRight(tree);
    }
    else if (balance < -1 && key > tree->right->key) {
    	cout << "Right Right\n";
    	return rotateLeft(tree);
    }
    else if (balance > 1 && key > tree->left->key) {
    	cout << "Left Right\n";
    	tree->left = rotateLeft(tree->left);
    	return rotateRight(tree);
    }
    else if (balance < -1 && key < tree->right->key) {
    	cout << "Right Left\n";
    	tree->right = rotateRight(tree->right);
    	return rotateLeft(tree);
    }

    return tree;
}

void printTree (node *tree) {
	if (tree != NULL) {
		cout << tree->key << "\n";
		printTree(tree->left);
		printTree(tree->right);
	}
}

int main () {
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 16);
    root = insertNode(root, 12);
    root = insertNode(root, 15);
    root = insertNode(root, 14);
    root = insertNode(root, 21);
    cout << "\nRoot key: " << root->key << " : " << root->height << "\n";
    cout << "\nThe final tree traversal:\n";
    printTree(root);
    return 0;
}
