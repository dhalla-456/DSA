// Node* kReverse(Node* head,int k)
// {
//     //base call
//     if (head== NULL)
//     {
//         return NULL;
//     }

//     //Reverse the first k Nodes
//     Node* next = NULL;
//     Node* prev = NULL;
//     Node* curr = head;

//     int cnt = 0;

//     while (curr != NULL && cnt < k)
//     {
//         next = curr->next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;

//         cnt++;
//     }
    
//     //step 2 : recursion dekhlega aage
//     if (next != NULL)
//     {
//         head -> next = kreverse(next,k);
//     }

//     //step 3 return head of reversed list
//     return prev;
    
// }

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
        int value = this ->data;
        //free kr rhe h memory
        if(this ->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory Free KrDi Gyi Hai"<<endl;
    }
};

void print(Node* head,int n)
{
    Node* temp = head;
    int cnt = 0;
    while (temp != NULL && cnt < n)
    {
        cout<< temp -> data <<" " ;
        temp = temp ->next;
        cnt++;
    }
    cout<<endl;
    return;
}

void insertAtTail(Node* &tail,int data)
{
    //creating new Node for New data
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

Node* kReverse(Node* head,int k)
{
    //base call
    if (head == NULL)
    {
        return NULL;
        //cout<<"NULL";
    }

    //Reverse the first k Nodes
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;

    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;

        cnt++;
    }
    
    //step 2 : recursion dekhlega aage
    if (next != NULL)
    {
        head -> next = kReverse(next,k);
    }

    //step 3 return head of reversed list
    return prev;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    int k = 2;
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    Node* pre = kReverse(head,k);
    print(pre,4);
    //delete(Node* (pre));
    return 0;
}