#include <iostream>
#include <vector>
using namespace std;

// Problem: Largest BST Subtree (Binary Tree)

// Given a binary tree, return the size of the largest
// subtree which is also a Binary Search Tree (BST).

// A BST satisfies:
// left.max < root.val < right.min

// Approach (Postorder Tree DP):
// For every node we need information from its children
// to decide if the subtree rooted at this node is a BST.

// So each recursive call returns 4 values:

// 1. minv  -> minimum value in the subtree
// 2. maxv  -> maximum value in the subtree
// 3. size  -> size of the largest BST in this subtree
// 4. isBST -> whether the subtree itself is a BST

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

/* -------------------------------------------------
   CORE LOGIC OF THE PROBLEM
--------------------------------------------------*/

struct Info{
    int minv;
    int maxv;
    int size;
    bool isBST;
};

Info helper(Node* root){

    // base case
    if(root == NULL){
        return {INT_MAX, INT_MIN, 0, true};
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    Info curr;

    // check BST condition
    if(left.isBST && right.isBST &&
       root->data > left.maxv &&
       root->data < right.minv){

        curr.isBST = true;
        curr.size = left.size + right.size + 1;

        curr.minv = min(root->data, left.minv);
        curr.maxv = max(root->data, right.maxv);
    }
    else{

        curr.isBST = false;
        curr.size = max(left.size, right.size);

        curr.minv = INT_MIN;
        curr.maxv = INT_MAX;
    }

    return curr;
}

int largestBST(Node* root){
    return helper(root).size;
}

/* -------------------------------------------------
   TEST RUNNER
--------------------------------------------------*/
void runTest(Node* root, int expected, int testNumber){

    int ans = largestBST(root);

    cout << "Test " << testNumber << " -> ";

    if(ans == expected)
        cout << "PASSED";
    else
        cout << "FAILED (Expected " << expected << " Got " << ans << ")";

    cout << endl;
}

int main(){

    /* Test Case 1
            50
           /  \
         30    60
        /  \   / \
       5   20 45 70
       Largest BST = 3
    */

    Node* t1 = new Node(50);
    t1->left = new Node(30);
    t1->right = new Node(60);
    t1->left->left = new Node(5);
    t1->left->right = new Node(20);
    t1->right->left = new Node(45);
    t1->right->right = new Node(70);

    runTest(t1,3,1);


    /* Test Case 2
            10
           /  \
          5    15
         / \     \
        1   8     7
        Largest BST = 3
    */

    Node* t2 = new Node(10);
    t2->left = new Node(5);
    t2->right = new Node(15);
    t2->left->left = new Node(1);
    t2->left->right = new Node(8);
    t2->right->right = new Node(7);

    runTest(t2,3,2);


    /* Test Case 3 (Full BST)
            8
           / \
          4   10
         / \    \
        2   6    20
        Largest BST = 6
    */

    Node* t3 = new Node(8);
    t3->left = new Node(4);
    t3->right = new Node(10);
    t3->left->left = new Node(2);
    t3->left->right = new Node(6);
    t3->right->right = new Node(20);

    runTest(t3,6,3);


    return 0;
}