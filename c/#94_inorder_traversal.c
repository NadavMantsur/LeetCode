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

void inorderHelper(struct TreeNode* root, int *res, int *idx)
{
    if (NULL == root)
    {
        return;
    }

    inorderHelper(root->left, res, idx);
    res[*idx] = root->val;
    ++(*idx);
    inorderHelper(root->right, res, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int idx = 0;
    int *res = NULL;

    *returnSize = countNode(root);

    res = (int*)malloc(*returnSize * sizeof(int));
    inorderHelper(root, res, &idx);

    return res;
}