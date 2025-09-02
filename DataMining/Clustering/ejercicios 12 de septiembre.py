# -*- coding: utf-8 -*-
"""
Created on Mon Sep 12 18:48:18 2022

@author: diana
"""
import matplotlib.pyplot as plt 
import numpy as np

def Distancia(vector1, vector2):
    dist=0
    for i in range(len(vector1)):
        dist=dist+(vector1[i]-vector2[i])**2
    return np.sqrt(dist)

a=[2,3,1]
b=[-3,2,1]
c=[-1,5,1]

print(Distancia(b,a))
print(Distancia(a,c))
print(Distancia(b,c))

def Centroide(lista_vectores):
    centroide=[]
    for i in range(len(lista_vectores)):
        promedio_i=0
        for j in range(len(lista_vectores[0])):
            promedio_i=promedio_i + lista_vectores[j][i]
        promedio_i=promedio_i/len(lista_vectores)
        centroide.append(promedio_i)
    return centroide
cluster=[a,b,c]
x=Centroide(cluster)
print(x)

print("imagenes")
import matplotlib.image as mpimg
img= mpimg.imread('stinkbug[3225].png')

print(img)
print(img[0][0][0])
print(len(img))
print(len(img[0]))
print(len(img[0][0]))

data_matrix=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        data_matrix.append(img([i][j]))

from sklearn.cluster import KMeans
kmeans=KMeans(n_clusters=2, random_state=0).fit_predict(data_matrix)

colors=[[0,0,0],[1,1,1],[0,0,1],[1,0,0],[0,1,0]]

image_kmeans=np.copy=np.copy(img)

index=0
data_matrix=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        image_kmeans[i][j]=colors[kmeans[index]]
        index+=1