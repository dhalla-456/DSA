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

Node* LcaInBST(Node*root,Node* a,Node* b)
{
    while (root != NULL)
    {
        if(root->data < a->data && root->data < b->data){
            root= root->right;
        }
        else if(root->data > a->data && root->data > b->data){
            root= root->left;
        }
        else{
            return root;
        }
    }
}