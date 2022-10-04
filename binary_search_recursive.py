"""Recursive approach of binary search.
   Ref : https://en.wikipedia.org/wiki/Binary_search_algorithm

   Time Complexity : O(log n)
   Space Complexity : O(1)
"""


def find_index(nums: list, k: int, left: int, right: int) -> int:
    """_summary_
    Args:
        nums (list): list of numbers
        k (int): number to be find from the list
        left (int): lower bound
        right (int): upper bound
    Returns:
        int: index of k in list or -1 if k is not found in list
    Examples
    --------
    >>> find_index([1,4,5,6,7],6,0,5)
    3
    >>> find_index([1,4,5,6,7],2,0,5)
    -1
    """
    # Base case
    if left >= right:
        return -1

    else:
        mid = (left + right) // 2

        if nums[mid] == k:
            return mid
        elif nums[mid] > k:
            return find_index(nums, k, left, mid)
        else:
            return find_index(nums, k, mid + 1, right)


def binary_search(nums: list, k: int, n: int) -> int:
    """This function uses divide & conquer paradigm to find the number in a sorted list
     and return its index.
    Args:
        nums (list): list of numbers
        k (int): number to be find from the list
        n (int): size of list
    Returns:
        int: index of k or -1 if k is not present in list
    Examples
    --------
    >>> binary_search([1,4,5,6,7],6,5)
    3
    >>> binary_search([1,4,5,6,7],3,5)
    -1
    """
    left = 0
    right = n

    return find_index(nums, k, left, right)


print(binary_search([1, 4, 5, 6, 7], 6, 5))
