//Construct Tree from Inorder & Preorder
//Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 
//https://practice.geeksforgeeks.org/problems/construct-tree-1/1

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

int findPosition(int in[],int element,int inOrderStart,int inOrderEnd)
            {
                for(int i = inOrderStart;i<=inOrderEnd;i++)
                {
                    if(in[i] == element)
                    {
                        return i;
                    }
                }
                return -1;
            }

Node* solve(int in[],int pre[],int &index,int inOrderStart,int inOrderEnd,int n)
{
    if(index >= n || inOrderStart > inOrderEnd) 
    {
        return NULL;
    }
    
    int element = pre[index++]; //root node ka element nikala 

    Node* root = new Node(element); //element ki node bna di 

    int position  = findPosition(in,element,inOrderStart,inOrderEnd); //inorder wale arr m element ki position dundhi

    //recursive Call
    root->left = solve(in,pre,index,inOrderStart,position-1,n);
    root->right = solve(in,pre,index,position+1,inOrderEnd,n);

    return root;
}

Node* buildTree(int in[],int pre[],int n)
{
    int preOrderIndex = 0 ;
    Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
}

// InOrder - LNR
// PreOrder - NLR -> isliye itrate kiya humne 0 to n kyoki node phle aati h isme print hone ke liye
// PostOrder - LRN -> isme n-1 to 0 kiya 
