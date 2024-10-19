# Program to rearrange the entered lowercase alphabets in correct order
a = int(input("Enter number of alphabets: "))
b = []

# Input lowercase alphabets
for i in range(a):
    char = input(f"Enter {i}th lowercase alphabet: ")
    
    # Input validation
    if len(char) != 1 or not char.islower():
        print("Invalid input! Please enter a single lowercase alphabet.")
        exit(1)  # Exit the program if invalid input is given

    b.append(char)

# Sort the list of alphabets
b.sort()

# Print the sorted alphabets
print("Alphabets in correct arrangement:")
print(''.join(b))  # Joining the list into a single string for better output
