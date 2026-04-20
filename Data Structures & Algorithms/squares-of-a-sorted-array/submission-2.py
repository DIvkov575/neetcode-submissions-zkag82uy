class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        split_idx = 0
        while split_idx < len(nums) and nums[split_idx] < 0: split_idx += 1
        negatives = [x*x for x in nums[:split_idx]][::-1]
        positives = [x*x for x in nums[split_idx:]]

        pt1 = 0
        pt2 = 0
        while pt1 + pt2 < len(nums):
            if pt1 >= len(negatives):
                nums[pt1 + pt2] = positives[pt2]
                pt2 += 1
            elif pt2 >= len(positives):
                nums[pt1 + pt2] = negatives[pt1]
                pt1 += 1
            elif negatives[pt1] < positives[pt2]:
                nums[pt1 + pt2] = negatives[pt1]
                pt1 += 1
            else:
                nums[pt1 + pt2] = positives[pt2]
                pt2 += 1
        
        return nums

        