/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public TreeNode ConstructMaximumBinaryTree(int[] nums)
    {
        return ConstructMaximumBinaryTree(nums, 0, nums.Length - 1);
    }
    
    //helper func
    private TreeNode ConstructMaximumBinaryTree(int[] nums, int left, int right)
    {
        if (left > right)
        {
            return null;
        }
        
        int maxIndex = FindMaxIndex(nums, left, right);
        // Create a new TreeNode with the maximum value as its value
        TreeNode root = new TreeNode(nums[maxIndex]);
        
        root.left = ConstructMaximumBinaryTree(nums, left, maxIndex - 1);
        root.right = ConstructMaximumBinaryTree(nums, maxIndex + 1, right);
        
        return root;
    }
    
    private int FindMaxIndex(int[] nums, int left, int right)
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
}