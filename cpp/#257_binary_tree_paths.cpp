// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.

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


#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> paths;
        if (nullptr == root)
        {
            return paths;
        }

        traverse(root, "", paths);

        return paths;
    }

private:
    void traverse(TreeNode* node, std::string path, std::vector<std::string>& paths)
    {
        if (nullptr == node)
        {
            return;
        }

        if (!path.empty())
        {
            path += "->";
        }
        path += std::to_string(node->val);

        if ((nullptr == node->left) && (nullptr == node->right))
        {
            paths.push_back(path);
            return;
        }

        traverse(node->left, path, paths);
        traverse(node->right, path, paths);
    }
};
