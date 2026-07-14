# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        #BFS
        if not root:
            return 0
        dq = deque([(root,1)])
        while dq:
            node,depth = dq.popleft()
            if not node.left and not node.right:
                return depth
            if node.left:
                dq.append((node.left, depth+1))
            if node.right:
                dq.append((node.right, depth+1))
        return 0

        #DFS
        # if not root:
        #     return 0

        # def dfs(root, depth):

        #     ld = dfs(root.left, depth+1) if root.left else None
        #     rd = dfs(root.right, depth+1) if root.right else None

        #     if not ld and not rd:
        #         return depth
        #     elif not ld:
        #         return rd
        #     elif not rd:
        #         return ld
        #     else:
        #         return ld if ld < rd else rd

        # return dfs(root, 1)
