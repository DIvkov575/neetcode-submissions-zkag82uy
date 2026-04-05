# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # visited = set()

        def dfs(poi, iol, ior) -> TreeNode:
            if ior - iol == 1: return TreeNode(inorder[iol])
            if ior - iol == 0: return None

            while preorder[poi] not in inorder[iol:ior]: poi += 1
            val = preorder[poi]

            partition_idx = iol + inorder[iol:ior].index(val)

            return TreeNode(inorder[partition_idx], dfs(poi+1, iol, partition_idx), dfs(poi+1, partition_idx+1, ior))

        return dfs(0, 0, len(inorder))

        







