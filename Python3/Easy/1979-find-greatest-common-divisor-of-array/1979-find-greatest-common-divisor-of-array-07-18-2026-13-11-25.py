class Solution:
    def findGCD(self, nums: List[int]) -> int:
        mn, mx = min(nums), max(nums)
        while mx % mn != 0:
            mn, mx = mx % mn, mn
        return mn