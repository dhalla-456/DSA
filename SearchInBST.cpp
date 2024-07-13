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

bool searchBST(Node*root,int x)
{
    Node* temp = root;

    while (temp != NULL)
    {
        if(temp -> data == x){
            return true;
        }
        if(temp ->data > x){
            temp = temp->left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}