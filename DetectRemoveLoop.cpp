#include<iostream>
#include<map>
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

void insertAtTail(Node* &tail,int data)
{
    //creating new Node for New data
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
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

Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow = fast)
            return slow;
    }
}

Node* getStartNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);

    if(intersection == NULL)
    {
        return NULL;
    }

    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* startOfLoop = getStartNode(head);
    if(startOfLoop == NULL)
    {
        return head;
    }
    Node* temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    //cout<<"Cycle Was Present And removed";
    return head;
    
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    insertAtTail(tail,60);
    tail->next = head->next->next;
    //print(head);
    //cout<< removeNode(head);
    
    
    return 0;
}



//Detect Loop using Maps
//TC - O(n)
//SC - O(N)

bool dectectloop(Node* head)
{
    if(head == NULL){
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;
    while (temp != NULL)
    {
        //cycle is present
        if(visited[temp] == true){
            cout<<"Cycle at "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp ->next;
    }
    return false;
}