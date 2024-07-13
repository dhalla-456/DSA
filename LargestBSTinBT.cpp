#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

class info{
    public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(Node* root,int &ans){

    //base case
    if(root == NULL){
        return {INT_MIN,INT_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
        if(currNode.isBST){
        ans = max(ans,currNode.size);
        }
        return currNode;
    }
    else{
        currNode.isBST = false;
        return {0,0,false,max(currNode.size,max(left.size,right.size))};
    }
}

int largestBST(Node* root) 
{
    int maxsize = 0 ;
    info temp = solve(root,maxsize);
    return maxsize;
}


int main() {
    // Create a binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    // Call the largestBST function
    int largestSize = largestBST(root);
    cout << "Size of the largest BST: " << largestSize << endl;

    // Delete the binary tree
    delete root;
}