"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        visited = {None: None}

        def dfs(root):
            if root in visited:
                return visited[root] 

            visited[root] = Node(root.val)
            visited[root].neighbors = [dfs(neighbor) for neighbor in root.neighbors]
            return visited[root]

        return dfs(node)
            


                
        