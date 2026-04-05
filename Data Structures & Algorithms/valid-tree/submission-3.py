class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        parent = list(range(n))
        rank = [0] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return False

            if rank[pa] < rank[pb]:
                parent[pa] = pb
            elif rank[pb] < rank[pa]:
                parent[pb] = pa
            else:
                parent[pb] = pa
                rank[pa] += 1
            return True

        for a, b in edges:
            if not union(a, b):
                return False

        return True