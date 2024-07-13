//Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node*right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(Node* root,int sum,int &MaxSum,int len,int &MaxLen)
{
    if(root == NULL)
    {
        if(len > MaxLen)
        {
            MaxLen = len;
            MaxSum = sum;
        }
        else if(len == MaxLen){
                MaxSum = max(sum,MaxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left,sum,MaxSum,len+1,MaxLen);
    solve(root->right,sum,MaxSum,len+1,MaxLen);
}

int sumOfLongestPath(Node* root)
{
    int len = 0 ;
    int maxLen = 0;

    int sum = 0;
    int maxSum = -25451;

    solve(root,sum,maxSum,len,maxLen);

    return maxSum;
}