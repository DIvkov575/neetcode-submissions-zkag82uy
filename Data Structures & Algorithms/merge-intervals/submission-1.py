class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])

        i = 0
        while i < len(intervals):
            j = i + 1
            while j < len(intervals):
                if intervals[i][1] >= intervals[j][0]:
                    intervals[i][1] = max(intervals[i][1], intervals[j][1])
                    intervals.pop(j)
                else:
                    break
            i += 1

        return intervals
        