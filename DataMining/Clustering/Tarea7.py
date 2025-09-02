"""
EQUIPO: 
 *   Fabián Ontiveros Juárez 173428
 *   Lizbeth Alondra Zamudio Paniagua 160495
 *   Regina Fierro Palomino 168093
 *   Diana Laura Reyes Youshimatz 173391
 *   Omar Emiliano Barrera Aranda 168430
 *   Jose Damián Lescas Espinosa 
"""

"""
Ejercicio 1:
    
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LinearRegression
from sklearn.metrics import accuracy_score

# Data generator function
def normal_pairs(size: int, mean: float, std: float) -> list:    
    my_data = []
    for i in range(size):
        my_data.append(np.random.normal(mean, std, 2))
    return my_data

def my_sum(x:int, start:int, end:int) -> int:
    if x == end:
        return start
    else:
        return x + 1
    
def to_pair(value: int, rows: int, cols: int) -> tuple:
    row = int(value/cols)
    col = value%cols
    return row, col

# Data creation for a specific size
samples = 500

X_1 = normal_pairs(samples, [2., 3.], [1., 1.])
X_2 = normal_pairs(samples, [5., 6.], [1., 1.])

X = np.zeros((samples*2,4))
c = 0
for i in range(samples):
    X[i][0:2] = X_1[i]
    X[i][2] = 0
    X[i][3] = c
    
    X[i+samples][0:2] = X_2[i]
    X[i+samples][2] = 1
    X[i+samples][3] = c
    
    c = my_sum(c,0,9)
    
df = pd.DataFrame(X)

data = {}

for i in range(10):
    subset = df[df[3]==i]
    sub = subset[[0,1,2]].to_numpy()
    sub_train, sub_test = train_test_split(sub, train_size=0.9, random_state=0)
    data.update({i:{'train':sub_train, 'test':sub_test}})

"""
--------------- KNN classification ------------------
"""

fig, ax = plt.subplots(2,5)
fig.set_figheight(10)
fig.set_figwidth(30)
knn_accuracy = {}

for i in range(10):
    knn_accuracy.update({i:{'train':[],'test':[]}})
    for k in range(1,11):
        model_KNN = KNeighborsClassifier(n_neighbors=k).fit(data[i]['train'][:,:2],data[i]['train'][:,2])
        y_pred_train = model_KNN.predict(data[i]['train'][:,:2])
        y_pred_test = model_KNN.predict(data[i]['test'][:,:2])
        knn_accuracy[i]['train'].append(100*accuracy_score(data[i]['train'][:,2], y_pred_train))
        knn_accuracy[i]['test'].append(100*accuracy_score(data[i]['test'][:,2], y_pred_test))
        
    pos = to_pair(i,2,5)
    ax[pos].plot(np.arange(1,11),knn_accuracy[i]['test'],color='red',marker='.',label='test', linestyle='none')
    ax[pos].plot(np.arange(1,11),knn_accuracy[i]['train'],color='blue',marker='.',label='train', linestyle='none')
    ax[pos].set_xlabel('K')
    ax[pos].set_ylabel(f'accuracy (%)')
    ax[pos].set_title(f'Subset {i+1}')
    ax[pos].legend()
    ax[pos].grid()

plt.suptitle('KNN classification accuracy for our dataset')    
plt.show()


"""
Ejercicio 2:
    
"""

# Ajuste del modelo de cuadrados mínimos
def ajuste_lineal_simple(x,y):
    a = sum(((x - x.mean())*(y-y.mean()))) / sum(((x-x.mean())**2))
    b = y.mean() - a*x.mean()
    return a, b

N = 500
minx = 2
maxx = 3
x = np.random.normal(minx, maxx, N)
r = np.random.normal(5, 6, N) # residuos simulados
y = 1.3*x + r

g = plt.scatter(x = x, y = y)
plt.title('gráfico de dispersión de los datos')
plt.xlabel('x')
plt.ylabel('y')
plt.show()

a, b = ajuste_lineal_simple(x, y)

grilla_x = np.linspace(start = minx, stop = maxx, num = 10000)
grilla_y = grilla_x*a + b

errores = y - (x*a + b)
print("ECM", (errores**2).mean())


#########################################################################
"""
A continuación, dividimos el 80% de los datos al conjunto de entrenamiento mientras que el 20% 
de los datos al conjunto de pruebas usando el código de abajo.
"""
x = np.random.normal(2,3,500) 
y = np.random.normal(5,6,500)

# Crea un dataframe con los m=1000 datos
df = pd.DataFrame({'valor': np.concatenate([x, y])})
df.shape
df2 = pd.DataFrame({'x':x, 'y':y})
df2.shape

X = df2['x'].values.reshape(-1,1)
Y = df2['y'].values.reshape(-1,1)

X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

regressor = LinearRegression() 
regressor.fit(X_train, y_train) #Entrena el algoritmo 

#Para obtener el intercepto:
print(regressor.intercept_)
#Para obtener la pendiente
print(regressor.coef_)


########################################################################
fig = plt.figure(figsize=(8,6))
plt.stem(df,
         label="Data",
         basefmt=" ")
plt.legend()
plt.show()

fig=plt.figure(figsize=(8,6))
plt.hist(df,
         bins=15,
         label="Data",
         color="purple",
         alpha=0.5,
         align="left",
         edgecolor = "black")
plt.legend()
plt.show()

fig = plt.figure(figsize=(8,6))
plt.scatter(x,y)
plt.show()



