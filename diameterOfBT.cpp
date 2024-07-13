#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//***********************************************************

    //Following is the TreeNode class structure
    class Node {
       public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

//***********************************************************
// int height(TreeNode<int>* &root)
// {
//     //base case
//     if(root == NULL)
//     {
//         return 0;
//     }

//     int left = height(root->left);
//     int right = height(root->right);

//     int ans = max(left,right)+1;
//     return ans;
// }

// int diameterOfBinaryTree(TreeNode<int> *root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }

//     int op1 = diameterOfBinaryTree(root->left);
//     int op2 = diameterOfBinaryTree(root->right);
//     int op3 = height(root->left)+height(root->right);

//     int ans = max(op1,max(op2,op3));
//     return ans;
// }
//*************************************************************
//Approach 2 

//Diameter of a Binary Tree

    // Function to return the diameter of a Binary Tree.
    pair<int,int> diameterFast(Node* root)
    {
        //base case
        if(root == NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
    
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
    
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
    
        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second)+1;
    
        return ans;
    }


    int diameter(Node* root) {
        return diameterFast(root).first+1;
    }