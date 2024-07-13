#include <bits/stdc++.h> 
#include<math.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

//***********************************************************

    //Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

//***********************************************************
int height(TreeNode<int>* &root)
{
    //base case
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;
}

int maxDepth(TreeNode<int> *root) {
    int ans = height(root)-1;
    return ans;
}