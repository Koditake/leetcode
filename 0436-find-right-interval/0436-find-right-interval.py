class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        if n == 0:
            return []

        # Create a list of (start, end, original index)
        indexed_intervals = [(intervals[i][0], intervals[i][1], i) for i in range(n)]

        # Sort intervals based on start point
        indexed_intervals.sort()

        result = [-1] * n  # Initialize result array

        for i in range(n):
            end_i = intervals[i][1]

            # Binary search to find the smallest index j such that intervals[j][0] >= end_i
            low, high = 0, n - 1
            while low <= high:
                mid = (low + high) // 2
                if indexed_intervals[mid][0] < end_i:
                    low = mid + 1
                else:
                    high = mid - 1

            # If low is within bounds and indexed_intervals[low][0] >= end_i
            if low < n and indexed_intervals[low][0] >= end_i:
                result[i] = indexed_intervals[low][2]  # Get the original index

        return result
