import heapq

class Solution:
    def lastStoneWeight(self, hq: List[int]) -> int:
        hq = [-stone for stone in hq]
        heapq.heapify(hq)

        while len(hq) > 1:
            x = heapq.heappop(hq)
            y = heapq.heappop(hq)

            if x == y:
                continue
            else:
                heapq.heappush(hq, min(x,y)-max(x,y))
        
        if len(hq) == 0:
            return 0
        else:
            return -heapq.heappop(hq)
                


        