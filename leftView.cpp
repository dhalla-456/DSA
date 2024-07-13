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

void solve(Node* root,vector<int> &ans,int lvl)
{
    if(root == NULL){
        return;
    }
    //when we enter new level 
    if(lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}

vector<int> getLeftView(Node *root)
{
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}