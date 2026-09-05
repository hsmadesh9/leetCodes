class Solution:
    def firstStableIndex(self, nums, k):
        n = len(nums)

        ansIdx = 0            # index we're currently testing as the answer
        globalMax = float('-inf')       # biggest number seen anywhere so far
        ansMax = float('-inf') # biggest number up to ansIdx

        for i in range(n):
            globalMax = max(globalMax, nums[i])

            # only update the candidate's max while we're still inside its prefix
            if i == ansIdx:
                ansMax = max(ansMax, nums[i])

            # this number is below the allowed floor, jump past it
            if nums[i] < ansMax - k:
                ansIdx = i + 1
                ansMax = globalMax

        return ansIdx if ansIdx < n else -1