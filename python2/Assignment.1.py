fhand = open('romeo.txt')
nlst = []
for line in fhand:
    line.rstrip()
    words = line.split()
    for word in words:
        nlst.append(word)
nlst.sort()
print(nlst)
    