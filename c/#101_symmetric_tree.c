/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* left, struct TreeNode* right);

bool isSymmetric(struct TreeNode* root) {
    if (NULL == root){
        return true;
    }

    return isMirror(root->left, root->right);
}

bool isMirror(struct TreeNode* left, struct TreeNode* right){
    if (NULL == left && NULL == right){
        return true;
    }

    if (NULL == left || NULL == right || left->val != right->val) {
        return false;
    }

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}