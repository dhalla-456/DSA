//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int row,int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    //step 1 : sare arrays ke first element ko min heap m daalo or sbse min element agle step m nikalo
    for (int row = 0; row < k; row++)
    {
        Node* temp = new Node(kArrays[row][0],row,0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //step 2 : 
    while (!minHeap.empty())
    {
        Node* temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp -> row;
        int col = temp -> col;

        if(col+1 < kArrays[row].size()){
            Node* next = new Node(kArrays[row][col+1],row,col+1);
            minHeap.push(next);
        }
    }
    return ans;
}