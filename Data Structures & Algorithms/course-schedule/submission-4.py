from collections import defaultdict
from typing import List

class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        # Build parent -> children map
        children_map = defaultdict(set)
        for course, pre in prerequisites:
            children_map[pre].add(course)

        # Memoize descendants for each course
        descendants = {}

        def dfs(cur, visiting):
            if cur in visiting:
                # Cycle detected
                return False
            if cur in descendants:
                # Already processed, no cycle here
                return True

            visiting.add(cur)
            all_descendants = set()

            for child in children_map[cur]:
                # DFS to collect descendants of child
                if not dfs(child, visiting):
                    return False
                # If child is already a descendant of current, cycle
                if child in all_descendants:
                    return False
                all_descendants.update(descendants[child])
                all_descendants.add(child)

            descendants[cur] = all_descendants
            visiting.remove(cur)
            return True

        for course in range(n):
            if not dfs(course, set()):
                return False

        return True