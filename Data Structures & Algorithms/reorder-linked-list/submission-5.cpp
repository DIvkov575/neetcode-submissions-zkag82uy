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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = reverse(slow->next);
        slow->next = nullptr;
        ListNode* l1 = head;

        while (l1 && l2) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;

            l1->next = l2;
            l2->next = tmp1;

            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
