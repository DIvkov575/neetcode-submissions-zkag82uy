from collections import deque
from typing import Optional

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

        # 🔥 trim useless trailing nulls (big win on sparse trees)
        while output and output[-1] == "null":
            output.pop()

        return ",".join(output)

    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        if not data:
            return None

        vals = data.split(",")
        root = TreeNode(int(vals[0]))
        queue = deque([root])
        i = 1

        while queue and i < len(vals):
            parent = queue.popleft()

            # left child
            if i < len(vals) and vals[i] != "null":
                parent.left = TreeNode(int(vals[i]))
                queue.append(parent.left)
            i += 1

            # right child
            if i < len(vals) and vals[i] != "null":
                parent.right = TreeNode(int(vals[i]))
                queue.append(parent.right)
            i += 1

        return root