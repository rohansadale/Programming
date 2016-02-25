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


// For level order printing
void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while(1){
        int c = q.size();
        if(c == 0)
            break;
            
        while(c > 0){
            node *t = q.front();;
            cout << t->data << " ";
        
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
            
            q.pop();    
            c--;
        }
        cout << endl;
    }
}

node* mirror(node *root){
    if(!root)
        return NULL;
    
    node *left = mirror(root->left);
    node *right = mirror(root->right);
    
    root->left = right;
    root->right = left;
    return root;
}


int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	cout << "Before - \n";
	levelOrder(root);
	
	cout << "\nAfter - \n";
	levelOrder(mirror(root));
	return 0;
}

/*
Output - 

Before - 
1 
2 5 
3 4 

After - 
1 
5 2 
4 3 

*/
