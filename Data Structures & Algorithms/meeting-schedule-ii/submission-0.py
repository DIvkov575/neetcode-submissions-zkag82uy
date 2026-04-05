import heapq
"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        
        # action == 0 -> start
        # action == 1 -> end

        actions = sum([[(interval.start, 1),(interval.end, 0)] for interval in intervals], []) # (time, actino) 

        heapq.heapify(actions) # min heap (earlier time, then dequee)

        max_ctr = 0
        ctr = 0
        while actions:
            time, action = heapq.heappop(actions)
            if action == 0:
                ctr -= 1
            else:
                ctr += 1
            
            max_ctr = max(max_ctr, ctr)

        return max_ctr
