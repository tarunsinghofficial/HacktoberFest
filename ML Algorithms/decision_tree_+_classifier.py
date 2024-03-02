#Decision Tree and Classifier

from sklearn.datasets import load_boston
import pandas as pd
boston = load_boston()
data = pd.DataFrame(boston.data, columns = boston.feature_names)
data

data['MEDV'] = pd.DataFrame(boston.target)
data

pd.DataFrame(data.corr().round(2))

x = data[['RM','ZN']]
y = data['MEDV']
x = pd.DataFrame(x)
y = pd.DataFrame(y)

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2)
y_train

#Use the DecisionTreeRegressor module
from sklearn.tree import DecisionTreeRegressor
dt1 = DecisionTreeRegressor(max_depth=20)
dt1.fit(x_train, y_train)
y_pred1 = dt1.predict(x_test)

#Finding the RMSE value
from sklearn.metrics import mean_squared_error
import numpy as np
rmse = np.sqrt(mean_squared_error(y_test, y_pred1))
print("RMSE : ",rmse)

#Finding the R^2 score
r2 = dt1.score(x_test, y_test)
print("R^2 score : ",r2)

#Using the RandomForestRegressor
from sklearn.ensemble import RandomForestRegressor
rf1 = RandomForestRegressor()
rf1.fit(x_train, y_train)
y_pred2 = rf1.predict(x_test)
rmse = np.sqrt(mean_squared_error(y_test, y_pred2))
print("RMSE : ",rmse)
r2 = rf1.score(x_test, y_test)
print("R^2 score : ",r2)

#Using the DecisionTreeClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_digits
digits = load_digits()

#Splitting the dataset
x_train, x_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.25)

dt2 = DecisionTreeClassifier(criterion="entropy")
dt2.fit(x_train, y_train)
print("Score 1 : ",dt2.score(x_test, y_test))

dt3 = DecisionTreeClassifier(max_depth=30)
dt3.fit(x_train, y_train)
print("Score 2 : ",dt3.score(x_test, y_test))
