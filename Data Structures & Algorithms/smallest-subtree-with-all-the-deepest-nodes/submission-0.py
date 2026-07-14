class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
 
        def dfs(root: Optinoal[TreeNode]) -> (Optional[TreeNode], int):
            if not root:
                return (root, 0)

            lnode, ldepth = dfs(root.left)
            rnode, rdepth = dfs(root.right)

            if (ldepth > rdepth):
                return (lnode, ldepth + 1)
            elif (rdepth > ldepth):
                return (rnode, rdepth + 1)
            else:
                return (root, ldepth + 1)
            
        node, _ = dfs(root)
        return node
