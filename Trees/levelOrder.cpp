// Level Order Tree Traversal

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

void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *t = q.front();;
        cout << t->data << " ";
        
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
            
        q.pop();    
    }
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	levelOrder(root);
	return 0;
}

// Output - 1 2 5 3 4 