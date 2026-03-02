#include<iostream>
#include<vector>
using namespace std;

// problem : Binary Tree Camera's
// approach : Depth first search 
// we apply cases following cases for knowing if we covered the node :
// 1.covered = 2, 2.not covered = 0 and 3. have camera = 1
// if we see the node is not covered we keep there camera and increase count

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

// Core logic for minimum camera's
int mincamera(TreeNode* root,int &count){
    if(root == NULL) return 2;

    int left = mincamera(root->left,count);
    int right = mincamera(root->right,count);

    if(right == 2 && left == 2){
        return 0;
    }

    if(right == 0 || left == 0){
        count++;
        return 1;
    };
        
    return 2;
}

int minCameraCover(TreeNode* root) {
    int count = 0;

    int n=mincamera(root,count);
    if(n==0) count++;

    return count;
}

int main(){
    vector<int>preorder={0,0,0,-1,-1,0,-1,-1,-1};

    TreeNode* root = BuildTree(preorder);
    int count=minCameraCover(root);

    cout<<"The minimum cameras needed for the tree to cover all nodes are "<<count;

    return 0;
}