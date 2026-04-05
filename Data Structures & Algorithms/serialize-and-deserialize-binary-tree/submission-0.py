from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    # Encodes a tree to a single string.
    def serialize(self, root):
        if not root:
            return ""
    
        output = []
        queue = deque([root])
    
        while queue:
            node = queue.popleft()
            if node:
                output.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                output.append("null")
    
        return ",".join(output)

        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        data = data.split(",")
        def dfs(idx):
            if idx >= len(data) or data[idx] == " ": return None
            
            return TreeNode(data[idx], dfs(idx*2+1), dfs(idx*2+2))

        return dfs(0)