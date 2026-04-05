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
    ListNode* reverseList(ListNode* head) {
        if (head != nullptr) {
            ListNode* output = new ListNode(head->val, nullptr);
    
            while (head->next != nullptr) {
                head = head->next;
                output = new ListNode(head->val, output);
            }
    
            return output;
        } else {
            return nullptr;
        }
        
        
    }
};
