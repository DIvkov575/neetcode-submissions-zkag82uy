class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        # max_trees = -1

        # n = len(fruits)
        # idx1,idx2 = 0,0
        # t1, t2 = currently considered types

        # idx1 - lower bound of t2/t1 range
        # idx2 - first occurrence of t2 in contig sequence 
            # if
        # max_trees = idx2-idx1 + 1 # this is incomplete


        n = len(fruits)
        if n == 0: return 0

        t1 = fruits[0]
        idx1 = 0

        idx2 = 1
        while idx2 < n and fruits[idx2] == t1:
            idx2 += 1

        if idx2 < n: t2 = fruits[idx2]
        else: return n

        max_trees = idx2 +1


        for i in range(idx2, n):
            t_cur =  fruits[i]
            if t_cur == t2:
              pass
            elif t_cur == t1:
              t1, t2 = t2, t1
              idx2 = i
            else:
              max_trees = max(max_trees, i - idx1)
              t1, t2 = t2, t_cur
              idx1 = idx2
              idx2 = i
        
        max_trees = max(max_trees, n - idx1)

        return max_trees


        