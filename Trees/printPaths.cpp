// Print all paths in Binary Tree

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

void print(vector<int> &v, int len){
    for(int i = 0; i < len ; i++)
        cout << v[i] << " ";
    cout << endl;
}

void printPaths(node *root, vector<int> v, int len){
    v.push_back(root->data);
    len++;
    
    if(!root->left && !root->right)
        print(v, len);
    else{
        printPaths(root->left, v, len);
        printPaths(root->right, v, len);
    }
}

int main() {
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	
	vector<int> v;
	printPaths(root, v, 0);
	return 0;
}

/*

Output
1 2 3 
1 2 4 
1 5 

*/
