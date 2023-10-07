/*struct ListNode {
    int val;
    struct ListNode *next;
};*/

struct ListNode* merge(struct ListNode* left, struct ListNode* right)
{
    struct ListNode dummy;
    struct ListNode* curr = &dummy;

    while (NULL != left && NULL != right)
    {
        if (left->val < right->val)
        {
            curr->next = left;
            left = left->next;
        }
        else
        {
            curr->next = right;
            right = right->next;
        }

        curr = curr->next;
    }

    /*merge the remains nodes*/
    if (NULL != left)
    {
        curr->next = left;
    }
    else
    {
        curr->next = right;
    }

    return dummy.next;
}

struct ListNode* mergeSort(struct ListNode* head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    /*reach the middle node*/
    while (NULL != fast && NULL != fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /*spliting the list to half*/
    struct ListNode* left = head;
    struct ListNode* right = slow->next;
    slow->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

struct ListNode* sortList(struct ListNode* head)
{
    return mergeSort(head);
}
