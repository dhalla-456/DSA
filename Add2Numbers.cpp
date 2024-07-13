#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
class Node {
    public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

     Node* reverse( Node*  head)
    {
         Node* curr = head;
         Node* prev = NULL;
         Node* next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

void insertAtTail( Node* &head, Node* &tail ,int val)
{
    struct Node* temp = new Node(val);
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

Node* add( Node* first, Node* second)
{
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0 ;
        if(first != NULL)
        {
            val1 = first->data;
        }

        int val2 = 0 ;
        if(second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2 ;

        int digit = sum%10;
        //creating a Node for ans LL
        insertAtTail(ansHead,ansTail,digit);

        carry = sum/10;
        if(first != NULL)
        {
        first = first -> next;
        }
        if(second != NULL)
        {
        second = second -> next;
        }
    }
    return ansHead;
}

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reverse both LL
        first = reverse(first);
        second = reverse(second);

        //Add LL

        struct Node* ans = add(first,second);

        //reverse ans wali LL

        ans = reverse(ans);

        return ans;
    }