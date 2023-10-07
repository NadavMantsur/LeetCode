// 501. Find Mode in Binary Search Tree
// Given the root of a binary search tree (BST) with duplicates, 
// return all the mode(s) (i.e., the most frequently occurred element) in it.

#include <vector>
#include <unordered_map>

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
    std::vector<int> findMode(TreeNode* root)
    {
        std::unordered_map<int, int> freqMap;
        int maxFreq = 0;

        traverse(root, freqMap, maxFreq);

        std::vector<int> modes;

        for (const auto& pair : freqMap)
        {
            if (pair.second == maxFreq)
            {
                modes.push_back(pair.first);
            }
        }

        return modes;
    }

private:
    void traverse(TreeNode* node, std::unordered_map<int, int>& freqMap, 
                                                                int& maxFreq)
    {
        if (nullptr == node)
        {
            return;
        }

        traverse(node->left, freqMap, maxFreq);

        ++freqMap[node->val];

        maxFreq = std::max(maxFreq, freqMap[node->val]);

        traverse(node->right, freqMap, maxFreq);
    }
};