// Number of elements in a Binary Tree

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

int size(node *root){
    if(!root)
        return 0;
    else
        return 1 + size(root->left) + size(root->right);
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	cout << size(root);
	return 0;
}

// Output - 5
