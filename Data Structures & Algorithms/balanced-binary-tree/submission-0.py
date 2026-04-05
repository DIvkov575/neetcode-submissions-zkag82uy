# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, height):
            if not root:
                return height, False

            lh, ls = dfs(root.left, height+1)
            rh, rs = dfs(root.right, height+1)

            if ls or rs: return 0,True

            Mh = max(lh, rh)
            mh = min(lh, rh)

            if Mh - mh > 1:
                return 0,True
            else:
                 return Mh, False

        _, state = dfs(root,0)
        return not state


