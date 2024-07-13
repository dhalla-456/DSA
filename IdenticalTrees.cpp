#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node 
{
        public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

//Determine if Two Trees are Identical

bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if ((r1 == NULL && r2 != NULL) || r1 != NULL && r2 == NULL) {
      return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool val = (r1->data == r2->data);

    if(left && right && val)
    {
        return true;
    }
    else{
        return false;
    }
    }