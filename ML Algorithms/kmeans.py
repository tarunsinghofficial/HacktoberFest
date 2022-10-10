#K-Means Algorithm

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
alldata = make_blobs(n_samples=200, centers=4, n_features=2, cluster_std=1.5, random_state=30)
print(alldata)

#taking only the first array which contains the data
data = alldata[0]
data

# %matplotlib inline
#plot the data points without labels
plt.scatter(data[:,0],data[:,1])

#Create kmeans object
kmeans = KMeans(n_clusters=4)
y_pred = kmeans.fit_predict(data)
print(y_pred)

clusters = kmeans.cluster_centers_
clusters

plt.scatter(data[y_pred==0,0], data[y_pred==0,1], s=70, color="green")
plt.scatter(data[y_pred==1,0], data[y_pred==1,1], s=70, color="yellow")
plt.scatter(data[y_pred==2,0], data[y_pred==2,1], s=70, color="red")
plt.scatter(data[y_pred==3,0], data[y_pred==3,1], s=70, color="blue")

plt.scatter(clusters[0][0], clusters[0][1], marker="*", color="black")
plt.scatter(clusters[1][0], clusters[1][1], marker="*", color="black")
plt.scatter(clusters[2][0], clusters[2][1], marker="*", color="black")
plt.scatter(clusters[3][0], clusters[3][1], marker="*", color="black")