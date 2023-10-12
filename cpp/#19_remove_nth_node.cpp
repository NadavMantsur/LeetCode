// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the 
// list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // in case the list is empty
        if (head == nullptr)
            return nullptr;
        
        ListNode* prev = head;
        ListNode* curr = head;
        size_t numOfNodes = 0;

        // counting the num of nodes
        while (curr != nullptr)
        {
            if (curr->next != nullptr)
            {
                curr = curr->next;
                ++numOfNodes;
            }
            else
            {
                numOfNodes++;
                break;
            }
        }

        curr = head;

        // special case - removing the first element
        if (numOfNodes == n)
        {
            head = head->next;
            delete curr;
            return head;
        }

        // reach the node to remove and his prev
        for (size_t i = 0; i < numOfNodes - n; ++i)
        {
            prev = curr;
            curr = curr->next;
        }

        // removing the nth node by skipping it
        prev->next = curr->next;

        delete curr;
        return head;
    }
};