def radix_sort(arr):
    # Find the maximum number to know the number of digits
    max_num = max(arr)
    exp = 1
    n = len(arr)
    output = [0] * n

    while max_num // exp > 0:
        count = [0] * 10

        # Count the occurrences of each digit
        for i in range(n):
            index = (arr[i] // exp) % 10
            count[index] += 1

        # Calculate the cumulative count
        for i in range(1, 10):
            count[i] += count[i - 1]

        # Build the output array
        i = n - 1
        while i >= 0:
            index = (arr[i] // exp) % 10
            output[count[index] - 1] = arr[i]
            count[index] -= 1
            i -= 1

        # Copy the output array to arr
        for i in range(n):
            arr[i] = output[i]

        # Move to the next digit
        exp *= 10

# Example usage:
arr = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(arr)
print("Sorted array is:", arr)
