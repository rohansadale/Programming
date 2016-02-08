// Lowest Common Ancestor in a Binary Tree


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

node* commonAncestor(node *root, int n1, int n2){
    
    if(!root)
        return NULL;
    
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    node *left = commonAncestor(root->left, n1, n2);
    node *right = commonAncestor(root->right, n1, n2);
    
    if(left && right)
        return root;
    
    return left ? left : right;
}

void preOrder(node *root){
    if(root){
        cout << root->data << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}



int main() {
	//To make insertion simple, elements are inserted as in Binary Search Tree
	insert(12);
	insert(3);
	insert(5);
	insert(1);
	insert(15);
	node *t = commonAncestor(root, 1, 15);
	cout << t->data;
}

// Output - 12
