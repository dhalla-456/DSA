//
//

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


void createMapping(int in[],map<int,int> &nodeToIndex,int n){
    for(int i = 0;i<n;i++){
        nodeToIndex[in[i]] = i;  //ab O(N) hi lagega barbar ni jana padega element ki position dhundhne
    }
}


Node* solve(int in[],int post[],int &index,int inOrderStart,int inOrderEnd,int n,map<int,int> &nodeToIndex)
{
    if(index >= 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    
    int element = post[index];
    index--;

    Node* root = new Node(element);

    int position = nodeToIndex[element];

    //recursive Call
    root->right = solve(in,post,index,position+1,inOrderEnd,n,nodeToIndex); //yha phle right call aaegi kyo ki postOrder traversal h hum piche se itrate kr rrhe h LRN hota h na PostOrder
    root->left  = solve(in,post,index,inOrderStart,position-1,n,nodeToIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n)
{   
    //int k = post.size();
    int postOrderIndex = n-1 ;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    Node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodeToIndex);
    return ans;
}