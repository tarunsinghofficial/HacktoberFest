import matplotlib.pyplot as plt
import numpy as np
import math

# Data points
f = [[10, 5], [40, 7], [3, 2], [5, 3]]
l = ['good', 'good', 'bad', 'bad']  # Labels for each point

x = np.array([point[0] for point in f])  # Extracting x-coordinates
y = np.array([point[1] for point in f])  # Extracting y-coordinates

# Display the data points
print("x-coordinates:", x)
print("y-coordinates:", y)

# Initialize lists to store labels only once for legend
plotted_good = False
plotted_bad = False

# Plot the data points with different markers for 'good' and 'bad'
for i in range(len(f)):
    if l[i] == 'good':
        if not plotted_good:
            plt.plot(x[i], y[i], 'r*', label='Good')  # Red stars for 'good'
            plotted_good = True
        else:
            plt.plot(x[i], y[i], 'r*')  # No label to avoid duplicate in legend
    else:
        if not plotted_bad:
            plt.plot(x[i], y[i], 'y^', label='Bad')  # Yellow triangles for 'bad'
            plotted_bad = True
        else:
            plt.plot(x[i], y[i], 'y^')  # No label to avoid duplicate in legend

# Get new input point
p = int(input("Enter saving%: "))  # Input saving percentage
q = int(input("Enter number of good habits: "))  # Input number of good habits
k = int(input("Enter k (number of nearest neighbors): "))  # Input the value of k

plt.plot(p, q, 'b*', label='New Point')  # Plot the new point with a blue star

# Calculate distances between the new point and existing points
distances = np.sqrt((x - p) ** 2 + (y - q) ** 2)
print("Distances:", distances)

# Sort the distances and get the k smallest ones
sorted_indices = np.argsort(distances)  # Sort distances and get indices
nearest_distances = distances[sorted_indices[:min(k, len(f))]]  # Handle case when k > len(f)
print("Nearest Distances:", nearest_distances)

# Compute the average of the k nearest distances
if len(nearest_distances) > 0:
    avg_min_distance = np.mean(nearest_distances)
    print("Average of nearest distances:", avg_min_distance)
else:
    print("No nearest distances to compute.")

# Display plot
plt.legend()  # Show legend for the different categories
plt.xlabel('Saving %')
plt.ylabel('Number of Good Habits')
plt.title(f'KNN with k = {k}')
plt.grid(True)
plt.show()
