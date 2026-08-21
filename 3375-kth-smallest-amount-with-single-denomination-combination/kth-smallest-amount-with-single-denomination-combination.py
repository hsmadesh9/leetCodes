from typing import List
from math import gcd
class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        def count(x):
            total=0
            n=len(coins)

            for mask in range(1,1<<n):
                lcm=1
                bits=0
                valid=True

                for i in range(n):
                    if mask & (1 <<i):
                        bits+=1
                        lcm=lcm * coins[i]//gcd(lcm,coins[i])

                        if lcm > x:
                            valid=False
                            break
                if valid:
                    amount=x //lcm

                    if bits %2 == 1:
                        total += amount
                    else:
                        total -= amount
            return total
        
        low=1
        high=min(coins) * k

        while low < high:
            mid=(low+high)//2

            if count(mid)>= k:
                high=mid
            else:
                low=mid+1
        return low