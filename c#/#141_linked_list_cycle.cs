/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution
{
    public bool HasCycle(ListNode head)
    {
        ListNode fast = head;
        ListNode slow = head;

        while (null != fast && null != fast.next)
        {
            fast = fast.next.next;
            slow = slow.next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
}