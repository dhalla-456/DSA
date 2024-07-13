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

Node* mac(Node*root){
    Node* temp = root;
    while (temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}