#include<iostream>
#include<vector>
using namespace std;

// Problem : Maximum depth of the binary tree
// Approach : go left as deep as possible then move right side deep and return max of both
// The height of the tree will be 1 + maximum(leftheight,rightheight)

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        right = left = NULL;
    }
};

static int indx = -1;
TreeNode* BuildTree(vector<int>preorder){
    indx++;
    if(preorder[indx]==-1) return NULL;

    TreeNode* root = new TreeNode(preorder[indx]);

    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);

    return root;
}

// Core idea of finding the depth
int maxdepth(TreeNode* root){
    if(root == NULL) return 0;

    int leftheight = maxdepth(root->left);
    int rightheight = maxdepth(root->right);

    return 1 + max(leftheight,rightheight);
}

int main(){
    vector<int>preorder = {3,9,-1,-1,20,15,-1,-1,-1,-1};
    TreeNode* root = BuildTree(preorder);

    int n = maxdepth(root);

    cout<<"The maximum depth of the tree is "<<n;

    return 0;
}