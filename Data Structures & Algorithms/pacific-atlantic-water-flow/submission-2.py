class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        directions = [(1,0), (0,1), (-1,0), (0,-1)]
        n = len(heights)
        m = len(heights[0])

        reaching = {}

        def dfs(cur) -> Tuple[bool,bool]:
            nonlocal visited

            l,r = False, False

            if cur in visited:
                return reaching.get(cur, (False, False))


            visited.add(cur)

            for (dy,dx) in directions:
                nexy,nexx = cur[0]+dy, cur[1]+dx

                if nexy < 0 or nexx < 0:
                    l |= True
                elif nexx >= m or nexy >= n:
                    r |= True
                elif heights[nexy][nexx] <= heights[cur[0]][cur[1]]:
                    lx, rx = dfs((nexy, nexx))
    
                    l |= lx
                    r |= rx
    
                    if l and r:
                        reaching[cur] = (True, True)
                        return (True, True)
            
            reaching[cur] = (l,r)
            

            return l, r

                
                    

            

        for i in range(n):
            for j in range(m):
                visited= set()
                dfs((i,j))

        return [key for key,value in reaching.items() if value[0] and value[1]]

                
        