// Program to check whether binary trees are identical.

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

bool identical(node *root1, node *root2){
    if(!root1 && !root2)
        return true;
    
    if(!root1 || !root2 )
        return false;
    
    if(root1->data == root2->data)
        return identical(root1->left, root2->left) && identical(root1->right,
    root2->right);
    
    return false;

}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->left->left = newNode(3);
	root1->left->right = newNode(4);
	root1->right = newNode(5);
	if (identical(root, root1))
	  cout << "Identical";
	else
	  cout << "Not Identical";
	
	return 0;
}

// Output 
