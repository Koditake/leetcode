class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        
        while l <= r:
            m = l + (r - l) // 2
            mid = nums[m]
            
            if mid < target:
                l = m + 1
            elif mid > target:
                r = m - 1
            else: 
                return m
            
        return l