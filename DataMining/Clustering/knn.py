# -*- coding: utf-8 -*-
"""
Created on Wed Oct 26 18:35:28 2022

@author: diana
"""

import numpy as np 
import matplotlib.pyplot as plt 
from sklearn.neighbors import KNeighborsClassifier

import numpy as np
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier

X=[[0],[1],[2],[3]]
Y= [0,0,1,1]

neigh=KNeighborsClassifier(n_neighbors=3)
neigh.fit(X,Y)

print(neigh.predict([[1.1]]))

print("\n Iris")
from sklearn import datasets
iris=datasets.load_iris()
X_train = iris.data
y_train=iris.target
 
#cargar nuevo dato
new_data=np.array([[5.1,3.0,1.4,0.2],[5.8,2.7,4,1]])

fig=plt.figure(figsize=(6,6))
plt.scatter(X_train[:,0],X_train[:,3], c=y_train, marker='.')
plt.scatter(new_data[:,0],new_data[:,3], c=['red','red'], marker='X')
#clasificador
k=2
neigh= KNeighborsClassifier(n_neighbors=k)
neigh.fit(X_train, y_train)

print(neigh.predict(new_data))