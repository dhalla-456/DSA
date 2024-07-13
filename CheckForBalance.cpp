#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//Check for Balanced Tree
    
pair<bool,int> isBalancedFast(Node * root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);
    
    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs (left.second -right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second) +1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans; 
}

    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }


//Approach 2

// int height(BinaryTreeNode<int>* root)
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

// bool isBalancedBT(BinaryTreeNode<int>* root) {
//     if(root == NULL)
//     {
//         return true;
//     }

//     bool left = isBalancedBT(root->left);
//     bool right = isBalancedBT(root->right);

//     bool diff = abs(height(root->left) - height(root->right)) <= 1;

//     if(left && right && diff)
//     {
//         return true;
//     }
//     else{
//         return false;
//     }
// }
