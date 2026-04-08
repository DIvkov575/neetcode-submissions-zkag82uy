from collections import defaultdict, deque
from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        E = defaultdict(list)
        icounts = defaultdict(int)

        for word in words:
            for c in word:
                icounts[c] = 0

        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]

            if len(w1) > len(w2) and w1.startswith(w2):
                return ""

            for j in range(min(len(w1), len(w2))):
                if w1[j] != w2[j]:
                    E[w1[j]].append(w2[j])
                    break

        for u in E:
            for v in E[u]:
                icounts[v] += 1

        queue = deque([c for c in icounts if icounts[c] == 0])
        output = []

        while queue:
            cur = queue.popleft()
            output.append(cur)

            for nei in E[cur]:
                icounts[nei] -= 1
                if icounts[nei] == 0:
                    queue.append(nei)

        if len(output) != len(icounts):
            return ""

        return "".join(output)