a = int(input("Enter Marks of First Subject Out of 100 :  "))
b = int(input("Enter Marks of Second Subject Out of 100 :  "))
c = int(input("Enter Marks of Third Subject Out of 100 :  "))
d = int(input("Enter Marks of Fourth Subject Out of 100 :  "))
f = int(input("Enter Marks of Fifth Subject Out of 100 :  "))

average = (a+b+c+d+f)/5

print("Your Average Marks Are: ", average)

if average>90:
    print("You Got A+ Grade")
elif average>80:
    print("You Got A Grade")
elif average>70:
    print("You Got B Grade")
elif average>60:
    print("You Got C Grade")
