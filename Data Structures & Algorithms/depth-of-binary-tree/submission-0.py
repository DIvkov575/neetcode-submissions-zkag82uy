# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:


        def dfs(root, depth):
            if not root:
                return depth

            ld = dfs(root.left, depth+1)
            rd = dfs(root.right, depth+1)

            return max(ld, rd)

        return dfs(root, 0)
        