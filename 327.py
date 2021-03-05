import bisect


class Solution:
    def countRangeSum(self, nums, lower: int, upper: int) -> int:
        res, pre, now = 0, [0], 0
        # now 0 -2 3 2
        # pre [0] [-2 0] [-2 0 3] [-2 0 2 3]
        for n in nums:
            now += n
            print("@", bisect.bisect_right(pre, now - lower))
            # pre= [0]      now - lower=-2-(-2)=0  ->1
            # pre= [-2 0]   now - lower=3-(-2)=5  -> 2
            print("#", bisect.bisect_left(pre, now - upper))
            # pre = [0],now -upper =-2-2=-4  --- >0
            # pre = [-2,0],now -upper =3-2=1  --- >2
            res += bisect.bisect_right(pre, now - lower) - bisect.bisect_left(pre, now - upper)# 1
            bisect.insort(pre, now)
        return res


s = Solution()
a = s.countRangeSum([-2, 5, -1], -2, 2)
# print(a)
