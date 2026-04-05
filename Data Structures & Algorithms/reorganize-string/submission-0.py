import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:

        pq = [(-count, value) for (value, count) in Counter(s).items()]
        heapq.heapify(pq)
        buffer = ""
        tmp = None

        while pq:
            top = heapq.heappop(pq)
            buffer += top[1]  # add to output string
            top = (top[0] + 1, top[1])  # decrease the count (tuple is immutable)

            if tmp and tmp[0] != 0:
                heapq.heappush(pq, tmp)

            tmp = top

        # check for leftover count
        if tmp and tmp[0] != 0:
            return ""
        else:
            return buffer