#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem : Maximum Width of the binary tree
// LeetCode Problem No. : 662
/* --------Approach-------------
    We so the level order travesal and store the nodes in the queue along 
    with their index or thier position according to the complete binary tree
    for that we use the formula of (2*right+1) for first element below the node
    and the for second i.e for right node (2*right+2) then before we pop the 
    element from the queue we find the length of the curr level by the
            formula = (right - left +1)
    */
//In this problem overflow is the main issue which can be solved by unsigned long long

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

// core logic for the width of the binary tree

int widthOfBinaryTree(TreeNode* root){
    unsigned long long maxwidth = 0;
    queue<pair<TreeNode*,unsigned long long>>q;
    q.push({root,0});
    q.push({NULL,0});

    while(!q.empty()){
        unsigned long long left = q.front().second;
        unsigned long long right = left;
        TreeNode* curr = q.front().first;
        q.pop();

        while(curr!=NULL){
            if(curr->left) q.push({curr->left,2*right+1});
            if(curr->right) q.push({curr->right,2*right+2});
            curr = q.front().first;
            if(curr!=NULL) right = q.front().second;
            q.pop();
        }
        maxwidth=max(right-left+1,maxwidth);

        if(!q.empty()) q.push({NULL,0});
    }

    return maxwidth;
}

int main(){
    vector<int>preorder = {1,3,5,6,-1,-1,-1,-1,2,-1,9,7,-1,-1,-1};
    TreeNode* root = BuildTree(preorder);

    int n=widthOfBinaryTree(root);

    cout<<"The width of the binary tree is "<<n;

    return 0;
}