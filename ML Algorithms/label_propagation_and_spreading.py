#Label Propagation and Spreading

from sklearn.datasets import load_digits
digits = load_digits()
digits.DESCR

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(digits.data, digits.target, test_size=0.2)
y_train

import numpy as np
indexList = np.arange(len(x_train))
x_label = x_train[indexList[0:300]]
y_label = y_train[indexList[0:300]]
nonLabelindices = indexList[300:]
y_train_nonlabel = np.copy(y_train)
y_train_nonlabel[nonLabelindices] = -1

from sklearn.semi_supervised import LabelPropagation
lp = LabelPropagation(gamma=0.3)
lp.fit(x_train, y_train_nonlabel)
score = lp.score(x_test, y_test)
print("Score : ",score)

y_label = lp.transduction_[nonLabelindices]
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_train[nonLabelindices], y_label, labels=lp.classes_)
cm

from sklearn.semi_supervised import LabelSpreading
ls = LabelSpreading(gamma=0.3)
ls.fit(x_train, y_train_nonlabel)
score = ls.score(x_test, y_test)
print("Score : ",score)
y_label = ls.transduction_[nonLabelindices]
cm = confusion_matrix(y_train[nonLabelindices], y_label, labels=lp.classes_)
cm