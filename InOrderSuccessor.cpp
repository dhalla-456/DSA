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

Node* successor(Node* root,Node* val)
{
    Node* succ = NULL;

    while (root != NULL)
    {
        if(val -> data >= root->data){
            root = root -> right;
        }
        else{
            succ = root;
            root = root -> left;
        }
    }
    return succ;
}