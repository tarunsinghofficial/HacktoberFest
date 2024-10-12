import os
from numpy.distutils.system_info import p
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
import numpy as np
import pandas as pd


print(os.getcwd())
rd = pd.read_excel('')

ds = pd.read_csv(r"C:\Users\salon\PycharmProjects\pythonProject")
filename = 'data.csv'
raw_data = open('data.csv')
df = pd.read_csv('data.csv')
ds = ds.dropna()
for i in ['age', 'bmi', 'avg_glucose_level']:
    ds[1] = ds[1].replace(0, np.NaN)
    mean = int(ds[1].mean(skipna=True))
    ds[1] = ds[1].replace(np.NaN, mean)

X = ds.iloc[:, [2, 8, 9]]
Y = ds.iloc[:, 11]

X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.2)
K_range = range(1, 30)
score = {}
score_list = []
for k in K_range:
    Knn = KNeighborsClassifier(n_neighbors=k)
    Knn.fit(X_train, y_train)
    Pred = Knn.predict(X_test)
    score_list.append(metrics.accuracy_score(y_test, Pred))

p.plot(K_range, score_list)
p.xlabel("value of k for ANN")
p.ylabel("Testing Accuracy")
p.show()
