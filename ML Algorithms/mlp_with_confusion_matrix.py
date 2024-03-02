#MLP with Confusion Matrxi

from sklearn.datasets import load_breast_cancer
cancer_dataset = load_breast_cancer()
cancer_dataset.DESCR

from sklearn.neural_network import MLPClassifier
mlp = MLPClassifier(hidden_layer_sizes=(150,100,50), max_iter=300, activation="relu", solver="adam",random_state=1)
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(cancer_dataset.data, cancer_dataset.target, test_size=0.25)
mlp.fit(x_train, y_train)
y_pred = mlp.predict(x_test)

from sklearn.metrics import confusion_matrix
cf = confusion_matrix(y_test, y_pred)
cf