# sort by keys
d = {'b':1, 'a':10, 'c':22}
# gets the list of touples form the dictionary
# sorts and stores them in t
t = sorted(d.items())
for k, v in t:
	print(k,v)


print('\nSort by values')
# sort by values
d = {'b':1, 'a':10, 'c':22}
# gets the list of touples form the dictionary
# sorts and stores them in t
tmp = list()
for k, v in d.items():
	tmp.append((v, k))
print(tmp)

tmp = sorted(tmp, reverse=True)
for k, v in tmp:
	print(k,v)