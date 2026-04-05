# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return -1,-1
            
            ldep, ldiam = dfs(node.left)
            rdep, rdiam = dfs(node.right)

            max_dep = max(ldep, rdep) + 1
            max_diam = max(ldep+rdep+2, ldiam, rdiam)

            return max_dep, max_diam
        
        return dfs(root)[1]
        

