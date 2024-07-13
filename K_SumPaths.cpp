//Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
//https://www.codingninjas.com/codestudio/problems/k-sum-path-in-a-binary-tree_893543
//https://practice.geeksforgeeks.org/problems/k-sum-paths/1


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

void find(Node* root,int k , int &count ,vector<int> path){
    if(root == NULL)
    {
        return;
    }
    path.push_back(root->data);

    find(root->left,k,count,path);
    find(root->right,k,count,path);

    int size = path.size();
    int sum = 0;
    for (int  i = size-1; i >= 0; i--)
    {
        sum = sum + path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}


int sumK(Node *root,int k)
{
        vector<int> path;
        int sum = 0 ;
        int count = 0;
        find(root,k,count,path);
        return count;
}