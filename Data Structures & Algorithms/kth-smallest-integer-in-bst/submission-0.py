# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        def dfs(root, count) -> (int, TreeNode):
            nonlocal k
            if not root: return 0, None

            lc, ln = dfs(root.left, count)
            
            if ln: return -1, ln
            if count + lc + 1 == k: return -1, root
                
            rc, rn = dfs(root.right, count + lc + 1)
            if rn: return -1, rn
            
            return lc + rc + 1, None

        return dfs(root, 0)[1].val