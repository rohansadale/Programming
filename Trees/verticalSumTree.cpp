/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. 
Print all sums through different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
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

void printVerticalLine(Node *root, int level, int hd, int *sum){
    if(!root)
        return;
    if(level == hd){
        *sum = *sum + root->data;
        //cout << root->data << " ";
        //return;
    }
    printVerticalLine(root->left, level, hd-1, sum);
    printVerticalLine(root->right, level, hd+1, sum);
}

void maxDistance(Node *root){
    int min = 0;
    int max = 0;
    
    findMinMax(root, &min, &max, 0);
    
    for(int i = min; i <= max; i++){
        int sum = 0;
        printVerticalLine(root, i, 0, &sum);
        cout << sum << endl;
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
Output -
4
2
12
11
7
9
*/