//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        next = NULL;
        this->data = data;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }
    
    Node* head = NULL;
    Node* tail = NULL;
    while (minHeap.size() > 0)
    {
        Node* top = minHeap.top();

        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = tail->next;
        }
    }
    return head;
}