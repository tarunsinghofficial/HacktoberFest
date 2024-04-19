# list comprehension expresses a list as expressions
fhand = open('romeo.txt')
# get frequency of words from the code
counts = dict()
for line in fhand:
	words = line.split()
	for word in words:
		counts[word] = counts.get(word, 0) + 1
# here we have used the list comprehension to sort the items in dictionary
print(sorted([(v, k) for k, v in counts.items()], reverse= True)[:10])