# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def pop_min(lists):
            min_idx, val = min([(idx,ll.val) for idx,ll in enumerate(lists)], key=lambda x: x[1])
    
            if lists[min_idx].next:
                lists[min_idx] = lists[min_idx].next
            else:
                lists.pop(min_idx)
    
            return val
        
        if len(lists) == 0:
            return None

        base = ListNode(pop_min(lists))
        head = base

        while len(lists) > 0:
            base.next = ListNode(pop_min(lists), None)
            base = base.next
        
        return head

        