# 322. Coin Change
from typing import List
from functools import lru_cache
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        return self.dp(coins, amount, {})

    def dp(self, coins: List[int], amount: int, dpt: dict) -> int:
        if amount == 0:
            return 0
        if amount in dpt:
            return dpt[amount]
        need = float('inf')
        for coin in coins:
            if amount - coin >= 0:
                use_coin = self.dp(coins, amount - coin, dpt)
                if use_coin != -1:
                    need = min(need, use_coin + 1)
        dpt[amount] = need if need != float('inf') else -1
        return dpt[amount]