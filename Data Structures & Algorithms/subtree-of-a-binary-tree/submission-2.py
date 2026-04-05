# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
        def check(a, b) -> bool:
            if not a and not b:
                return True
            if not a or not b:
                return False
            if a.val != b.val:
                return False

            return check(a.left, b.left) and check(a.right, b.right)


        queue = [root]
        while len(queue) != 0:
            elt = queue.pop();
            print(elt.val)
            if check(elt, subRoot):
                return True
            
            if elt.left: queue.append(elt.left)
            if elt.right: queue.append(elt.right)

        return False
            