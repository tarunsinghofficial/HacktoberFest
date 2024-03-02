#Linear Regression in ML

from sklearn.datasets import load_boston
boston = load_boston()

#description of the dataset
boston.DESCR

#load the dataset into a dataframe
import pandas as pd
data = pd.DataFrame(boston.data, columns = boston.feature_names)
data

#MEDV is generally the target element
data['MEDV'] = boston.target
data

#find all correlation values
pd.DataFrame(data.corr().round(2))

#RM has the highest value corresponding to MEDV as thus it is our training data
#x corresponds to train data and y corresponds to labels
x = data['RM']
y = data['MEDV']

#Convert x and y to pandas dataframe
x = pd.DataFrame(x)
y = pd.DataFrame(y)

#import module for linear regression and train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
linearRegressionClassifier = LinearRegression()

#Splitting the data into training and testing data sets
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2)
print(x_train.shape)
print(y_train.shape)

#Train the classifier by fitting the test data
linearRegressionClassifier.fit(x_train, y_train)

import pandas as pd
from sklearn.metrics import mean_squared_error

#Determine the prediction values
y_pred = linearRegressionClassifier.predict(x_test)
print(y_pred)
print(y_pred.shape)

import numpy as np

#Find the Root mean square error(RMSE)
rmse = np.sqrt(mean_squared_error(y_test, y_pred))
print(rmse)

#Determine the R^2 score
linearRegressionClassifier.score(x_test,y_test)

#Using the ridge regression model
from sklearn.linear_model import Ridge

ridge1 = Ridge(alpha=1)
ridge1.fit(x_train, y_train)

#Determine the prediction values
y_pred1 = ridge1.predict(x_test)

#Determine the RMSE value
rmse = np.sqrt(mean_squared_error(y_test, y_pred1))
print("Root Mean squared error : ",rmse)

#Determine the R^2 score
res = ridge1.score(x_test, y_test)
print("R^2 score : ",res)

#Using the Lasso regression model
from sklearn.linear_model import Lasso

lasso1 = Lasso(alpha=0.01)
lasso1.fit(x_train, y_train)

#Determine the prediction values
y_pred2 = lasso1.predict(x_test)

#Determine the RMSE value
rmse = np.sqrt(mean_squared_error(y_test, y_pred2))
print("Root Mean squared error : ",rmse)

#Determine the R^2 score
res = lasso1.score(x_test, y_test)
print("R^2 score : ",res)

#Using the ElasticNet regression model
from sklearn.linear_model import ElasticNet

en1 = ElasticNet(alpha=0.1, l1_ratio=0.5)
en1.fit(x_train, y_train)

#Determine the predicted values
y_pred3 = en1.predict(x_test)

#Determine the RMSE value
rmse = np.sqrt(mean_squared_error(y_test, y_pred3))
print("Root Mean squared error : ",rmse)

#Determine the R^2 score
res = en1.score(x_test, y_test)
print("R^2 score : ",res)