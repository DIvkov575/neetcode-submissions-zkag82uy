class Solution:
            
    def sumFourDivisors(self, nums: List[int]) -> int:
        def check_divisibility(x: int):
            solutions = set()
            for i in range(2, int(x**0.5)+1):
                if x%i == 0:
                    # solutions |= {i, x//i}
                    solutions = set.union(solutions, set([i, x//i]))
    
                    if len(solutions) > 2:
                        return 0
            
            if len(solutions) == 2:
                return sum(solutions | {1, x})
            else:
                return 0

        return sum( [check_divisibility(num) for num in nums])
        # foo = [check_divisibility(num) for num in nums]
        # print(foo)
        # return sum(reduce(set.union, foo))
