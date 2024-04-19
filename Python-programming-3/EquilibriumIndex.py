# Python3 program to find equilibrium
# index of an array

# function to find the equilibrium index


def equilibrium(arr):
	leftsum = 0
	rightsum = 0
	n = len(arr)

	# Check for indexes one by one
	# until an equilibrium index is found
	for i in range(n):
		leftsum = 0
		rightsum = 0

		# get left sum
		for j in range(i):
			leftsum += arr[j]

		# get right sum
		for j in range(i + 1, n):
			rightsum += arr[j]

		# if leftsum and rightsum are same,
		# then we are done
		if leftsum == rightsum:
			return i

	# return -1 if no equilibrium index is found
	return -1


# Driver code
if __name__ == "__main__":
	arr = [-7, 1, 5, 2, -4, 3, 0]

	# Function call
	print(equilibrium(arr))
