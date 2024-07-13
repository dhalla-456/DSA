#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


//Approach 1 : traversing complete LL and counting the numbers of 0,1,2 
// TC : O(n) SC: O(1)
Node* Sort1(Node* head)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            one++;
        }
        else if(temp->data == 2)
        {
            two++;
        }
        
        temp = temp -> next;
    }
    
    temp = head;
    while (temp != NULL)
    {
        if(zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if(one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if(two != 0)
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }

    return head; //head of new sorted LL
    
}

//Approach 2 : create 3 separate LL for 0,1,2 and insert value traversing original LL and then merge them
// TC : O(n) SC: O(1)

void insertAtTail(Node* &tail,Node* curr)
{
    //creating new Node for New data
    Node* temp = new Node(curr->data);
    tail -> next = temp;
    tail = temp;
}

Node* Sort2(Node* head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail,curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail,curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail,curr);
        }
        
        curr = curr->next;
        
    }

    //merging 3 subLL

    if(oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setuping Head
    head = zeroHead->next;

    //delete Dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}