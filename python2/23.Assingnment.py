import re
sum = 0
fhand = open('a.txt')
for line in fhand:
	line = line.rstrip()
	stuff = re.findall('[0-9]+',line)
	if len(stuff) >= 1:
		for num in stuff:
			sum += int(num)
print(sum)