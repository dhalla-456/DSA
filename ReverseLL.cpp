#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail,int data)
{
    //creating new Node for New data
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp -> data <<" " ;
        temp = temp ->next;
    }
    cout<<endl;
}

Node* reverse1(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    print(prev);
    return prev;
}

//by recursion 
Node* reverse2(Node* head)
{
    //base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* chotaHead = reverse2(head->next);
    head -> next -> next = head;
    head -> next = NULL;
    print(chotaHead);
    return chotaHead;
}

//code used in Codetudio
void reverse3(Node* head,Node* curr,Node* &prev)
{
    //base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse3(head,forward,curr);
    curr -> next = prev;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    print(head);
    cout<<"Reverse1 : "<<reverse1(head);
    
    cout<<"Reverse2 : "<<reverse2(head);
  
    return 0;
}
