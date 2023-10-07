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


// iterative solution - using a breadth-first search (BFS) traversal approach
#include <queue>

using namespace std;

class Solution
{
public:
    int minDepth(TreeNode* root)
    {
        if (nullptr ==  root)
        {
            return 0;
        }

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        int depth = 0;

        while (!nodesQueue.empty())
        {
            depth++;

            int levelSize = nodesQueue.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // If the node is a leaf, return the current depth.
                if (nullptr == node->left && nullptr == node->right)
                {
                    return depth;
                }

                // Add child nodes to the queue.
                if (node->left)
                {
                    nodesQueue.push(node->left);
                }
                if (node->right)
                {
                    nodesQueue.push(node->right);
                }
            }
        }

        return depth;
    }
};

// recursive solution
// #include <limits> //INT_MAX

// using namespace std;

// class Solution 
// {
// public:
//     int minDepth(TreeNode* root) 
//     {
//         if (NULL == root) 
//         {
//             return 0;
//         }

//         // is leaf
//         if (NULL == root->left && NULL == root->right) 
//         {
//             return 1;
//         }

//         // INT_MAX - indicating that the left subtree does not exist.
//         int leftDepth = (NULL != root->left) ? minDepth(root->left) : INT_MAX;
//         int rightDepth = (NULL != root->right) ? minDepth(root->right) : INT_MAX;

//         return min(leftDepth, rightDepth) + 1; //+1 to considering the current node
//     }
// };