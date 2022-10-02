import re
x = 'My 2 favorite numbers are 19 and 42'
# regular expression with range 0 to 9 with one or more digits
y = re.findall('[0-9]+', x)
print(y)
