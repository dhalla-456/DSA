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
    ~Node(){
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Destrcutor Called For Value : " << value << endl;
    }
};

void insert(Node* &tail,int element,int data) 
{
    //for empty list
    if (tail == NULL)
    {
        Node* node1 = new Node(data);
        tail = node1;
        node1 ->next = node1;
    }

    //for list with element
    else
    {
        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        //element found at curr
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
    
    
}

void print(Node* &tail)
{
    Node* temp = tail;
    
    //Empty List
    // if(tail == NULL)
    // {
    //     cout<<"List is empty"<<endl;
    //     return;
    // }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while (tail != temp);
    cout<<endl;
    
}

void deleteNode(Node* &tail,int value)
{
    //if LL is Empty
    if(tail == NULL)
    {
        cout<<"List Is Empty Already"<<endl;
        return;
    }

    //NON - EMPTY LL
    Node* prev = tail;
    Node* curr = prev->next;

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;

    //Only 1 Node is Present in LL
    if (curr = prev)
    {
        tail = NULL;
    }

    //When LL has More Than 1 Node
    else if (tail = curr)
    {
        tail = prev;
    }
    
    curr->next = NULL;
    delete curr;

}

int main()
{
    Node* tail = NULL;
    insert(tail,0,3);
    print(tail);
    insert(tail,3,4);
    print(tail);
    insert(tail,4,5);
    print(tail);
    insert(tail,5,6);
    print(tail);
    deleteNode(tail,4);
    print(tail);
    return 0;
}