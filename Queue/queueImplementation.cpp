#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node *next;
};

class Queue{
    private:
        node *front;
        node *rear;
	int n;
    public:
        Queue();
        void enqueue(int);
        void dequeue();
        void display();
	int size();
};

Queue::Queue(){    
    front = NULL;
    rear = NULL;  
    n = 0;  
}

void Queue::enqueue(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    
    if(!front){
        front = temp;
    }
    else{
        rear->next = temp;
    }
    rear = temp;
    n++;
}

void Queue::dequeue(){
    node *temp = front;
    front = front->next;
    delete(temp);
    n--;
}

void Queue::display(){
    node *t = front;
    while(t){
        cout << t->data << " "; 
        t = t->next;
    }
    cout << endl;
}

int Queue::size(){
	return n;
}

int main()
{
    Queue q;
    vector<int>data = {5, 3, 4, 8, 6, 7};
    cout << "Queue Created \n";
    for(auto i = 0; i < data.size(); i++){
        q.enqueue(data[i]);
    }
    q.display();
    
    cout << "Queue contents after some deletions \n";
    for(auto i = 1; i < 3; i++){
        q.dequeue();
    }
    q.display();

    cout << "Size = " << q.size() << endl;    

    return 0;
}

/*
Output
Queue Created 
5 3 4 8 6 7 
Queue contents after some deletions 
4 8 6 7 
*/
