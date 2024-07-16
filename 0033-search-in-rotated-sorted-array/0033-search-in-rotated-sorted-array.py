class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        
        if nums[l] == target:
            return l
        elif nums[r] == target:
            return r
        
        def binary_search(nums: List[int], target: int, left: int, right: int) -> int:
            while left < right:
                mid = left + (right - left) // 2
                
                if nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid
                else:
                    return mid
                
            return -1
        
        # array was not rotated -> find from first to last
        if nums[l] <= nums[r]:
            return binary_search(nums, target, l, r)
        
        while l < r:
            m = l + (r - l) // 2
            if nums[m] < nums[r]:
                r = m
            else:
                l = m + 1
            
        # target < nums[0] -> it is in the right of pivot -> find from pivot to end
        if target < nums[0]:
            return binary_search(nums, target, l, len(nums) - 1)
        
        # else -> it is in the left of pivot -> find from begin to pivot
        return binary_search(nums, target, 0, l)
        
            