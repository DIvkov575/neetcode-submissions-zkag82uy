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
    pair<ListNode*, ListNode*> last_two(ListNode* head) {
        while (head->next->next) { head = head->next; }
        return {head, head->next};
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        
        ListNode* c1_head = head->next; // c1_head valid

        auto [prev, last] = last_two(c1_head); // !null
        head->next = last;
        head = head->next;
        prev->next = nullptr;

        head->next = c1_head;

        reorderList(head->next);
    }
};
