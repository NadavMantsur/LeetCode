/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int CountNodes(struct ListNode *head)
{
    int cnt = 0;
    struct ListNode *curr = head;

    while (NULL != curr)
    {
        curr = curr->next;
        ++cnt;
    }

    return cnt;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int cnt1 = CountNodes(headA);
    int cnt2 = CountNodes(headB);

    while (cnt1 > cnt2)
    {
        headA = headA->next;
        --cnt1;
    }
    
    while (cnt1 < cnt2)
    {
        headB = headB->next;
        --cnt2;
    }

    while (NULL != headA)
    {
        if (headA == headB)
        {
            return headA;
        }

        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}