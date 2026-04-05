# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        def dfs(root, ):
            if not root:
                return -1,0

            lp, ld = dfs(root.left)
            rp, rd = dfs(root.right)

            mp = max(lp, rp) + 1
            md = max(lp+rp+2, ld, rd)

            return mp, md

        _, md = dfs(root)
        return md
        