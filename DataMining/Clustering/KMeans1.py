import numpy as np
#import pandas as pd
import matplotlib.image as mpimg
import matplotlib.pyplot as plt

def mean_group(q: int) -> np.ndarray:
    mean = np.zeros(p)
    my_group = groups[q]
    for j in range(p):
        for i in my_group:
            mean[j] += Data[i][j]
    return mean/len(my_group)

def update_mean_groups():
    for q in range(K):
        group_means.update({q:mean_group(q)})

def distance(A: np.ndarray, B: np.ndarray) -> float:
    return np.linalg.norm(A-B)

"""--------------- BASE DE DATOS ---------------"""

img=mpimg.imread('imagen2.png')

"""--------------- HIPERPARÁMETROS ---------------"""
K = 3
iterations = 15
x_header = 'Longitud'
y_header = 'Latitud'

"""--------------- INICIALIZACIÓN ---------------"""

img=mpimg.imread('imagen2.png')
Data=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        Data.append(img[i][j])
        
        
n = len(Data)
p = len(Data[0])


groups = {}
group_means = {}

for i in range(K):
    groups.update({i:set()})
    group_means.update({i:set()})

for i in range(n):
    groups[np.random.randint(K)].add(i)

update_mean_groups()

"""--------------- ALGORITMO ---------------"""

for iter in range(iterations):
    for q in range(K):
        new_group=[]
        for i in groups[q]:
            x = Data[i]
            new_group.append([q,i])
            minimum = distance(x,group_means[q])
            for s in range(K):
                test = distance(x,group_means[s])
                if test < minimum:
                    minimum = test
                    new_group[-1] = [s,i]
        for g in new_group:
            s = g[0]
            i = g[1]
            if s != q:
                groups[q].remove(i)
                groups[s].add(i)
    update_mean_groups()

fig = plt.figure(figsize=(10,8))

for q in range(K):
    x_values = []
    y_values = []
    z_values = []
    index = groups[q]
    for i in index:
        x_values.append(Data[i][0])
        y_values.append(Data[i][1])
        y_values.append(Data[i][2])
    plt.plot(x_values, y_values, marker='x', linestyle='None', label=f'cluseter {q}: {len(groups[q])}')
    plt.plot(group_means[q][0], group_means[q][1],group_means[q][2] )

