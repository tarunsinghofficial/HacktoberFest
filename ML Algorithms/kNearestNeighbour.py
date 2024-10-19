import matplotlib.pyplot as plt
import numpy as np
import math

# Input data points
f = [[10, 5], [40, 7], [3, 2], [5, 3]]
l = ['good', 'good', 'bad', 'bad']

# Initialize numpy arrays
x = np.array([point[0] for point in f])
y = np.array([point[1] for point in f])

print(x, " ", y)

# Plot data points based on labels
for i in range(len(f)):
    if l[i] == 'good':
        plt.plot(x[i], y[i], 'r*', label='Good Habits' if i == 0 else "")
    else:
        plt.plot(x[i], y[i], 'y^', label='Bad Habits' if i == 0 else "")

# User inputs
p = int(input("Enter saving%: "))
q = int(input("Enter no. of good habits: "))
k = int(input("Enter k: "))

# Plot user input point
plt.plot(p, q, 'b*', label='User Input')

# Calculate distances
dis = np.array([math.sqrt(((p - x[i]) ** 2) + ((q - y[i]) ** 2)) for i in range(len(x))])
print(dis)

# Sort distances and get the k smallest
dis.sort()
min1 = dis[:k]  # Get the k smallest distances
print(min1)

# Calculate average of the smallest distances
if len(min1) > 0:
    avg_min = sum(min1) / len(min1)
    print("Average of the k smallest distances:", avg_min)
else:
    print("No distances to calculate average.")

# Add legends and labels
plt.title('Habits Visualization')
plt.xlabel('Saving Percentage')
plt.ylabel('Number of Good Habits')
plt.legend()
plt.grid(True)
plt.show()
