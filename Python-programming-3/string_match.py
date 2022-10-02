import re

name = ["A1B1", "djdd", "B2C4", "C2H2", "jdoi","1A4V"]

# Match names.
for element in name:
     m = re.match("(^[A-Z]\d[A-Z]\d)", element)
     if m:
        print(m.groups())
