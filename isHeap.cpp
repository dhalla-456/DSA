//https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
//Is a tree is heap

#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


//Approach : check  if complete binary tree and check that every parent node has greater data than is child 
//nodes

int countNodes(Node* root)
{
    if(root == NULL){
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root,int index,int count)
{
    if(root == NULL)
    {
        return true;
    }

    if(index >= count){
        return false; // count se bhar chla gya index pointer
    }

    else
    {
        bool left = isCBT(root->left,2*index+1,count); // 0 indexing se solve kr rhe h isliye 2*i+1 hua h
        bool right = isCBT(root->right,2*index+2,count);
        return (left && right);
    }
}

bool isMaxOrder(Node* root)
{
    //checking Leaf Node
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    //checking hi sirf right node to exist ni krti ,ni krti to yhe kre 
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data ));
    }
}

bool isHeap(Node* root)
{
    int index = 0;
    int totalNode = countNodes(root);
    if(isCBT(root,index,totalNode) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}