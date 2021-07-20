class Solution:
    def check(self, nums: List[int]) -> bool:
        problems = 0
        prev = nums[0]
        for i in range(1, len(nums) + 1):
            num = nums[i % len(nums)]
            if prev > num:
                problems += 1
                if problems > 1:
                    return False
            prev = num
        return True
