#include<iostream>
#include<vector>
using namespace std;

// problem : Sub tree of another tree
// approach : inorder method of transversal 
// we first check if the node of the main tree and the subtree are identical
// if we get such node we try to see if the other branches of the subtree also are same
// we have another function same to check if they are identical
// if we find identical we return true else we return false

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

TreeNode* BuildTree(vector<int>preorder,int &indx){
    indx++;
    if(preorder[indx]==-1) return NULL;

    TreeNode* root = new TreeNode(preorder[indx]);

    root->left = BuildTree(preorder,indx);
    root->right = BuildTree(preorder,indx);

    return root;
}

// check for subtree as soon as we find the root of main tree and subtree as same

bool same(TreeNode* root,TreeNode* subRoot){
    if(root==NULL || subRoot==NULL) return root==subRoot;
        
    return same(root->left,subRoot->left)  &&  same(root->right,subRoot->right)  && root->val==subRoot->val;
}

// check for the node which is identical as subtree

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==NULL || subRoot==NULL) return root==subRoot;

    if(root->val==subRoot->val && same(root,subRoot)) return true;

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);     
}

int main(){
    vector<int>preorder={3,4,1,-1,-1,2,-1,-1,5,-1,-1};
    vector<int>preordersub={4,1,-1,-1,2,-1,-1};

    int indx1=0,indx2=0;
    TreeNode* root=BuildTree(preorder,indx1);
    TreeNode* subtree=BuildTree(preordersub,indx2);

    if(isSubtree(root,subtree)){
        cout<<"The given subtree is present in the given main tree!";
    }else{
        cout<<"The given subtree is not present in the given main tree!";
    }

    return 0;
}