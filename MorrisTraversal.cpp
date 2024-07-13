//https://www.youtube.com/watch?v=80Zug6D1_r4
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

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

vector<int> getInOrder(Node* root)
{
    vector<int> inOrder;
    Node* curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inOrder.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            Node* prev = curr->left;
            while (prev -> right && prev -> right != curr)
            {
                prev = prev -> right;
            }
            if(prev -> right == NULL)
            {
                prev -> right = curr;
                curr = curr -> left;
            }

            else
            {
                prev -> right = NULL;
                inOrder.push_back(curr -> data);
                curr = curr -> right;
            }
        }
    }
    return inOrder;
}

vector<int> getPreOrder(Node* root)
{
    vector<int> inOrder;
    Node* curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inOrder.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            Node* prev = curr->left;
            while (prev -> right && prev -> right != curr)
            {
                prev = prev -> right;
            }
            if(prev -> right == NULL)
            {
                prev -> right = curr;
                inOrder.push_back(curr -> data);
                curr = curr -> left;
            }

            else
            {
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return inOrder;
}