#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void sortLL(Node*& head) {
    if (head == NULL)
        return;

    Node* curr = head;

    while (curr->next != NULL) {
        Node* temp = curr->next;
        while (temp != NULL) {
            if (curr->data >= temp->data) {
                swap(curr->data, temp->data);
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}

Node* removeDuplicates(Node* head) {
    if (head == NULL)
        return NULL;

    map<int, bool> visited;
    Node* curr = head;

    while (curr->next != NULL) {
        visited[curr->data] = true;
        if (visited[curr->next->data] == true) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    // Sample usage of the functions
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    sortLL(head);
    cout << "Sorted Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = removeDuplicates(head);
    cout << "Linked List after removing duplicates: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}




#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node* removeDuplicates(Node* head) {
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int> uniqueSet;

    while (curr != NULL) {
        if (uniqueSet.count(curr->data) > 0) {
            // Duplicate node found, remove it
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // Unique node, add it to the set
            uniqueSet.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
