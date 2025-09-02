# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 19:14:42 2022

@author: diana
""" 

import numpy as np
import matplotlib.image as mpimg
import matplotlib.pyplot as plt

img= mpimg.imread('stinkbug[3225].png')

print(img)
print(img[0][0][0])
print(len(img))
print(len(img[0]))
print(len(img[0][0]))

data_matrix=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        data_matrix.append(img[i][j])
        
        
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
        
        
fig=plt.figure(figsize=(12,6))
imgplot=plt.imshow(img)
plt.show()

fig=plt.figure(figsize=(12,6))
imgplot=plt.imshow(image_kmeans)
plt.show()
