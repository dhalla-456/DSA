//https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

#include<iostream>
#include<queue>
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


void inOrder(Node* root,vector<int> &inOrderV){
    if(root == NULL){
        return;
    }

    inOrder(root->left,inOrderV);
    inOrderV.push_back(root->data);
    inOrder(root->right,inOrderV);
}

Node* inOrderBST(int s,int e,vector<int> &in){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inOrderBST(s, mid-1,in);
    root -> right = inOrderBST(mid+1, e, in);
    return root;
}

Node* balancedBst(Node* root) {
    vector<int> inOrderVal;
    //inOrder value of Bst stored in BST in Sorted way
    inOrder(root,inOrderVal);
    int n = inOrderVal.size();

    return inOrderBST(0,n-1 , inOrderVal);

}
