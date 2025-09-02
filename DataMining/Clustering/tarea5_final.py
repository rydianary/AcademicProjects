import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import AgglomerativeClustering
from scipy.cluster.hierarchy import dendrogram
from scipy.cluster.hierarchy import linkage
import matplotlib.image as mpimg

data = np.array([[2.3,9],[6,2],[1,7],[4,3],[5,1.5]])
plt.scatter(data[:,0], data[:,1])
plt.title("El dato se define como R2")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()

#1er dendo
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="single")
print(hierarchical_clustering)
cluster_1 = hierarchical_clustering.fit_predict(data)
print("Método de agrupamiento único ", cluster_1)

for i in range(len(cluster_1)):
    if cluster_1[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "pink", label = "1er Cluster")
    elif cluster_1[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "cyan", label = "2do Cluster")
    elif cluster_1[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "violet", label = "3er Cluster")

plt.title("Agrupación jerárquica con método único")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

linkage_data = linkage(data, method="single",metric="euclidean")
dendrogram(linkage_data)
plt.title("Metodo del Dendrograma")
plt.show()  



#2do dendo
hierarchical_clustering = AgglomerativeClustering(n_clusters = 3, affinity="euclidean",linkage="ward")
print(hierarchical_clustering)
cluster_2 = hierarchical_clustering.fit_predict(data)

print("método de agrupamiento: ",cluster_2)
for i in range(len(cluster_2)):
    if cluster_2[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "pink", label = "1er Cluster")
    elif cluster_2[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "cyan", label = "2do Cluster")
    elif cluster_2[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "violet", label = "3ro Cluster")

plt.title("Agrupación jerárquica con método ward")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

linkage_data = linkage(data, method="ward",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendograma con método de Ward")
plt.show()  


#3er dendo
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="average")
print(hierarchical_clustering)
cluster_3 = hierarchical_clustering.fit_predict(data)
print("Promedio del método de agrupamiento ",cluster_3)

for i in range(len(cluster_3)):
    if cluster_3[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "pink", label = "1ro Cluster")
    elif cluster_3[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "cyan", label = "2do Cluster")
    elif cluster_3[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "violet", label = "3ro Cluster")

plt.title("Agrupación jerárquica con método de promedio")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()


linkage_data = linkage(data, method="average",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendograma con método promedio")
plt.show()



#4to dendo
hierarchical_clustering = AgglomerativeClustering(n_clusters=3,affinity="euclidean",linkage="complete")
print(hierarchical_clustering)
cluster_4 = hierarchical_clustering.fit_predict(data)
print("Método de agrupamiento completo ",cluster_4)

for i in range(len(cluster_4)):
    if cluster_4[i] == 0:
        plt.scatter(data[i, 0], data[i, 1], c = "pink", label = "1ro Cluster")
    elif cluster_4[i] == 1:
        plt.scatter(data[i, 0], data[i, 1], c = "cyan", label = "2do Cluster")
    elif cluster_4[i] == 2:
        plt.scatter(data[i, 0], data[i, 1], c = "violet", label = "3ro Cluster")


plt.title("Agrupación jerárquica con método completo")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()


linkage_data = linkage(data, method="complete",metric="euclidean")
dendrogram(linkage_data)
plt.title("Dendograma con método completo")
plt.show()

### Ejercicio 3 y 4
# esta libreria simplemente nos ayuda a calcular la distancia entre 
# los centroides y todos los puntos de una manera mas sencilla
from scipy.spatial.distance import cdist

#np.random.seed(##)


def Kmeans(data, k):
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

img = np.array(mpimg.imread('imagen.png'))
data_matrix = img.reshape(-1,3)
kmeans = Kmeans(data_matrix,3) 
closest, centers = kmeans
colors = np.array([[0,0,0],[1,1,1],[0,0,1],[1,0,0],[0,1,0]])
image_kmeans=np.copy(img)

index=0
data_matrix=[]
for i in range(len(img)):
    for j in range(len(img[0])):
        image_kmeans[i][j]=colors[closest[index]]
        index=index+1
        
fig = plt.figure(figsize=(12,6))
imgplot = plt.imshow(img)
plt.show()

fig = plt.figure(figsize=(12,6))
imgplot = plt.imshow(image_kmeans)
plt.show()

### Ejercicio 5

def Distancia(vector1, vector2):
    dist = 0
    for i in range(len(vector1)):
        temp = (vector1[i]-vector2[i])
        dist+= temp * temp 
    return np.sqrt(dist)

def DistanciaMinima(lista_vectores, centroides):
    dist = []
    for i in range(len(lista_vectores)):
        dist.append([])
        for j in range(len(centroides)):
            dist[i].append(Distancia(lista_vectores[i], centroides[j]))
    
    for i in range(len(dist)):
        dist[i] = np.min(dist[i])
    return dist


def Centroide(lista_vectores):
    centroide=[]
    for i in range(len(lista_vectores)):
        promedio_i=0
        for j in range(len(lista_vectores[0])):
            promedio_i=promedio_i+lista_vectores[j][i]
        promedio_i=promedio_i/len(lista_vectores) 
        centroide.append(promedio_i) 
    return centroide



def Kmeans(lista_vectores, k, iters = 10, randstate = 0):
    rng = np.random.RandomState(randstate)
    firstclusters = rng.randint(k, size = len(lista_vectores))
    centroides = []
    kmeans = []
    for i in range(k):
        cluster = []
        for j in range(len(lista_vectores)):
            if firstclusters[j] == i:
                cluster.append(lista_vectores[j])
        centroides.append(Centroide(cluster))
        
    kmeans = firstclusters
    
    for x in range(iters):
        distanciaMinima= DistanciaMinima(lista_vectores, centroides)
        
        for i in range(k):
            for j in range(len(lista_vectores)):
                if Distancia(lista_vectores[j], centroides[i]) == distanciaMinima[j]:
                    kmeans[j] = i
                    
        for i in range(k):
            cluster = []
            for j in range(len(lista_vectores)):
                if kmeans[j] == i:
                    cluster.append(lista_vectores[j])
            centroides[i] = Centroide(cluster)
                    
    return kmeans

img = mpimg.imread("imagen2.png")

def tograyscale(pixel):
    n = 0.3*pixel[0] + 0.59*pixel[1] + 0.11*pixel[2]
    pixel[0] = n
    pixel[1] = n
    pixel[2] = n
    
    return pixel

print("Ejercicio 5:")
data_matrix = []
for i in range(len(img)):
    for j in range(len(img[0])):
        data_matrix.append(img[i][j])


kmeans = Kmeans(data_matrix, k = 7, iters = 5, randstate = 34178)
image_kmeans = np.copy(img)
print("kmeans done")


colors = [[0,0,0],[1,1,1],[0,0,1],[0,1,0],[1,0,0],[0,1,1],[1,0,1], [1,1,0]]
index = 0
data_matrix = []
for i in range(len(img)):
    for j in range(len(img[0])):
        #if not (kmeans[index] == 2 or kmeans[index] == 4):
        #if not (kmeans[index] == 2 or kmeans[index] == 4):
            image_kmeans[i][j] = tograyscale(image_kmeans[i][j])
            index+=1
        #else:
         #   index+=1
        
fig = plt.figure(figsize = (6,12))
imgplot = plt.imshow(img)
plt.show()

fig = plt.figure(figsize = (6,12))
imgplot = plt.imshow(image_kmeans)
plt.show()
fig.savefig("Blanco y negro.png", format = "png", dpi = 200)