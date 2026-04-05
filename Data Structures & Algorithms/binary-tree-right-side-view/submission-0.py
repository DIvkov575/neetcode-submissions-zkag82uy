# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []

        out = []
        queue = [(root, 1)]
        mx = 0
        while len(queue) > 0:
            elt,lvl = queue.pop(0)
            if lvl > mx:
                mx = lvl
                out.append(elt.val)
            
            if elt.right:
                queue.append((elt.right, lvl+1))
            if elt.left:
                queue.append((elt.left,lvl+1))
        
        return out
