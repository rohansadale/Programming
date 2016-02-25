// Iterative Inorder Traversal

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
    stack<node*> s;
    node *current = root;
    while(1){
        while(current){
            s.push(current);
            current = current->left;
        }
        
        if(s.empty())
            break;
        
        if(!current){
            node *t = s.top();
            cout << t->data << " ";
        
            s.pop();
            current = t->right;
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

// Output 3 2 4 1 5 
