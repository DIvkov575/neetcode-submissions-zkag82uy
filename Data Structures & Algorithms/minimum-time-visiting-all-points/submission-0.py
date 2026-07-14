class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        acc = 0
        # acc += max(abs(points[0][0]), abs(points[0][1]))

        for i in range(0, len(points) -1):
            xd = abs(points[i][0] - points[i+1][0])
            yd = abs(points[i][1] - points[i+1][1])
            acc += max(xd,yd)
        
        return acc
