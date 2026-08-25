from typing import List

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        present = set(nums)

        multiple = k

        while multiple in present:
            multiple += k

        return multiple