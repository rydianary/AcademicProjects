# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 18:19:29 2022

@author: diana
"""
import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

X_train=[3.2,1.1,4.0,1.5,3.5,1.2,1.7,1.4,3.1,1.0,3.45]

fig=plt.figure(figsize=(8,6))
plt.stem(X_train,label='Data',
         basefmt=' ')
plt.legend()
plt.show()



fig=plt.figure(figsize=(8,6))
plt.hist(X_train,
         bins=15,
         label='Data',
         color='red',
         alpha=0.5, 
         align='left',
         edgecolor='black')
plt.legend()
plt.show()

#agregar valor
y_train=[1,0,1,0,1,0,1,0,1,0,1]
fig=plt.figure(figsize=(8,6))
plt.scatter(X_train,y_train)
plt.show()

#sklearn
X_train=pd.DataFrame(X_train)
reg=LinearRegression().fit(X_train, y_train)
b0=reg.intercept_
b1=reg.coef_

print(b0)
print(b1)

#
fig=plt.figure(figsize=(6,6))
plt.scatter(X_train,y_train)
plt.plot([1,4],[b0+b1,b0+(4*b1)], color='red')
plt.scatter([(0.5-b0)/b1],[0.5], color='black',marker='o')
plt.show()
threshold=(0.5-b0)/b1
print(threshold)

#iris #regresion lineal un metodo de prediccion que se puede usar para muchas otras cosas
from sklearn import datasets
iris=datasets.load_iris()

X_train=iris.data
y_train=iris.target
for i in range(len(y_train)):
    if(y_train[i]!=0):
        y_train[i]=1
    else:
        y_train[i]=0
        
#comentar
fig=plt.figure(figsize=(6,6))
plt.scatter(X_train[:,0],X_train[:,1], c=y_train)
plt.show()

#comentar 
reg=LinearRegression().fit(X_train, y_train)
print(reg.coef_)
print(reg.intercept_)

new_data=np.array([[5.1,3.0,1.4,0.2],[5.8,2.7,4,1]])

fig=plt.figure(figsize=(6,6))
#tachecitos
plt.scatter(X_train[:,0],X_train[:,1], c=y_train, marker='.')
plt.scatter(new_data[:,0],new_data[:,1], c=['red','red'], marker='X')
plt.show()

reg=LinearRegression().fit(X_train, y_train)
print(reg.coef_)
print(reg.intercept_)

y_predict=[]
for i in range(len(new_data)):
    y=reg.intercept_+ new_data[i][0]*reg.coef_[0]
    +new_data[i][1]*reg.coef_[1]
    +new_data[i][2]*reg.coef_[2]
    +new_data[i][3]*reg.coef_[3]
    
    if(y>0.5):
        y_predict.append(0)
    else:
        y_predict.append(1)
print(y_predict)

fig=plt.figure(figsize=(6,6))
#tachecitos asignados al color de la prediccion 
plt.scatter(X_train[:,0],X_train[:,1], c=y_train, marker='.')
plt.scatter(new_data[:,0],new_data[:,1], c=y_predict, marker='D')