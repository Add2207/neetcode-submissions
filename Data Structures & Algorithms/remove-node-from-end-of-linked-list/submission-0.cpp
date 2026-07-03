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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        int size = 0;
        while(curr != NULL)
        {
            size++;
            curr= curr->next;
        }
        if(n == size)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        int desired = size-n;
        curr = head;
        while(--desired > 0)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};
