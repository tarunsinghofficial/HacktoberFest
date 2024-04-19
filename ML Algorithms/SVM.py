from sklearn import svm
from sklearn import datasets
from sklearn.model_selection import train_test_split

iris=datasets.load_iris()

x=iris.data[:,2]
y=iris.target

x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,random_state=4)

x_train_mod=x_train.reshape(-1,1)
x_test_mod=x_test.reshape(-1,1)
y_train_mod=y_train.reshape(-1,1)
y_test_mod=y_test.reshape(-1,1)

model=svm.SVC(kernel='linear')
model.fit(x_train_mod,y_train_mod)
accuracy=model.score(x_test_mod,y_test_mod)
print("Accuracy of your model for the Iris dataset is :",accuracy)