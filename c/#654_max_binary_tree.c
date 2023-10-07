/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findMaxIdx(int *nums, int left, int right)
{
    int maxIdx = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (nums[i] > nums[maxIdx])
        {
            maxIdx = i;
        }
    }

    return maxIdx;
}

struct TreeNode* constructHelper(int* nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    int maxIdx = findMaxIdx(nums, left, right);

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[maxIdx];
    root->left = constructHelper(nums, left, maxIdx - 1);
    root->right = constructHelper(nums, maxIdx + 1, right);

    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    return constructHelper(nums, 0, numsSize - 1);
}