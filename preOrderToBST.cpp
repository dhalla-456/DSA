//https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

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


Node* solve(vector<int> &preorder,int mini,int maxi,int &i) {
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini  || preorder[i] > maxi){
        return NULL;
    }
    Node* root = new Node(preorder[i++]);
    //root -> right = solve(preorder,root->data,maxi,i);
    root -> left = solve(preorder,mini, root->data, i);
    root -> right = solve(preorder,root->data,maxi,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int i = 0;
    int mini = INT_MIN;
    int maxi = INT_MAX;

    return solve(preorder, mini,maxi,i);
}