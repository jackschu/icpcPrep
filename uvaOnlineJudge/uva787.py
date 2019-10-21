from sys import stdin
import math


def solve(nums):
    n = len(nums)
    if n == 0:
        return -math.inf
    if n == 1:
        return nums[0]
    if 0 in nums:
        idx = nums.index(0)
        return max(0, solve(nums[:idx]), solve(nums[idx + 1 :]))
    else:
        mem = []
        prod = 1
        for elem in nums:
            prod *= elem
            mem.append(prod)
        out = -math.inf
        for i in range(n):
            for j in range(i, n):
                cur = mem[j] // (1 if i == 0 else mem[i - 1])
                out = max(out, cur)
        return out


sending = []
for line in stdin:
    cur_nums = list(map(int, line.split()))
    if len(cur_nums) == 0:
        continue
    sending += cur_nums
    if -999999 in cur_nums:
        sending.pop()
        print(int(solve(sending)))
        sending = []
