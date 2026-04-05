class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
    
        while l < r:
            m = l + (r - l) // 2  
    
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        
        num_rots = l
        nums = nums[l:len(nums)] + nums[0: l]

        # print(nums)
        l = 0
        r = len(nums) - 1
        while (l < r): 
            m = l + (r - l + 1) // 2

            if target >= nums[m]:
                l = m
            else:
                r = m - 1

        print(l, num_rots) 

        if nums[l] == target:
            return (l + num_rots) % len(nums)
        else:
            return -1