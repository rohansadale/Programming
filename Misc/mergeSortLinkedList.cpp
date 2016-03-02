// Merge Sort on Linked List

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newNode(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
}

void printList(node *root){
    while(root){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

void split(node *root, node **a, node **b){
    node *slow = root;
    node *fast = root->next;
    
    while(fast){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *a = root;
    *b = slow->next;
    slow->next = NULL;
    
    
}

node *merge(node **a, node **b){
    node *fake = newNode(99);
    node *head = fake;
    
    while(*a && *b){
        if((*a)->data < (*b)->data){
            head->next = *a;
            *a = (*a)->next;
            head = head->next;
        }
        else{
            head->next = *b;
            *b = (*b)->next;
            head = head->next;
        }
    }
    while(*a){
        head->next = *a;
        *a = (*a)->next;
        head = head->next;
    }
    
    while(*b){
        head->next = *b;
        *b = (*b)->next;
        head = head->next;
    }
    
    head = fake->next;
    delete(fake);
    return head;
}

node* mergeSort(node *root){
    if(!root || !root->next)
        return root;
    
    node *a, *b, *headref;
    headref = root;
    
    split(root, &a, &b);

    mergeSort(a);
    mergeSort(b);
    
    headref = merge(&a,&b);
    //printList(headref);
    return headref;
}

int main() {
	
	node *root = newNode(1);
	root->next = newNode(5);
	root->next->next = newNode(3);
	root->next->next->next = newNode(2);
	root->next->next->next->next = newNode(6);
	
	//mergeSort(root);
	printList(mergeSort(root));
	
	
	return 0;
}

// Output 1 2 3 5 6
