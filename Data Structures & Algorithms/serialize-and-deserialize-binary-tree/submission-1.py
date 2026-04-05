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
    def deserialize(self, data):
        if not data:
            return None
    
        vals = data.split(",")
        root = TreeNode(int(vals[0]))
        queue = deque([root])
        i = 1
    
        while queue:
            node = queue.popleft()
    
            if vals[i] != "null":
                node.left = TreeNode(int(vals[i]))
                queue.append(node.left)
            i += 1
    
            if vals[i] != "null":
                node.right = TreeNode(int(vals[i]))
                queue.append(node.right)
            i += 1
    
        return root