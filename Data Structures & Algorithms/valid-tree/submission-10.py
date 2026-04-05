from collections import defaultdict, deque
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

        queue = deque([0])
        while queue:
            cur = queue.popleft()

            visited.add(cur)

            for child in graph[cur]:
                if child not in visited:
                    queue.append(child)

        return len(visited) == n
        


            





        # parents = [i for i in range(n)]
        # degree = [1 for i in range(n)]

        # for a,b in (edge[0], edge[1] for edge in edges):
        #     x
    