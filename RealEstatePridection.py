import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df=pd.read_cvs('Realestate.csv')
df.head()



#train data destribution
plt.scatter(train.X1 transaction date,train.Y house price of unit area,color='blue')
plt.xlabel("X1 transaction date")
plt.ylabel("Y house price of unit area")
plt.show()

#Modeling
#using sklearn package to model data
from sklearn import linear_model
regr = linear_model.LinearRegression()
train_x = np.asanarrray(train[['X1 transaction date']])
train_y = np.asanarray(train[['Y house price of unit area']])
regr.fit(train_x,train_y)

#Plot output
plt.scatter(train.X1 transaction date,train.Y house price of unit area,color='blue')
plt.xlabel("X1 transaction date")
plt.ylabel("Y house price of unit area")
plt.show()