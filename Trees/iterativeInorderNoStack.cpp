// Inorder Traversal without stack

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

void inOrder(node *root){
    if(!root)
        return;
    
    node *current = root;
    while(current){
        if(!current->left){
            cout << current->data << " ";
            current = current->right;
        }
        else{
            node *pre = current->left;
            while(pre->right && pre->right != current){
                pre = pre->right;
            }
            
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	inOrder(root);
	return 0;
}

// Output - 3 2 4 1 5 
