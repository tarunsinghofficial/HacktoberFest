import matplotlib.pyplot as plt
import numpy as np
import math 
f=[[10,5],[40,7],[3,2],[5,3]]
l=['good','good','bad','bad']
x=[]
y=[]
s=len(set(l)) #shows all categories present
for i in range(len(f)):
    f1=f[i][0]
    x=np.append(x,f1)
    f2=f[i][1]
    y=np.append(y,f2)
print(x," ",y)
for i in range(len(f)):
    if (l[i]== 'good'):
        plt.plot(x[i],y[i],'r*')
    else:
        plt.plot(x[i],y[i],"y^")
p = int(input("Enter saving%"))
q = int(input("Enter no. of good habit"))
k=int(input("Enter k"))
plt.plot(p,q,'b*')
disx=[]
disy=[]
dis=[]
if (k>len(f)):
    k=len(f)
for i in range(len(x)):
    dis=np.append(dis,math.sqrt(((p-x[i])**2)+((q-y[i])**2)))
print(dis)
dis.sort()
min1=[]
for i in range(k):
    min1=np.append(min1,dis[i])
print(min1)
sum1=0
for i in range(len(min1)):
    sum1=sum1+min1[i]
print(sum1/len(min1)) #avgmin = sum1/len(min1)
plt.show()
