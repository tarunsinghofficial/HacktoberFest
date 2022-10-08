# Python3 program to find the smallest
# positive value that cannot be
# represented as sum of subsets
# of a given sorted array

# Returns the smallest number
# that cannot be represented as sum
# of subset of elements from set
# represented by sorted array arr[0..n-1]
def findSmallest(arr, n):

	res = 1 #Initialize result

	# Traverse the array and increment
	# 'res' if arr[i] is smaller than
	# or equal to 'res'.
	for i in range (0, n ):
		if arr[i] <= res:
			res = res + arr[i]
		else:
			break
	return res


# Driver program to test above function
arr1 = [1, 3, 4, 5]
n1 = len(arr1)
print(findSmallest(arr1, n1))

arr2= [1, 2, 6, 10, 11, 15]
n2 = len(arr2)
print(findSmallest(arr2, n2))

arr3= [1, 1, 1, 1]
n3 = len(arr3)
print(findSmallest(arr3, n3))

arr4 = [1, 1, 3, 4]
n4 = len(arr4)
print(findSmallest(arr4, n4))
