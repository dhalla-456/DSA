//https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0

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

//Approach 1 : 
// inorder traversal nikal lo or check krlo sorted h ki ni
// inorder traversal krte time root->data ko ek array m daalo lo or check krlo sorted h ki ni 

//Approach 2 : 
//

bool isBST(Node *root,int min,int max)
{
    //base case
    if(root == NULL)
    {
        return true;
    }
    if(root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);  //on left side values lies between -infinity to root data
        bool right = isBST(root->right,root->data, max); //on right side values lies between root data to infinity
        return left && right; //dono true hone chiye jbhi BST hoga
    }
    else{
        return false;
    }
}

bool validateBST(Node *root) {
    return isBST(root,INT_MIN,INT_MAX);
}