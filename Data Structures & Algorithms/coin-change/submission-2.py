from collections import deque
from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0: return 0

        visited = {0: 0}  # sum -> count
        queue = deque([0])  # queue holds sums

        while queue:
            cur = queue.popleft()
            for coin in coins:

                if coin + cur > amount:
                    continue
                elif coin + cur in visited:
                    if visited[coin + cur] > visited[cur] + 1:
                        visited[coin + cur] = visited[cur] + 1
                        queue.append(coin + cur)
                    else:
                        continue
                else:
                    visited[coin + cur] = visited[cur] + 1
                    queue.append(coin + cur)

        if amount in visited:
            return visited[amount]
        else:
            return -1