class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mxv = nums[0]

        n = len(nums)
        dp = [[1 for _ in range(n)] for _ in range(n)]

        for i in range(n):
            dp[i][i] = nums[i]
            mxv = max(mxv, dp[i][i])
        
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i+length-1
                dp[i][j] = nums[i]*dp[i+1][j]
                mxv = max(mxv, dp[i][j])

        return mxv
