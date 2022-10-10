#Logistic Regression in ML

from sklearn.datasets import load_digits
digits = load_digits()
digits.DESCR

print(digits.data)
print(digits.data.shape)

#target or label dimension
print(digits.target.shape)

d = digits.data[0:500]
print(d.shape)

#taking only the first pixel of the image
image = digits.data[0]
print(image)

#determine the class of first pixel
print(digits.target[0])

#plotting the image
import matplotlib.pyplot as plt
import numpy as np
print(np.reshape(image,(8,8)))
plt.imshow(np.reshape(image,(8,8)),cmap="Greys")

#LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
lr = LogisticRegression(max_iter=10000)
x_train, x_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.2)
lr.fit(x_train, y_train)
y_pred = lr.predict(x_test)
score = lr.score(x_test, y_test)
print("Score : ",score)