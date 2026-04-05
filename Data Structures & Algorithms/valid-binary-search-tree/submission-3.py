import math
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root: return True

        def dfs(root, l, h) -> bool:
            if root is None: return True

            if l < root.val < h:
                return dfs(root. left, l, root.val) and dfs(root.right, root.val, h)
            else:
                return False
            
            return True

        return dfs(root, -math.inf, math.inf)

                

                
            
            

        