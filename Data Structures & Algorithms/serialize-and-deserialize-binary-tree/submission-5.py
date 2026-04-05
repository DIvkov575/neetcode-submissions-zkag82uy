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

        while output and output[-1] == "null":
            output.pop() 

        return ",".join(output)

            
    def deserialize(self, data: str) -> Optional[TreeNode]:
        if not data:
            return None

        data = data.split(",")
        root = TreeNode(data[0])
        queue = deque([root])
        lr = 0

        for i in range(1,len(data)):
            node = data[i]
            if lr == 0:
                if node == "null":
                    queue[0].left = None
                else:
                    queue[0].left = TreeNode(node)
                    queue.append(queue[0].left)
                lr ^= 1
            elif lr == 1:
                if node == "null":
                    queue[0].right= None
                else:
                    queue[0].right = TreeNode(node)
                    queue.append(queue[0].right)
                queue.popleft()
                lr ^= 1
        
        return root



        
