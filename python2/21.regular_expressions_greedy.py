# regular expression trying to have maximum length
import re
x = 'From: using the :'
# regular expression says
# ^F starts with F
# .+ one or more characters
# : list character is a :
y = re.findall('^F.+:', x)
# this will print the whole string
print(y)

# ? dont be greedy
y = re.findall('^F.+?:', x)
print(y)

s = 'From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008'

# \S non whitespace character
# + one or more
# @ container @
y = re.findall('\S+@\S+', s)
print(y)

s = 'From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008'
# ^ starts with
# \S non whitespace character
# + one or more
# @ container @
# () only extract within parenthesis
y = re.findall('^From (\S+@\S+)', s)
print(y)

# ^From starts with From
# .* n number of character upto @
# [^ ] mathch every non blank character
# * one or more
# () extract words within parenthisis
y = re.findall('^From .*@([^ ]*)', s)
print(y)
y = re.findall('\S+?@\S+', s)
print(y)