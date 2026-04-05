from collections import defaultdict
from copy import deepcopy

# class Solution:
#     def validTree(self, n: int, edges: List[List[int]]) -> bool:
#         if len(edges) != n - 1:
#             return False

#         parent = list(range(n))
#         rank = [0] * n

class Solution:
    def validTree(self, n, edges):
        if len(edges) != n - 1:
            return False
    
        graph = defaultdict(list)
        for a,b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = set()
    
        def dfs(node, parent):
            for child in (xchild for xchild in graph[node] if xchild != parent):
                if child in visited:
                    return False

            visited.add(node)
            for child in (xchild for xchild in graph[node] if xchild != parent):
                if not dfs(child, node): return False
                
            return True




        return dfs(0, -1) and len(visited) == n
    