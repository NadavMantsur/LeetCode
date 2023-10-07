/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public int CountNodes(ListNode head)
    {
        int cnt = 0;
        ListNode curr = head;

        while (null != curr)
        {
            curr = curr.next;
            ++cnt;
        }

        return cnt;
    }

    public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
    {
        int cnt1 = CountNodes(headA);
        int cnt2 = CountNodes(headB);

        while (cnt1 > cnt2)
        {
            headA = headA.next;
            --cnt1;
        }
        
        while (cnt1 < cnt2)
        {
            headB = headB.next;
            --cnt2;
        }

        while (null != headA)
        {
            if (headA == headB)
            {
                return headA;
            }

            headA = headA.next;
            headB = headB.next;
        }

        return null;
    }
}