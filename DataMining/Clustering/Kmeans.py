# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 00:52:49 2022

@author: USER
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

datos=pd.read_csv('moviescs.csv')
df=pd.DataFrame(datos)
x=df['cast_total_facebook_likes'].values
y= df['imdb_score'].values

"-----------------sacar el max y minimo-----------------------"
print("valor máximo de likes:",df['cast_total_facebook_likes'].max())           
print("valor minimo kes:",df['cast_total_facebook_likes'].min())      
"-----------------------Funcion de promedio-----------------------------"
print("valor promedios:",df['cast_total_facebook_likes'].mean())

"--------------------Uso de Dataframe con matrix-------------"
X = np.array(list(zip(x,y)))
print(X)

"-------------------Kmeans Uso------------------------------"
Kmeans=KMeans(n_clusters=2)
kmeans=Kmeans.fit(X)
labels = kmeans.predict(X)
centroids=kmeans.cluster_centers_

colors=["m.", "r.", "c.", "y.", "b."]
for i in range(len(X)):
    print("Coordenada: ",X[i],"Label: ", labels[i])
    plt.plot(X[i][0],X[i][1],colors[labels[i]],markersize=10)
plt.scatter(centroids[:,0],centroids[:,1], marker='x', s=150, linewidths=5,zorder=10)
plt.show()
