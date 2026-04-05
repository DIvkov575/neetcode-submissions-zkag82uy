# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        ctr = 0;

        def dfs(root, maxv):
            nonlocal ctr
            if not root:
                return

            if root.val >= maxv:
                ctr += 1

            maxv = max(root.val, maxv)

            dfs(root.left, maxv)
            dfs(root.right, maxv)
            

        dfs(root, root.val);

        return ctr;