/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* time comlexity: O(n)*/
int maxDepth(struct TreeNode* root){
    if (NULL == root){
        return 0;
    }

    int maxLeft = maxDepth(root->left) + 1;
    int maxRight = maxDepth(root->right) + 1;

    return maxLeft > maxRight ? maxLeft : maxRight;
}