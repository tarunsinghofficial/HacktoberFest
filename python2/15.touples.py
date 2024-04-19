# touples are unmodifiable lists
x = ('Glenn', 'Sally','Joseph')
print(x[2])
y = (1, 9, 2)
print(max(y))
# now work
# x[2] = 'hello'
# x.sort()
# x.append()
# x.reverse()
(x,y) = (4, 'fred')
print(x)
print(y)

# touple can be compared
print((0, 1, 2) < (5, 1, 2))
print(('Aayush', 'Joshi') < ('Mamta', 'Sharma'))