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

Node* predecessor(Node* root,Node* val)
{
    Node* pred = NULL;

    while (root != NULL)
    {
        if(root -> data >= val->data){
            root = root -> left;
        }
        else{
            pred = root;
            root = root -> right;
        }
    }
    return pred;
}