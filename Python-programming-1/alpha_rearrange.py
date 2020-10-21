# Program to Rearrange the Entered Lower Case Alphabets in their Correct Arrangement
a = int(input("Enter Number of Alphabets:-"))
b = []
for i in range(a):
    b.append(input(f"Enter {i}th Lower Case Alphabet:-"))
for i in range(a):
    b[i] = ord(b[i])
b.sort()
for i in range(a):
    b[i] = chr(b[i])
print("Alphabets in Correct Arrangement:-")
print(b)
