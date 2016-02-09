/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(!headA)
        return headB;
    if(!headB)
        return headA;    
    
    Node *fake = new Node();
    Node *p = fake;
    
    while(headA && headB){
        if(headA->data < headB->data){
            p->next = headA;
            headA = headA->next;
            p = p->next;
        }
        else{
            p->next = headB;
            headB = headB->next;
            p = p->next;
        }
    }
    while(headA){
        p->next = headA;
        headA = headA->next;
        p = p->next;
    }
    
    while(headB){
        p->next = headB;
        headB = headB->next;
        p = p->next;
    }
    
    return fake->next;
}
