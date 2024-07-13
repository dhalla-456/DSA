#include<iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node* head)
{
     while(head)
    {
        cout<< head->data << " ";
        head= head->next;
    }
    cout<< endl;
}

void insertAtTail(Node* &head,Node* &tail ,int val)
{
    Node* temp = new Node(val);
    //when LL is Empty
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node* cloneLL(Node* head)
{
    //Approch 1:
    
    //creating a clone list and coying next  simple values to it
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp -> next;
    }

    //creating map to store linking of original and clone list

    unordered_map<Node*,Node*> oldToNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode)
    {
        cloneNode -> random = oldToNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    
    return cloneHead;
    

   //Approach 2 :

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while (temp)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp -> next;
    }

    
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            Node* Next = originalNode -> next;
            originalNode ->next = cloneNode;
            originalNode = Next;

            Next = cloneNode ->next;
            cloneNode -> next = originalNode;
            cloneNode = Next; 
        }

        Node* temp = head;

        while (temp)
        {
            if (temp ->next != NULL)
            {
                if (temp -> random != NULL)
                {
                    temp -> next -> random = temp ->random ->next;
                }
                
                else
                {
                    temp ->next = temp -> random;
                }
                
            }
            
        }
        //revert changes made in step 2
        originalNode = head;
        cloneHead = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode -> next = cloneNode -> next ;
            originalNode = originalNode -> next;

            if(originalNode != NULL)
                cloneNode ->next = originalNode ->next;
        
            cloneNode = cloneNode -> next;
        }
        
    return cloneHead;
    
}



int main()
{
    cout<<"Hello World";
    return 0;
}