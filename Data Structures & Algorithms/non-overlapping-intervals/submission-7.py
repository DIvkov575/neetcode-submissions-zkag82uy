class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda x: x[0])

        ctr = 0

        last_end = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= last_end:
                last_end = intervals[i][1]
            else:
                ctr += 1
                last_end = min(last_end, intervals[i][1])
            
            
        return ctr
                

        