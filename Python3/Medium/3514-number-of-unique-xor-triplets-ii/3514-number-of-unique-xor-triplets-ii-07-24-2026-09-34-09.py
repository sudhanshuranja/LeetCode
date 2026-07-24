class Solution:
    def uniqueXorTriplets(self, nums):
        vals = list(set(nums))

        MAXX = 2048  # nums[i] <= 1500, so XOR fits in 11 bits

        pair = [False] * MAXX
        for a in vals:
            for b in vals:
                pair[a ^ b] = True

        ans = [False] * MAXX
        for x in range(MAXX):
            if pair[x]:
                for v in vals:
                    ans[x ^ v] = True

        return sum(ans)