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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            //previous level complete so enter
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inOrder(Node* root)  //LNR
{
    //base case
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){  //NLR
        //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)  //LRN
{
        //base case
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* insertInBST(Node* root,int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data > root->data)
    {
        root -> right = insertInBST(root -> right,data);
    }
    else
    {
        root -> left = insertInBST(root -> left,data);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertInBST(root,data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter Data For BST Creation : "<<endl;
    takeInput(root);
    cout<<"Printing BST Dost : "<<endl;
    levelOrderTraversal(root);
    return 0;
}