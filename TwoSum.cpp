//https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0

#include<iostream>
#include<queue>
#include<vector>
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

void inOrder(Node* root,vector<int> &inOrderV){
    if(root == NULL){
        return;
    }

    inOrder(root->left,inOrderV);
    inOrderV.push_back(root->data);
    inOrder(root->right,inOrderV);
}

bool twoSumInBST(Node* root, int target) {
	vector<int> inOrderVal;
    //inOrder value of Bst stored in VECTOR in Sorted way
    inOrder(root,inOrderVal);
    //Uses Two pointer Approach to Find Sum in O(N) TC and SC
    int i = 0;
    int j = inOrderVal.size()-1;

    while(i<j){
        int sum = inOrderVal[i] + inOrderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}