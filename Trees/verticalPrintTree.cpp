/*
Print Binary Tree in vertical Order

Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
              
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void findMinMax(Node *root, int *min, int *max, int hd){
    if(!root)
        return;
    
    if (*min > hd)
        *min = hd;
    else if(*max < hd)
        *max = hd;
    
    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->right, min, max, hd+1);
}

void printVerticalLine(Node *root, int level, int hd){
    if(!root)
        return;
    if(level == hd){
        cout << root->data << " ";
        // If below return is uncommented, top view of tree would be shown.
        //return;
    }
    printVerticalLine(root->left, level, hd-1);
    printVerticalLine(root->right, level, hd+1);
}

void maxDistance(Node *root){
    int min = 0;
    int max = 0;
    
    findMinMax(root, &min, &max, 0);
    
    for(int i = min; i <= max; i++){
        printVerticalLine(root, i, 0);
        cout << endl;
    }
    //cout << min << " " << max;
}

int main() {

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    
    maxDistance(root);
    return 0;
}

/*
Output
4 
2 
1 5 6 
3 8 
7 
9 

*/