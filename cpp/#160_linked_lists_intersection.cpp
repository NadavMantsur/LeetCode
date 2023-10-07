/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int CountNodes(struct ListNode *head)
    {
        int cnt = 0;
        struct ListNode *curr = head;

        while (nullptr != curr)
        {
            curr = curr->next;
            ++cnt;
        }

        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
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

        while (nullptr != headA)
        {
            if (headA == headB)
            {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;   
    }
};