// Binary Search Tree Implementation

#include <iostream>
using namespace std;


struct node{
    int data;
    node *left;
    node *right;
};

node *root;

void insert(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    if(!root){
        root = temp;
        return;
    }
    
    node *current = root;
    node *prev = NULL;
    
    while(current){
        prev = current;
        if(current->data < data)
            current = current->right;
        else
            current = current->left;
    }
    
    if(prev->data < data){
        prev->right = temp;
    }
    else{
        prev->left = temp;
    }
    return;
}

void preOrder(node *root){
    if(root){
        cout << root->data << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int height(node *root){
    if(!root)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}

int main() {
	//code
	insert(12);
	insert(3);
	insert(5);
	insert(1);
	insert(15);
	node *t = root;
	cout << "PreOrder Traversal \n";
	preOrder(t);
	
	cout << "Height of Tree = ";
	cout << height(t) << endl;
	return 0;
}

/*
Output
PreOrder Traversal 
12
3
1
5
15
Height of Tree = 3
*/
