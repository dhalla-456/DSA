//Lowest Common Ancestor in a Binary Tree
//https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_920541
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

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

Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
       if(root == NULL)
       {
        return NULL;
       }
       if(root->data == n1 || root->data == n2){
        return root;
       }
       
       Node* leftAns = lca(root->left,n1,n2);
       Node* rightAns = lca(root->right,n1,n2);

       if(leftAns != NULL && rightAns != NULL)
       {
            return root;
       }
       else if (leftAns != NULL && rightAns == NULL)
       {
        return leftAns;
       }
       else if (leftAns == NULL && rightAns != NULL)
       {
        return rightAns;
       }
       else{
        return NULL;
       }       
    }