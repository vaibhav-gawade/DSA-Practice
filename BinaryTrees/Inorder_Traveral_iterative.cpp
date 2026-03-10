#include<iostream>
#include<vector>
using namespace std;

// Problem : Binary Tree Inorder Traversal
// Leetcode no. : 94
/* --------------Approach-------------------
   We use the morris inorder traversal method to solve this in the
   O(n) time complexity and O(1) space complexity for this we maintain 
   the current node and take the inorder predecessor for the next left
   and come back irretatively by the previous pointer we make.*/
// Time complexity = O(N)
// Space complexity = O(1)

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

TreeNode* buildTree(vector<int>&preorder,int& indx){
    indx++;
    if(preorder[indx]==-1) return NULL;
    TreeNode* root = new TreeNode(preorder[indx]);

    root->left = buildTree(preorder,indx);
    root->right = buildTree(preorder,indx);

    return root;
}

// morris inorder traversal

void inorder(TreeNode* root){
    if(root == NULL) return;
    TreeNode* curr = root;

    while(curr!=NULL){
        if(curr->left == NULL){
            cout<<curr->val<<"  ";     
            curr=curr->right;
        }else{
            TreeNode* ip=curr->left;
            while(ip->right!=NULL && ip->right!=curr){
                ip=ip->right;
            }

            if(ip->right == NULL){
                ip->right = curr;       // make connection
                curr = curr->left;
            }else{
                ip->right = NULL;
                cout<<curr->val<<"  ";      // break connection
                curr=curr->right;
            }
        }
    }
}

int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int indx=-1;
    TreeNode* root = buildTree(preorder,indx);

    inorder(root);

    return 0;
}