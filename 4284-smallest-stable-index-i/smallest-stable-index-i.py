class Solution:
    def firstStableIndex(self, nums, k):
        n = len(nums)
        suffix = [0] * n
 
        mn = float('inf')
        # Build suffix minimum
        for i in range(n - 1, -1, -1):
            mn = min(mn, nums[i])
            suffix[i] = mn
 
        mx = 0
        # Find first index with score <= k
        for i in range(n):
            mx = max(mx, nums[i])
            score = mx - suffix[i]
            if score <= k:
                return i
 
        return -1