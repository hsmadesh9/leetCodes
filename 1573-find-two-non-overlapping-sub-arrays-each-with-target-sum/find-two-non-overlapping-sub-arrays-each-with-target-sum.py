from typing import List


class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)

        best = [float("inf")] * n

        left = 0
        total = 0
        answer = float("inf")

        for right in range(n):
            total += arr[right]

            while total > target:
                total -= arr[left]
                left += 1

            if total == target:
                current_length = right - left + 1

                if left > 0 and best[left - 1] != float("inf"):
                    answer = min(
                        answer,
                        current_length + best[left - 1]
                    )

                best[right] = current_length

            if right > 0:
                best[right] = min(best[right], best[right - 1])

        return -1 if answer == float("inf") else answer