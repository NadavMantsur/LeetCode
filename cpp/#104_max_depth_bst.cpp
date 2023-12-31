// 104. Maximum Depth of Binary Tree
// Given the root of a binary tree, return its maximum depth.

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

// time comlexity: O(n)
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return 0;
        }

        int maxLeft = maxDepth(root->left) + 1;
        int maxRight = maxDepth(root->right) + 1;

        return max(maxLeft, maxRight);
    }
};


/*shorter solution*/
int maxDepth(TreeNode* root) 
    {
        if (nullptr == root)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};