class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        i = 0
        while i < len(intervals) and intervals[i][0] < newInterval[0]: i += 1
        intervals.insert(i, newInterval)

        i = 0
        while i < len(intervals) - 1:
            while i+1 < len(intervals) and intervals[i][1] >= intervals[i+1][0]:
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1])
                intervals.pop(i+1)
            i += 1
        
        return intervals



        