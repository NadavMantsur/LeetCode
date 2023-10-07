// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next) 
        {
            return head;
        }
        
        ListNode* newHead = head->next;
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (nullptr != curr && nullptr != curr->next)
        {
            ListNode *next = curr->next;

            if (nullptr != prev)
            {
                prev->next = next; //update prev->next to point to his new next.
            }

            curr->next = next->next;
            next->next = curr;

            prev = curr; //saving curr as prev for the next iteration.
            curr = curr->next;
        }

        return newHead;
    }
};