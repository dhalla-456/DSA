#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL; 
    }
};

Node* createTree(Node* &root)
{
    cout<<"Enter the Data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of : " << data <<endl;
    root->left = createTree(root->left);
    cout<<"Enter data for inserting in right of : " << data <<endl;
    root->right = createTree(root->right);
    return root;
}

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
            //Purana Level Completely Traverse Ho Chuka H
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); //When q has some child nodes
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        
    }
    
}

void reverse_vector(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n/2; i++) {
        int temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

vector<int> reverseLevelOrder(Node* root){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);

    while(!q.empty())
    {
        Node* temp =q.front();
        ans.push_back(temp->data);

        if(temp->right)
        {
                q.push(temp->right);
        }
        if(temp->left)
        {
                q.push(temp->left);
        }
        q.pop();
    }
    // for(int i = ans.size();i>=0;i--){
    //     cout<<ans[i]<<"  ";
    // }
    int n = ans.size();
    reverse_vector(ans);
    return ans;
}

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}

int main()
{
    Node* root = NULL;
    createTree(root);

    levelOrderTraversal(root);
    return 0;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 14 -1 -1
}





/*
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
/*
void reverse_vector(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n/2; i++) {
        int temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

vector<int> reverseLevelOrder(TreeNode<int> *root){
    queue<TreeNode<int>*> q;
    vector<int> ans;
    if(!root)
    {
        return ans;
    }
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* temp = q.front();
        ans.push_back(temp->val);

        if(temp->right)
        {
                q.push(temp->right);
        }
        if(temp->left)
        {
                q.push(temp->left);
        }
        q.pop();
    }
    // for(int i = ans.size();i>=0;i--){
    //     cout<<ans[i]<<"  ";
    // }
    //int n = ans.size();
    reverse_vector(ans);
    return ans;
}
*/
/*
#include <vector>
#include <queue>
/*
template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void reverse_vector(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n/2; i++) {
        int temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

vector<int> reverseLevelOrder(const TreeNode<int>* root){
    queue<const TreeNode<int>*> q;
    vector<int> ans;
    if(!root)
    {
        return ans;
    }
    q.push(root);

    while(!q.empty())
    {
        const TreeNode<int>* temp = q.front();
        ans.push_back(temp->val);

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        q.pop();
    }

    // Print elements in reverse order
    // for(int i = ans.size()-1; i >= 0; i--) {
    //     cout << ans[i] << " ";
    // }

    reverse_vector(ans);
    return ans;
}

*/