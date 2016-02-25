#include <iostream>
#include <queue>
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

void increment(node *root, int diff){
    if(root->left){
        root->left->data = root->left->data + diff;
        increment(root->left, diff);   
    }
    else if(root->right){
        root->right->data = root->right->data + diff;
        increment(root->right, diff);
    }
}

void childrenSum(node *root){
    if(!root)
        return;
    else{
        childrenSum(root->left);
        childrenSum(root->right);
        
        int left = 0;
        int right = 0;
        
        if(root->left)
            left = root->left->data;
        if(root->right)
            right = root->right->data;
            
        int diff = left + right - root->data;
        
        if(diff > 0)
            root->data = left + right;
        else
            increment(root, -diff);
    }
}

void inorder(node *root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }    
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	cout << "Before - \n";
	inorder(root);
	childrenSum(root);
	cout << "\nAfter -" << endl;
	inorder(root);
	
	return 0;
}

/*
Output - 
Before - 
3 2 4 1 5 
After -
3 7 4 12 5 
*/
