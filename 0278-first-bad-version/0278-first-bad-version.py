# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r, a = 0, n, 0
        while l < r:
            m = l + (r - l)//2
            if isBadVersion(m) is True:
                r = m
            else:
                l = m + 1
        
        return l
                