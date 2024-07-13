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

vector<int> DiagonalView(Node* root)
{
    queue<Node*> q;

    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        while (temp)
        {
            if(temp->left){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;    
}