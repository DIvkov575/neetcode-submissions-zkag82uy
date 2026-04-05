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
    // propogates head n+1 times -> n+2 node
    ListNode* getNth(ListNode* head, int n) {
        while (head->next && n > 0) {
            --n;
            head = head->next;
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* chopped_shit_head = new ListNode(-1, head);
        ListNode* l = chopped_shit_head;
        ListNode* r = getNth(head, n-1);

        while (r->next) {
            l = l->next;
            r = r->next;
        } // left should point to end - (n + 1) point

        // delete l->next;
        // if (l->next && l->next->next) {
        //     // ListNdoe*
        l->next = l->next->next;

        // }
        return chopped_shit_head->next; 
    }
};
