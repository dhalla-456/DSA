//https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0

#include<iostream>
#include<queue>
#include<vector>
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

Node* flatten(Node* root)
{
    vector<int> inOrderVal;
    //inOrder value of Bst stored in BST in Sorted way
    inOrder(root,inOrderVal);

    int n = inOrderVal.size();

    Node* newroot = new Node(inOrderVal[0]);

    Node* curr = newroot;
    for(int i = 1;i<n;i++)
    {
        Node* temp = new Node(inOrderVal[i]);

        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }
    curr -> left = NULL;
    curr -> right = NULL;

    return newroot;
}