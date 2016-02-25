// Delete Binary Tree

#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *newNode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void deleteTree(node *root){
    if(!root)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    
    cout << "Deleting " << root->data << endl;
    free(root);
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	deleteTree(root);
	
	return 0;
}

/*
Output -

Deleting 3
Deleting 4
Deleting 2
Deleting 5
Deleting 1

*/
