#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Destructor Called and Deleted : "<<value<<endl;;
    }
};

//traversing LL
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//finding length of LL
int getLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &head,Node* &tail,int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    //if inserting at index 1
    if (position == 1)
    {
        insertAtHead(head,tail,data);
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
        insertAtTail(head,tail,data);
        return;
    }

    //Creating node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert ->next = temp ->next;
    temp ->next -> prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(Node* &head,Node* &tail,int position)
{
    if (position == 1)
    {
        Node* temp = head;
        temp -> next ->prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }

    else
    {
        Node* curr = head;
        Node* pre = NULL;

        int count = 1;
        while (count < position)
        {
            pre = curr;
            curr = curr -> next;
            count++;
        }
        curr->prev = NULL;
        pre ->next = curr -> next;
        curr ->next = NULL;
        if (pre->next == NULL)
        {
            tail=pre;
        }
        delete curr;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    //cout<<"Value in Head : ";
    print(head);
    //cout<<"Length Of Linked List : "<<getLength(head);    
    insertAtHead(head,tail,9);
    print(head);
    insertAtTail(head,tail,12);
    print(head);
    //cout<<"Head : "<<head->data<<endl;
    //cout<<"Tail : "<<tail->data<<endl;
    insertAtPosition(head,tail,3,11);
    print(head);
    deleteNode(head,tail,4);
    print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    return 0;
}



//If list is empty

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

//traversing LL
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//finding length of LL
int getLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data)
{
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data)
{
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    //if inserting at index 1
    if (position == 1)
    {
        insertAtHead(head,tail,data);
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
        insertAtTail(head,tail,data);
        return;
    }

    //Creating node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert ->next = temp ->next;
    temp ->next -> prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    //cout<<"Value in Head : ";
    print(head);
    //cout<<"Length Of Linked List : "<<getLength(head);    
    insertAtHead(head,tail,9);
    print(head);
    insertAtTail(head,tail,11);
    print(head);
    //cout<<"Head : "<<head->data<<endl;
    //cout<<"Tail : "<<tail->data<<endl;
    insertAtPosition(head,tail,2,10);
    print(head);
    return 0;
}
