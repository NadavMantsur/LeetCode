/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countNode(struct TreeNode* root)
{
    if (NULL == root)
    {
        return 0;
    }

    return 1 + countNode(root->left) + countNode(root->right);
}

void postorderHelper(struct TreeNode* root, int *res, int *idx)
{
    if (NULL == root)
    {
        return;
    }

    postorderHelper(root->left, res, idx);
    postorderHelper(root->right, res, idx);
    res[*idx] = root->val;
    ++(*idx);
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int idx = 0;
    int *res = NULL;

    *returnSize = countNode(root);

    res = (int*)malloc(*returnSize * sizeof(int));
    postorderHelper(root, res, &idx);

    return res;
}