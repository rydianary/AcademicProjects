# -*- coding: utf-8 -*-
"""
Created on Wed Sep 21 18:55:03 2022

@author: diana
"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

X = np.array ([[1.5,2.5],[1,4],[1,0],[5.5,1],[6,4],[6,0]])
fig=plt.figure(figsize=(6,6))
plt.scatter(X[:,0], X[:,1])
plt.show()
# por default
from sklearn.cluster import AgglomerativeClustering
clustering= AgglomerativeClustering().fit(X)
print(clustering.labels_)

#para modelar, elegir  características
hierarchical_clustering=AgglomerativeClustering(n_clusters=3, affinity='euclidean', linkage='ward')
print(hierarchical_clustering)
labels=hierarchical_clustering.fit_predict(X)
print(labels)

#generar dendograma
from scipy.cluster.hierarchy import dendrogram, linkage
linkage_data=linkage(X, method='ward', metric='euclidean')
fig=plt.figure(figsize=(8,8))
dendrogram(linkage_data)
plt.show()

archivo = open("iris.txt", "r")

lineas = archivo.readlines()
cleandata=[]
i=0
while i < len(lineas)-1:
    cleandata.append(lineas[i].split(sep=","))
    i+=1
print(cleandata[0]) 
for i in range(len(cleandata)):
    cleandata[i][0] = float(cleandata[i][0])
    cleandata[i][1] = float(cleandata[i][1])
    cleandata[i][2] = float(cleandata[i][2])
    cleandata[i][3] = float(cleandata[i][3])
df = pd.DataFrame(cleandata)
df.columns = ["Sepal_length","Sepal_width","Petal_length","Petal_width","Class"]
I=df.iloc[0:150, [0]].values
L=df.iloc[0:150, [1]].values
plt.scatter(I, L)