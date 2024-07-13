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

void insertAtTail(Node* &tail,int data)
{
    //creating new Node for New data
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

int getlength(Node* head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head -> next;
    }
    return len;
}

//Approach 1
int findMiddle(Node* head)
{
    int length = getlength(head);
    int ans = (length/2);
    Node* temp = head;
    int count = 0;
    while (count < ans)
    {
        temp = temp -> next;
        count++;
    }
    return temp->data;
}

//Approach 2

int getMiddle(Node* &head)
{
    //if list is empty or only have 1 element
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }

    //if LL have 2 element
    if (head->next->next == NULL)
    {
        return head->next;
    }
    
    Node* fast = head->next;
    Node* slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;
}

int main(int argc, char const *argv[])
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    print(head);
    cout<<"Length of the List : "<< getlength(head)<<endl;
  //cout<<"Middle Element of the List is : "<< findMiddle(head) << endl;
    cout<<"Middle Element of the List is : "<< getMiddle(head)  << endl;
    return 0;
}
    