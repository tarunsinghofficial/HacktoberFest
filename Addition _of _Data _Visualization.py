import matplotlib.pyplot as plt
import seaborn as sns
import plotly.express as px

# Sample data
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Create a line plot
plt.plot(x, y)

# Add title and labels
plt.title('Line Plot Example')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Show the plot
plt.show()

# Sample data
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Create a scatter plot
sns.scatterplot(x, y)

# Add title and labels
plt.title('Scatter Plot Example')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Show the plot
plt.show()

# Sample data
x = ['A', 'B', 'C', 'D', 'E']
y = [10, 15, 20, 25, 30]

# Create a bar chart
fig = px.bar(x=x, y=y)

# Add title and labels
fig.update_layout(title='Bar Chart Example', xaxis_title='X-axis', yaxis_title='Y-axis')

# Show the plot
fig.show()


x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

plt.plot(x, y)
plt.title('Line Plot Example')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()
