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

Node* min(Node*root){
    Node* temp = root;
    while (temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

Node* deleteNode(Node* root,int val){
    //base case
    if (root == NULL)
    {
        return root;
    }

    if(root->data == val)
    {
        //0 CHILD
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 CHILD which is LEFT
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //1 RIGHT CHILD
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;  
            delete root;
            return temp;
        }

        //Node have 2 Nodes
        if(root->left != NULL && root->right != NULL){
            int mini = min(root->right) -> data;  //node ke right m minimum val nikali 
            root->data = mini;  // node m mini daali  
            root->right = deleteNode(root->right,val);  // node delete krdi
            return root;
        }
    }
    
}