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
class Solution 
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return ConstructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* ConstructMaximumBinaryTree(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int maxIndex = FindMaxIndex(nums, left, right);
        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = ConstructMaximumBinaryTree(nums, left, maxIndex - 1);
        root->right = ConstructMaximumBinaryTree(nums, maxIndex + 1, right);

        return root;
    }

    int FindMaxIndex(vector<int>& nums, int left, int right)
    {
        int maxIndex = left;
        for (int i = left + 1; i <= right; ++i)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }

        return maxIndex;
    }
};