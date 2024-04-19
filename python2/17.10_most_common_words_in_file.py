fhand = open('romeo.txt')
# get frequency of words from the code
counts = dict()
for line in fhand:
	words = line.split()
	for word in words:
		counts[word] = counts.get(word, 0) + 1

# sort words according to there frequency
lst = list()
for key, val in counts.items():
	newtup = (val, key)
	lst.append(newtup)
lst = sorted(lst, reverse = True)

# print the top 10 words
for val, key in lst[:10]:
	print(key, val)