The QuickSelect algorithm is an efficient method to find the kkk-th smallest (or largest) element in an unordered list without sorting the entire list. It works similarly to the QuickSort algorithm but only recurses into one half of the data.
Key Data Structures:

    List/Array: We use Python's built-in list for this approach. The algorithm modifies the list in place.
    Pivot: An element chosen from the list, around which the list gets partitioned.

Step-by-step Breakdown:

    Initialization:
        Set the left boundary to the beginning of the list and the right boundary to the end of the list.

    Pivot Selection:
        Randomly select a pivot index between the left and right boundaries.

    Partitioning:
        Move all elements smaller than the pivot to its left and all larger elements to its right.
        Return the final position of the pivot after the partitioning.

    Check Pivot Position:
        If the position of the pivot is the desired kkk-th largest index, return the pivot.
        If the pivot's position is greater than the desired index, adjust the right boundary and repeat.
        If the pivot's position is lesser than the desired index, adjust the left boundary and repeat.

    Result:
        The function will eventually return the kkk-th largest element in the original list.
