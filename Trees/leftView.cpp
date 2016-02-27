// Left View of Tree

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewUtil(node *root, int level, int *maxLevel){
    if(!root)
        return;
    
    if(*maxLevel < level){
        cout << root->data << endl;
        *maxLevel = level;
    }
    
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);
}

void leftView(node *root){
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
}

// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    leftView(root);
 
    return 0;
}

/*
Output - 
12
10
25
*/
