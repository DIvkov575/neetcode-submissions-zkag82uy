
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev_link = dummy  

        while True:
            
            node = prev_link
            for i in range(k):
                node = node.next
                if not node:
                    return dummy.next  

            
            curr = prev_link.next  
            nex = curr.next
            for i in range(k-1):
                tmp = nex.next
                nex.next = curr
                curr = nex
                nex = tmp

            
            tail = prev_link.next  
            prev_link.next = curr  
            tail.next = nex        

            prev_link = tail