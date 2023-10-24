/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Returns -1 if the subtree is unbalanced.
    int getHeight(TreeNode* root) {
        // If the node is null, the height is 0.
        if (nullptr == root) {
            return 0;
        }
        
        // Recursively calculate the height of the left subtree.
        int leftHeight = getHeight(root->left);
        // in case the left subtree is unbalanced
        if (leftHeight == -1) {
            return -1;
        }
        
        // Recursively calculate the height of the right subtree.
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        
        // check the difference between left and right subtrees
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        // Return the height of the current subtree.
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};