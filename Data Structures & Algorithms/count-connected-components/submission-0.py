from collections import defaultdict, deque
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for a,b in ((edge[0], edge[1]) for edge in edges):
            graph[a].append(b)
            graph[b].append(a)

        ctr = 0
        visited = set()

        for i in range(n):
            if i in visited:
                continue

            ctr += 1
            queue = deque([i])
            while queue:
                cur = queue.popleft()

                for child in graph[cur]:
                    if child not in visited:
                        visited.add(child)
                        queue.append(child)
        
        return ctr


        