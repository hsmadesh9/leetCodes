class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        if k == 1:
            return [n * (n + 1) // 2]

        ans = [0] * k
        freq = [0] * k

        for x in nums:
            r = x % k
            freq2 = [0] * k

            ans[r] += 1

            for j in range(k):
                prod = (j * r) % k
                freq2[prod] += freq[j]
                ans[prod] += freq[j]

            freq2[r] += 1
            freq = freq2

        return ans