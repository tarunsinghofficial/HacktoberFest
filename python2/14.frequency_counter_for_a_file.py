name = input('Enter file:')
handle = open(name)
counts = dict()
for line in handle:
	words = line.split()
	for word in words:
		counts[word] = counts.get(word, 0) + 1

big_count = None
big_word = None
for word, count in counts.items():
	if big_count is None or count > big_count:
		big_count = count
		big_word = word
print(big_count)
print(big_word)