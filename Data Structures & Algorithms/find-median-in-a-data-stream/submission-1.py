class MedianFinder:

    def __init__(self):
        self.ctr = 0
        self.minh = []
        self.maxh = []
        

    def addNum(self, num: int) -> None:
        if not self.maxh or num <= -self.maxh[0]:
            heapq.heappush(self.maxh, -num)
        else:
            heapq.heappush(self.minh, num)

        self.ctr += 1
        

    def findMedian(self) -> float:
        while len(self.minh) - len(self.maxh) > 1:
            heapq.heappush(self.maxh, -self.minh[0])
            heapq.heappop(self.minh)

        while len(self.maxh) - len(self.minh) > 1:
            heapq.heappush(self.minh, -self.maxh[0])
            heapq.heappop(self.maxh)

        if len(self.minh) ==0: return -self.maxh[0]
        if len(self.maxh) ==0: return self.minh[0]

        if len(self.maxh) > len(self.minh):
            return -self.maxh[0]
        elif len(self.maxh) < len(self.minh):
            return self.minh[0]
        else:
            return -self.maxh[0] + (self.minh[0] + self.maxh[0])/2


            
 