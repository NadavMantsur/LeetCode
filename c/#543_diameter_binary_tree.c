/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int helper(struct TreeNode* root, int* diameter) {
    if (NULL == root) {
        return 0;
    }
    
    /* Recursively find the heights of left and right subtrees*/
    int leftHeight = helper(root->left, diameter);
    int rightHeight = helper(root->right, diameter);
    
    /* Update the diameter if the current path is longer*/
    *diameter = max(*diameter, leftHeight + rightHeight);
    
    /* Return the height of the current subtree*/
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    helper(root, &diameter);
    return diameter;
}