#include<iostream>
#include<vector>
using namespace std;

// Problem : Diameter of the binary tree
// Approach : use postorder traversal to find the length of the right and left side
// compare the diameter of the current branch with maximum diameter and update accordingly
// return the longest side of the branch to the above branch

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

// core logic of finding diameter

int dia(TreeNode* root,int &diameter){
    if(root == NULL) return 0;

    int lefth = dia(root->left,diameter);
    int righth = dia(root->right,diameter);

    diameter = max(diameter,lefth + righth);

    return 1 + max(lefth,righth);
}

int diameteroftree(TreeNode* root){
    int diameter = 0;
    dia(root,diameter);

    return diameter;
}

int main(){
    vector<int>preorder = {3,9,-1,-1,20,15,-1,-1,-1,-1};
    TreeNode* root = BuildTree(preorder);

    int n = diameteroftree(root);

    cout<<"The diameter of the tree is "<<n;

    return 0;
}