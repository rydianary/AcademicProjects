
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from sklearn.cluster import AgglomerativeClustering
from sklearn.cluster import KMeans 
from scipy.cluster.hierarchy import dendrogram
from scipy.cluster.hierarchy import linkage
from scipy.spatial.distance import cdist

"""
----------- Exercise 2 --------------
"""
#first we define the points we want to cluster and we plot them
data = np.array([[0.0, 2.0, 0.11, 0.3, 0.91], [0.2, 0, 0.62, 0.99, 0.82], [0.11, 0.62, 0, 0.54, 0.45],[0.3,0.99, 0.54, 0, 0.7], [0.91, 0.82, 0.45, 0.7, 0]])
plt.scatter(data[:,0], data[:,1])
plt.title("Data we define on R2")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()

#1st type
#Hierarchical grouping with singe linkage
#here we first print the different clusters
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="single")
print(hierarchical_clustering)
cluster_1 = hierarchical_clustering.fit_predict(data)
print("Clustering method single ", cluster_1)

for i in range(len(cluster_1)):
    if cluster_1[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "blue", label = "1st Cluster")
    elif cluster_1[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "green", label = "2nd Cluster")
    elif cluster_1[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "red", label = "3rd Cluster")

plt.title("Hierarchical grouping with single method")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

#we print the dendogram with a single method
linkage_data = linkage(data, method="single",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendogram with single method")
plt.show()  



#2nd type
#Hierarchical grouping with ward linkage
#here we print define the clusters and print them on a graph
hierarchical_clustering = AgglomerativeClustering(n_clusters = 3, affinity="euclidean",linkage="ward")
print(hierarchical_clustering)
cluster_2 = hierarchical_clustering.fit_predict(data)

#we print data depending on the cluster it belongs to
print("Clustering method ward : ",cluster_2)
for i in range(len(cluster_2)):
    if cluster_2[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "blue", label = "1st Cluster")
    elif cluster_2[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "green", label = "2nd Cluster")
    elif cluster_2[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "red", label = "3rd Cluster")

plt.title("Hierarchical grouping with ward method")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

#now we print the dendogram with ward method
linkage_data = linkage(data, method="ward",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendogram with ward method")
plt.show()  



#3rd type
#Hierarchical grouping with average linkage
#here we first print the different clusters
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="average")
print(hierarchical_clustering)
cluster_3 = hierarchical_clustering.fit_predict(data)
print("Clustering method average ",cluster_3)

for i in range(len(cluster_3)):
    if cluster_3[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "blue", label = "1st Cluster")
    elif cluster_3[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "green", label = "2nd Cluster")
    elif cluster_3[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "red", label = "3rd Cluster")

plt.title("Hierarchical grouping with average method")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

#we print the dendogram with a average method
linkage_data = linkage(data, method="average",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendogram with average method")
plt.show()



#4th type
#Hierarchical grouping with complete linkage
#here we first print the different clusters
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="complete")
print(hierarchical_clustering)
cluster_4 = hierarchical_clustering.fit_predict(data)
print("Clustering method complete ",cluster_4)

for i in range(len(cluster_4)):
    if cluster_4[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "blue", label = "1st Cluster")
    elif cluster_4[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "green", label = "2nd Cluster")
    elif cluster_4[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "red", label = "3rd Cluster")


plt.title("Hierarchical grouping with complete method")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

#we print the dendogram with a complete method
linkage_data = linkage(data, method="complete",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendogram with complete method")
plt.show()  
"""
-------------- Ejercicio 3 --------------
"""

def Kmeans(data, k, iters=10, randstate=0):
    # se selecciona el numero de datos
    n = data.shape[0] 
    # se seleccionan los primers centroides al azar, sin reemplazo
    centers = data[np.random.choice(n,k,replace=False)]
    # se inicializa nuestro array del cluster mas cercano a cada dato
    closest = np.zeros(n).astype(int)
    
    # se actualizan los centroides y los clusters hasta que converja
    while True:
        old_closest = closest.copy()
        distances = cdist(data, centers, 'euclidean')
        closest = np.argmin(distances, axis=1)

        for i in range(k):
            centers[i, :] = data[closest == i].mean(axis=0)

        if all(closest == old_closest):
            break

    return closest, centers


"""
-------------- Ejercicio 4 --------------
"""

# Se carga la imagen 2
img = np.array(mpimg.imread('imagen2.png'))
data_matrix = img.reshape(-1,3)
# Se ejecuta el modelo de k-medias
kmeans = Kmeans(data_matrix, 3)
# Se separan los resultados y se obtiene un array con el índice de cada agrupamiento y otro con la ubicación de los centroides
closest, centers = kmeans

# Se crea la imagen con los agrupamientos
colors = np.array([[1,0,0],[1,1,0],[0,1,0]])
image_kmeans=np.copy(img)

index=0
data_matrix=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        image_kmeans[i][j]=colors[closest[index]]
        index=index+1

# imagen original        
fig = plt.figure(figsize=(6,12))
imgplot = plt.imshow(img)
plt.show()

# imagen modificada (agrupamientos)
fig = plt.figure(figsize=(6,12))
imgplot = plt.imshow(image_kmeans)
plt.show()


"""
-------------- Ejercicio 5 --------------
"""

# Se crea la imagen en escala de grises
grey_img = np.copy(img)
grey_color = [0.3, 0.59, 0.11]

column = np.zeros_like(grey_img[:,:,0])
for i in range(3):
    column += grey_img[:,:,i]*grey_color[i]
for i in range(3):
    grey_img[:,:,i] = column    

# imagen a escala de grises    
fig = plt.figure(figsize=(6,12))
imgplot = plt.imshow(grey_img)
plt.show()

# Se crea la imagen combinada (flor de color y resto en b/n)
hsize= len(img[0])
new_img = grey_img
flower = closest[700*900+300]
for _ in range(len(closest)):
    if closest[_] == flower:
        i = int(_/hsize)
        j = (_ - _*hsize) % hsize
        new_img[i][j] = img[i][j]

# imagen combinada
fig = plt.figure(figsize=(6,12))
imgplot = plt.imshow(new_img)
plt.show()