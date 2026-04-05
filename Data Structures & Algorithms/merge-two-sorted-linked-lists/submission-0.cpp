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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) { return list2; } 
        if (!list2) { return list1; }

        ListNode* basenode;
        ListNode* lastnode;
        if (list1->val <= list2->val) {
            lastnode = basenode = list1;
            list1 = list1->next;
        } else {
            lastnode = basenode = list2;
            list2 = list2->next;
        }

        while (list1 || list2) {
            int lnv = lastnode? lastnode->val: 0 ;
            int l1v = list1? list1->val: 0 ;
            int l2v = list2? list2->val: 0 ;
            if (!list1) {
                lastnode->next = list2;
                list2 = list2->next;
                lastnode = lastnode->next;
            } else if (!list2) {
                lastnode->next = list1;
                list1 = list1->next;
                lastnode = lastnode->next;
            } else {
                if (list1->val <= list2->val) {
                    lastnode->next = list1;
                    list1 = list1->next;
                    lastnode = lastnode->next;
                } else {
                    lastnode->next = list2;
                    list2 = list2->next;
                    lastnode = lastnode->next;
                }
            }
        }

        return basenode;

            
        

    }
};