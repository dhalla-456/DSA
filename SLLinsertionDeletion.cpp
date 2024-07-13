#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //consructer
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
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

void insertAtHead(Node* &head,int data) //used reference operator & kyoki hum nyi copy ni bana chate
{
    //creating new Node for New data
    Node* temp = new Node(data);

    temp ->next = head;
    head = temp;

}

void insertAtTail(Node* &tail,int data)
{
    //creating new Node for New data
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{   
    //if inserting at index 1
    if (position == 1)
    {
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position-1)
    {
        temp = temp ->next;
        count++;
    }

    //inserting at last index or position
    if (temp -> next  == NULL)
    {
        insertAtTail(tail,data);
        return;
    }

    //Creating node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert ->next = temp ->next;
    temp ->next = nodeToInsert;
    
}

void deleteNode(Node* &head,Node* &tail,int position)
{
    Node*temp = head;
    //For deleting first Node as previous element doesnot exist 
    if(position == 1)
    {
        head = head -> next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        //deleting last or middle Node
        Node* curr = head;
        Node* prev = NULL;
        
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;  
        }

        prev ->next = curr ->next;
        curr ->next = NULL;
        if (prev->next == NULL)
        {
            tail=prev;
        }
        
        delete curr;

    }
}

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp -> data <<" " ;
        temp = temp ->next;
    }
    cout<<endl;
    
}

int main()
{
    Node* node1 = new Node(10);
    // cout<< node1-> data << endl;
    // cout<< node1-> next << endl;
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head,9);
    print(head);
    insertAtTail(tail,11);
    print(head);
    insertAtPosition(head,tail,4,12);
    print(head);
    cout<<endl;
    cout<< head -> data << endl;
    cout<< tail ->data << endl;
    cout<<endl;
    deleteNode(head,tail,4);
    print(head);
    cout<<endl;
    cout<< head -> data << endl;
    cout<< tail ->data << endl;
    return 0;
}
