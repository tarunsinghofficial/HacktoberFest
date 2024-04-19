# counts = dict()
# names = input().split()
# for name in names:
# 	if name not in counts:
# 		counts[name] = 1
# 	else:
# 		counts[name] = counts[name] + 1
# print(counts)

counts = dict()
names = input("Enter the names:").split()
for name in names:
	counts[name] = counts.get(name, 0)  + 1
print(counts)