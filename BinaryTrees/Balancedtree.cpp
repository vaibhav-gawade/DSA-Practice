#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

// Problem : Balanced Binary Tree
// Approach : use postorder traversal to find the length of the right and left side
// if the absoulte difference between left and right is <=1 tree is valid
// if we find somewhere that the absoulte difference is greater we return -1
// -1 tells it is invlaid

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

// core logic of finding is balanced or not

int Balanced(TreeNode* root){
    if(root == NULL) return 0;

    int lefth = Balanced(root->left);
    int righth = Balanced(root->right);

    if(abs(lefth-righth)>1) return -1;
    if(lefth==-1) return -1;
    if(righth==-1) return -1;

    return 1 + max(lefth,righth);
}

bool isBalanced(TreeNode* root){
    if(Balanced(root) == -1) return false;
    return true;
}

int main(){
    vector<int>preorder = {3,9,-1,-1,20,15,-1,-1,7,-1,-1};
    TreeNode* root = BuildTree(preorder);

    if(isBalanced(root)){
        cout<<"The Binary Tree is balanced!";
    }else{
        cout<<"The binary tree is not balanced!";
    }

    return 0;
}