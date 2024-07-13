#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* merge(Node* left,Node*right)
{
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data )
        {
            temp -> next = left;
            temp = left;
            left = left -> child;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> child;
        }
    }
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> child;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> child;
    }
    ans = ans -> next;
    return ans;
}

Node* flattenLinkedList(Node* head) 
{
	Node* down = head;
	down->next = down->child;
	Node* right = flattenLinkedList(head->next);
	Node* ans = merge(down,right);
	return ans;
}


