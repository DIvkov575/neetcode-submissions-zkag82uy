from collections import defaultdict, deque
from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        E = defaultdict(list)
        icounts = defaultdict(int)

        # initialize all characters
        for word in words:
            for c in word:
                icounts[c] = 0

        for i in range(len(words)-1):
            flag = True  # moved outside

            # prefix invalid case
            if len(words[i]) > len(words[i+1]) and words[i].startswith(words[i+1]):
                return ""

            for idx in range(min(len(words[i]), len(words[i+1]))):
                if flag and words[i][idx] != words[i+1][idx]:
                    E[words[i][idx]].append(words[i+1][idx])
                    flag = False
                    break  # IMPORTANT

        # topo sort
        
        for (key, values) in E.items():
            for value in values:
                icounts[value] += 1

        output = []
        zeros = [key for (key,value) in icounts.items() if value == 0]
        queue = deque(zeros)

        while queue:
            cur = queue.popleft()
            output.append(cur)

            for child in E[cur]:
                icounts[child] -= 1
                if icounts[child] == 0: 
                    queue.append(child)
        
        # cycle check fix
        if len(output) != len(icounts):
            return ""
        else:
            return "".join(output)