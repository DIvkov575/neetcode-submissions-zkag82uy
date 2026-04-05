# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:

        def dfs(root):
            nonlocal p,q

            if not root: return False, None
            
            lt, ln = dfs(root.left)
            rt, rn = dfs(root.right)

            if ln: return True, ln
            elif rn: return True, rn

            if lt and rt:
                return True, root
            elif (lt and not rt) or (rt and not lt):
                if (root == p) or (root == q):
                    return True, root
                else: return True, None
            elif (root == p) or (root == q):
                return True, None
            else:
                return False, None


        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return root