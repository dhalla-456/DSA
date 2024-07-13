#include <bits/stdc++.h> 
using namespace std;
//*************************************************************
 
    //Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode<int> *left;
        BinaryTreeNode<int> *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

//*************************************************************/

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



//Above approach is right but code TLE mar gya 
//So we used Approach 2 mention below
pair<bool,int> isBalancedFast(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);
    
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

bool isBalancedBT(BinaryTreeNode<int>* root) {

    return isBalancedFast(root).first;

}
