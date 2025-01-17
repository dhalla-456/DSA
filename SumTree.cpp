#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node 
{
        public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

pair<bool,int> isSumTreeFast(Node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool isleftSum = leftAns.first;
    bool isrightSum = rightAns.first;

    bool condition = (root->data == (leftAns.second + rightAns.second));

    pair<bool,int> ans;
    if(isleftSum && isrightSum && condition)
    {
        ans.first = true;
        ans.second = 2*root->data;
    } 
    else{
        ans.first = false;
    }
    return ans;
};

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}
