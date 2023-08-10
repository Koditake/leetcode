# This is for the case that the pivot index is duplicated in the array
# ie, [1,2,3,4,4,4,4] => [4,4,1,2,3,4,4]


def search(self, nums, target):
    # when nums[mid] == pivot, it's impposible to decision whether you should move the 
    # lower bound or upper bound
    if not nums: return False
    pivot = nums[0]
    if target == pivot: return True

    # !!key!! 
    # we move lo and hi so pivot will never equal to lo or hi
    lo, hi = 0, len(nums) - 1
    while hi >= 0 and nums[hi] == pivot:
        hi -= 1
    while lo <= len(nums) - 1 and nums[lo] == pivot:
        lo += 1
        
    # now we can just blindly copy the code from search-in-rotated-sorted-array-i
    while lo <= hi:
        mid = (hi - lo) // 2 + lo
        if nums[mid] == target:
            return True
        if nums[mid] < pivot:
            # mid is on the upper side
            if nums[mid] < target < pivot:
                lo = mid + 1
            else:
                hi = mid - 1
        if nums[mid] > pivot:
            if pivot < target < nums[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
    return False