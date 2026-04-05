import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:

        # pq = [(-count, value) for (value, count) in Counter(s).items()]
        pq = [(-count, value) for (value, count) in Counter(s).items()]
        heapq.heapify(pq)

        # buffer = ""
        buffer = ""

        # tmp
        tmp = None

        # while pq
        while pq:
            # top =  heapq.heappop(pq)
            top = heapq.heappop(pq)

            # buffer += top[1] # add to output string
            buffer += top[1]

            # top[0] += 1 # decreaes the count
            top = (top[0] + 1, top[1])  # tuple is immutable, create new one

            # if tmp and tmp[0] != 0:
            if tmp and tmp[0] != 0:
                # heapq.heappush(tmp)
                heapq.heappush(pq, tmp)
            
            # tmp = top
            tmp = top

        # if buffer[-1][1] == pq[0][1]:
        if tmp and tmp[0] != 0:
            return ""
        # else:
        else:
            return buffer