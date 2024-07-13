//https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
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

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node*,vector<Node*>,compare> minHeap;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    //create a minHeap for starting element of every list and tracking min/max value
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new Node(element,i,0));        
    }
    
    int start = mini;
    int end = maxi;

    //processing range
    while (!minHeap.empty())
    {
        //mini ko fetch kr rhe h  
        Node* top = minHeap.top();
        minHeap.pop();
        mini = top->data;
        
        //min max ko update kr rhe h 
        if (maxi - mini  < end-start)
        {
            start = mini;
            end = maxi;
        }
        //next element exist krta h ya ni check kr rhe h 
        if (top->col +1 < n )
        {
            maxi = max(maxi,a[top->row][top->col+1]);
            minHeap.push(new Node(a[top->row][top->col+1],top->row,top->col+1));
        }
        else
        {
            //next element does not exist
            break;
        }
    }
    //returning the difference of the range values 
    return (end - start) + 1;
}