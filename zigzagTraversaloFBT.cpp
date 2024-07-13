#include<iostream>
#include<vector>
#include<queue>
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

vector<int> zigzag(Node* root)
{
    vector<int> result;
    queue<Node*> q;

    if(root == NULL)
    {
        return result;
    }

    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        //BT ke har level ko process krna h 
        for (int i = 0; i < size ; i++)
        {
            Node* frontNode = q.front();
            q.pop();

            //normal order ya reverse order----------
            int index;
            if(leftToRight)
            {
                index = i; // ye to normal h left to right
            }
            else{
                index = size - i - 1; //index piche point kra diya taki right to left m last element dale
            }
            ans[index] = frontNode->data;
            //--------------------------------------
            //ab child dl rhe h
            if(frontNode->left)
            {
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        //direction change krni h 
        leftToRight = !leftToRight; //!leftToRight ki jgh false likhne pr glt answer aa rhe h 

        for(auto i : ans)
        {
            result.push_back(i);
        }
    }

    return result;
    
}