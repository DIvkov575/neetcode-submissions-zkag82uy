class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        res = [gas[0] - cost[0]]
        for i in range(1,n):
            res.append(res[i-1] + gas[i] - cost[i])

        mindx = min(range(n), key=res.__getitem__)
        mindx = (mindx+1)%n


            # check for neg
        res = [gas[mindx] - cost[mindx]] * n
        if gas[mindx] - cost[mindx] < 0: return -1
        for i in range(1,n):
            res[(mindx+i)%n] = res[(mindx+i-1)%n] + gas[(mindx+i)%n] - cost[(mindx+i)%n]
            if res[(mindx+i)%n] < 0: return -1
        
        return mindx
        

        


