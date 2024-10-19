def binarySearchAppr(arr, start, end, x):
    # Check condition
    if end >= start:
        mid = start + (end - start) // 2
        
        # If element is present at the middle
        if arr[mid] == x:
            return mid
        
        # If element is smaller than mid
        elif arr[mid] > x:
            return binarySearchAppr(arr, start, mid - 1, x)
        
        # Else the element is greater than mid
        else:
            return binarySearchAppr(arr, mid + 1, end, x)
    
    # Element is not found in the array
    return -1

# Initialize and sort the array
arr = sorted(['t', 'u', 'o', 'r', 'i', 'a', 'l'])  # Sort to ensure binary search works
x = 'r'

# Perform binary search
result = binarySearchAppr(arr, 0, len(arr) - 1, x)

# Check the result and print the appropriate message
if result != -1:
    print("Element is present at index " + str(result))
else:
    print("Element is not present in the array")
