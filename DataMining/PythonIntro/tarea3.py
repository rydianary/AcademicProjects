# -*- coding: utf-8 -*-
"""
Created on Mon Aug 22 16:41:33 2022

@author: Alejandro Josaphat Ramírez Sánchez
         Regina Fierro Palomino 
         Diana Laura Reyes Youshimatz
         Guillermo Francisco Ramírez Pérez
         Antoine Bregeon
"""

import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
#import yfinance as yf

"""
Pa"rte 1:
"""

""""
fig = plt.figure(figsize = (12,6))
#Creating an empty dataframe
df = pd.DataFrame()
#Putting the stock labels on a list for management
tickers = ["AAPL","AMZN","META","NFLX","GOOG"]
#Filling the dataframe with the Yahoo Finance values for each stock's price from the start 
#of 2022 to August 23rd, 2022 on a daily interval
for ticker in tickers:
    df[ticker] = yf.Ticker(ticker).history(start = "2022-01-01", end = "2022-08-23", interval = "1d").Close
#Plotting the dataframe with the stock labels as the labels of the 
plt.plot(df, label = tickers)
plt.legend()
plt.show()
#Saving the plot on a pdf format
fig.savefig("Stock performance from start of year.pdf", format = "pdf", dpi = 1200)
"""

"""
Parte 2:
"""
def exp_serie(x, n):
    #Creando arreglo vacío serie
    serie = []
    #Para cada i de 0 a n (usamos n+1 para tomar en cuenta n en el rango) evaluamos 
    #el término de la función y lo añadimos a la lista serie
    for i in range(n+1):
        xn = (x**i) / np.math.factorial(i)
        serie.append(xn)
    return serie

colors = ["blue","purple","red","orange","yellow"]
names = ["aproximacion_1.pdf","aproximacion_2.pdf","aproximacion_3.pdf","aproximacion_4.pdf","aproximacion_5.pdf"]
labels = []

for i in range(5):
    label = "aproximación con n = " + str(i+1)
    labels.append(label)

for i in range(5):
    fig = plt.figure(figsize = (12,6))
    eje_x = np.arange(-2-(0.5*i),2+(0.5*1), 0.01)
    eje_y = []
    #para cada elemento del eje x, añadimos la suma de los terminos de la 
    #serie de potencias que caratreriza la función exponencial en x con i+1 (de 1 a 5)
    for j in range(len(eje_x)):
        eje_y.append(np.sum(exp_serie(eje_x[j], i+1)))
        
    
    eje_x_exp = np.arange(-2-(0.5*i),2+(0.5*1), 0.01)
    eje_y_exp = np.exp(eje_x_exp)

    plt.plot(eje_x, eje_y, label = labels[i], color = colors[i])
    plt.plot(eje_x_exp, eje_y_exp, label = "exp(x)", color = "black")
    plt.legend()
    fig.savefig(names[i], format = "pdf", dpi = 1200)
    
    
"""
Parte 3: 
"""
#Creating the path graph's adjacency matrix with size n (square matrix)
def mat_path(n):
    a = np.zeros(shape = (n,n))
    for i in range(n-1):
        a[i][i+1] = 1
        a[i+1][i] = 1
    return a

#Creating a list from i = 1 to n for the expression 2cos-(iπ/n+1))
def list_k(n):
    list1 = []
    for i in range(n):
        result = 2*np.cos((np.pi*i)/(n+1))
        list1.append(result)
    return list1


#Plotting the histogram of the eigenvalues of the adjacency matrix of size 1000
fig = plt.figure(figsize = (12,6))
x = mat_path(500)
eigenvalue = np.linalg.eigvals(x)
plt.hist(eigenvalue, color = "red")
plt.title("Histograma de valores propios con n=500")
fig.savefig("Valores propios con n=500.pdf", format = "pdf", dpi = 1200)

#Plotting the list from i = 1 to n = 500 for the expression 2cos-(iπ/n+1)
fig = plt.figure(figsize = (12,6))
k_list = list_k(500)
plt.hist(k_list, color = "purple")
plt.title("Histograma de lista de i=1 a n con n=500")
fig.savefig("Lista de i=1 a n con n=500.pdf", format = "pdf", dpi = 1200)

#Plotting the histogram of the eigenvalues of the adjacency matrix of size 1000
fig = plt.figure(figsize = (12,6))
x = mat_path(1000)
eigenvalue = np.linalg.eigvals(x)
plt.hist(eigenvalue, color = "yellow")
plt.title("Histograma de valores propios con n=1000")
fig.savefig("Valores propios con n=1000.pdf", format = "pdf", dpi = 1200)

#Plotting the list from i = 1 to n = 1000 for the expression 2cos-(iπ/n+1)
fig = plt.figure(figsize = (12,6))
k_list = list_k(1000)
plt.hist(k_list, color = "orange")
plt.title("Histograma de lista de i=1 a n con n=1000")
fig.savefig("Lista de i=1 a n con n=1000.pdf", format = "pdf", dpi = 1200)