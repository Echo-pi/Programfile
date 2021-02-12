#include <stdio.h>
#include <stdlib.h>
//Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    ListNode *pTail;
    ListNode *newhead;
    if (NULL == l1)
    {
        return l2;
    }
    else if (NULL == l2)
    {
        return l1;
    }
    else
    {
        if (l1->val < l2->val)
        {
            newhead = l1;
            l1 = l1->next;
        }
        else
        {
            newhead = l2;
            l2 = l2->next;
        }
        pTail = newhead; //指向第一个节点
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                pTail->next = l1;
                l1 = l1->next;
            }
            else
            {
                pTail->next = l2;
                l2 = l2->next;
            }
            pTail = pTail->next;
        }
        if (NULL = l1)
            pTail->next = l2;
        else
            pTail->next = l1;
    }
    return newhead;
}