/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

ex1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

ex2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* tail = dummy;
    int carry = 0;

    while (NULL != l1 || NULL != l2)
    {
        int sum = carry;

        if (NULL != l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (NULL != l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;
        
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = sum;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }
    
    /*the last one*/
    if (0 < carry)
    {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = carry;
        new_node->next = NULL;
        tail->next = new_node;
    }

    return dummy->next;
}