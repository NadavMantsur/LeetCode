struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev = NULL;
    struct ListNode *nextNode;

    while (head != NULL)
    {
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    return prev;
}