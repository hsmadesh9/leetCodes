class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = []
        for i in range (n):
            if i >0 and nums[i]==nums [i -1]:
                continue 
            for j in range (i+1 , n ):
                if j >i+1 and nums[j]==nums[j-1]:
                    continue 
                l = j +1
                r = n-1 
                while l <r :
                    s = nums[i]+nums[j]+nums[l]+nums[r]
                    if s ==target :
                        ans.append((nums[i],nums[j],nums[l],nums[r]))
                        while l <r and nums[l]==nums[l+1]: #skip for c 
                            l+=1
                        l+=1
                    elif s >target :
                        r-=1
                    else :
                        l+=1
        return ans 
