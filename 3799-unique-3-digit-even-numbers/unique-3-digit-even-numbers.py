class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = [0] * 10

        for digit in digits:
            freq[digit] += 1

        answer = 0

        for first in range(1, 10):
            for second in range(10):
                for third in range(0, 10, 2):
                    if freq[first] == 0 or freq[second] == 0 or freq[third] == 0:
                        continue

                    if first == second == third and freq[first] < 3:
                        continue

                    if first == second and freq[first] < 2:
                        continue

                    if first == third and freq[first] < 2:
                        continue

                    if second == third and freq[second] < 2:
                        continue

                    answer += 1

        return answer