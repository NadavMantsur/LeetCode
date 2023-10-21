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

#include <algorithm>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterHelper(root, &diameter);
        return diameter;    
    }

private:
    int diameterHelper(TreeNode* root, int* diameter){
        if (nullptr == root){
            return 0;
        }

        int leftHeight = diameterHelper(root->left, diameter);
        int rightHeight = diameterHelper(root->right, diameter);

        *diameter = std::max(*diameter, leftHeight + rightHeight);

        // calculate the max height of the sub tree + 1 (the curr node)
        return 1 + std::max(leftHeight, rightHeight);
    }
};