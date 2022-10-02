# lists decleration
friends = ['Joseph','glenn','sally']

# list within list
listWithinList = [1, [3,4], 5]
print(friends)
print(listWithinList)

# lists are mutable
lotto = [2, 14, 26, 41, 63]
print(lotto)
lotto[2] = 28
print(lotto)

# print length of string
print(len(lotto))

# print a list using for loop
friends = ["Hello", "Hi", "There"]
for i in range(len(friends)):
	friend = friends[i]
	print('happy new year:', friend)

# adding two list will concatinate them
list1 = ["hello", "there", "wow"]
list2 = ["Welcome", "to", "jungle"]
list3 = list1 + list2
print(list3)

# slicing elements of the list

t = [9, 41, 12, 3, 74, 15]
print(t[1:3])
print(t[:4])
print(t[3:])
print(t[:])

# building list from scratch

stuff = list()
stuff.append('book')
stuff.append(99)
print(stuff)
stuff.append('cookie')
print(stuff)

# in operator
some = [1, 9, 21, 10, 16]
print(9 in some)
print(20 not in some)

# sorting a list
friends = ['Joseph', 'Glenn', 'sally']
friends.sort()
print(friends)

# math in list
nums = [3, 41, 12, 9, 74, 15]
# lenth of list
print(len(nums))
# find max of list
print(max(nums))
# find min of list
print(min(nums))
# find sum of all elements
print(sum(nums))
# find the average of all the elements
print(sum(nums)/len(nums))

