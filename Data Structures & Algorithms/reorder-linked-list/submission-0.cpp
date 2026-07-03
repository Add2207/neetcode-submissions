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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        ListNode *curr = head2;

        while (curr)
        {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        head2 = prev;

        ListNode *p1 = head;
        ListNode *p2 = head2;

        while (p1 && p2)
        {
            ListNode *p1Next = p1->next;
            ListNode *p2Next = p2->next;

            p1->next = p2;
            p2->next = p1Next;

            p1 = p1Next;
            p2 = p2Next;
        }
    }
};