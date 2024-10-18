import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("winequalityN.csv")
print(df)

df.head(25)

plt.title("LINE PLOT ")

x=df.head(25)['alcohol']
y=df.head(25)['sulphates']
plt.plot(x,y)

plt.title('SCATTER PLOT')

X=df.head(25)['pH']
Y=df.head(25)['chlorides']
plt.scatter(x,y)

plt.title("LALIPOP CHART")
X=df.head(50)["quality"]
plt.stem(x)

plt.title("BAR CHART")
X=df.head(50)["chlorides"]
Y=df.head(50)["quality"]
plt.bar(x,y)

plt.title("PIE CHART")
X=df.head(75)['citric acid']
Y=df.head(75)["residual sugar"]
plt.pie(x,y)

import seaborn as sns

plt.title("SEABORN")
x=df.head(75)["volatile acidity"]
y=df.head(75)["fixed acidity"]
sns.regplot(x=x, y=y)

plt.title("BOX PLOT")
x=df.head(75)["density"]
plt.boxplot(x)

arr1  =df.head(75) ["sulphates"]
arr2  = df.head(75)["density"]
arr3  = df.head(75)["pH"]

plt.plot([], [], color='r', label = 'D 1')
plt.plot([], [], color='g', label = 'D 2')
plt.plot([], [], color='b', label = 'D 3')

plt.stackplot( arr1, arr2, arr3, colors= ['r', 'g', 'b'])
plt.title('Stack Plot Example')
plt.legend()
plt.show()
