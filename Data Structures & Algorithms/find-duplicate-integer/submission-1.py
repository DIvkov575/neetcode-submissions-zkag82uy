class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = 0
        fast = 0

        while (True):
            slow = (slow + 1) % len(nums)
            fast = (fast + 2) % len(nums)

            if nums[slow] == nums[fast]:
                return nums[slow]
