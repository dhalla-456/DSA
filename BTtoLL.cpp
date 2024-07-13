//Flatten binary tree to linked list
//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
//https://www.codingninjas.com/codestudio/problems/flatten-binary-tree-to-linked-list_1112615

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

void flatten(Node* root)
{
    Node* curr = root;

    while (curr != NULL)
    {
        if(curr -> left){
            Node* prev = curr -> left;  // left m chlegya
            while (prev -> right)
            {
                prev = prev -> right;   // first node ke left m jane ke bad ye while loop hume extreme right m le jaega 
            }
            prev -> right = curr -> right;    // yha humne link bna diye left or right nodes ke bich m
            curr -> right = curr -> left;   //or root node ke right ko hta ke left m point kra diya
            curr -> left = NULL;  // or left ko NULL krdiya kyo ki PreOrder Traversal m m kr rhe h NLR
        }
        curr = curr -> right;
    }
    
}