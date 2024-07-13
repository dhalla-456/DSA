//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-nodes-in-a-binary-tree-such-that-no-two-nodes-are-adjacent_1118112



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



pair<int,int> solve(Node* root) 
{
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0); 
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
}
int getMaxSum(Node *root) 
{
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
}