class Solution:
    def majorityElement(self, nums):
        def dfs(l, r):
            if l == r:
                return nums[l]
    
            m = (l + r) // 2
            left = dfs(l, m)
            right = dfs(m + 1, r)
    
            if left == right:
                return left
    
            left_count = sum(1 for i in range(l, r+1) if nums[i] == left)
            right_count = sum(1 for i in range(l, r+1) if nums[i] == right)
    
            return left if left_count > right_count else right
    
        return dfs(0, len(nums)-1)


        