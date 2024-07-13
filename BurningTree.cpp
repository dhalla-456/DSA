//Burning Tree
//https://practice.geeksforgeeks.org/problems/burning-tree/1
//https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563
//TC - O(N) SC - O(N)

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

Node* createMapping(Node*root,int target,map<Node*,Node*> &nodeToParent)
{
    Node* res = NULL;

    queue<Node*> q;
    q.push(root);   //root node daali phle 
    nodeToParent[root] = NULL;  // root node ka koi parent ni hota

    while(!q.empty())
    {
        Node* front = q.front();  
        q.pop();

        if(front->data == target)
        {
            res = front;  //target bhi dhundh liye is function m jis se burning start krni h 
        }

        if(front -> left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front -> right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int buringTree(Node* root,map<Node*,Node*> &nodeToParent)
{
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(root);       //yha root mtlb targetnode se h 
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag =1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right])
            {
                flag =1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]])  // checking parent of node jispe pointer h 
            {
                flag =1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        if(flag == 1){
            ans++;
        }
    }
    return ans;
}

int minTime(Node* root,int target)
{
    algo:
    //create nodetoParent Mappping
    //find target node
    //burn tree in min time

    map<Node*,Node*> nodeToParent;
    Node* targetNode = createMapping(root, target,nodeToParent);
    int ans = buringTree(targetNode,nodeToParent);
    return ans;
}