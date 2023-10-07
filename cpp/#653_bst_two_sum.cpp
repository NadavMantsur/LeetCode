// Given the root of a binary search tree and an integer k, return true if there 
// exist two elements in the BST such that their sum is equal to k, or false otherwise.

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

#include <unordered_set>

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        std::unordered_set<int> numSet;
        return SearchBst(root, numSet, k);
    }

private:
    bool SearchBst(TreeNode* node, std::unordered_set<int>& numSet, int k)
    {
        if (nullptr == node)
        {
            return false;
        }

        if (numSet.find(k - node->val) != numSet.end())
        {
            return true;
        }

        numSet.insert(node->val);

        return SearchBst(node->left, numSet, k) || SearchBst(node->right, numSet, k);
    }
};
