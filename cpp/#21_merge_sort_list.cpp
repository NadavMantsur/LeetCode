// 21. Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

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
    // space complexity: O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* mergedList = new ListNode();
        ListNode* current = mergedList;

        while (nullptr != list1 && nullptr != list2)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }
        
        if (nullptr != list1)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }
        
        ListNode* mergedHead = mergedList->next;
        delete mergedList;
        
        return mergedHead;
    }

    // more elegant Solution
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0); //defualt value
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } 
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // check remaining nodes in list1 or list2
    tail->next = list1 ? list1 : list2;

    return dummy.next;
    }
};