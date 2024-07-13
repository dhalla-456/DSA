#include<iostream>
#include<map>
using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node();
};

Node* uniqueSortedList(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head ;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr ->data == curr->next->data))
        {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

Node* uniqueUnsortedList(Node* head)
{
    //Approach 1 : Use 2 loops TC - o(n2)
    //Approach 2 : first sort LL and then apply above algo
    //Approach 3 : Use map and mark visited number and if reappear then delete that

    if(head == NULL)
    {
        return NULL;
    } 

    Node* curr = head;
    map<Node*,bool> visited;

    
}
