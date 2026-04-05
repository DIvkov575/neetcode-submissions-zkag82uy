from collections import defaultdict, deque
from typing import List

class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        lastseen = [0] * n

        parents = defaultdict(int)
        children = defaultdict(list)
        for i in range(n):
            parents[i] = 0
        for preq in prerequisites:
            parents[preq[0]] += 1
            children[preq[1]].append(preq[0])
        
        ctr = 0

        queue = deque(node for node, pcount in parents.items() if pcount == 0)
        while queue:
            cur = queue.popleft()
            ctr += 1
            for child in children[cur]:
                parents[child] -= 1
                if parents[child] == 0:
                    queue.append(child)
        return n == ctr
                


