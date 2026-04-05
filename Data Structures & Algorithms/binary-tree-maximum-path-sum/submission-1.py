# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if not root:
                return 0, 0

            ld, lm = dfs(root.left) if root.left else (None, None)
            rd, rm = dfs(root.right) if root.right else (None, None)

            if ld and rd:
                lhs =max(ld,rd,0)+root.val
                return lhs, max(lm, rm, ld+rd+root.val, lhs)
            elif ld and not rd:
                lhs = max(ld, 0) + root.val
                return lhs, max(lm, lhs)
            elif rd and not ld:
                lhs = max(rd, 0) + root.val
                return lhs, max(rm, lhs)
            else:
                return root.val, root.val
            


        
        return dfs(root)[1]

                
        