# -*- coding: utf-8 -*-
"""
Created on Mon Nov 14 18:10:24 2022

@author: diana
"""
#ejercicio 6
#el conteo de la posicion del minimo es apartir de 0 
def min_index(lista):
    minm=lista[0]
    for i in range (len(lista)): 
        if lista[i]<=minm:
            minm=lista[i]
            place=i
    return minm, place

lista1=[5,4,3,2,1,1]

print(min_index(lista1))


#ejercicio 7
import numpy as np

a=np.array
b=np.array
def producto_matrices(a, b):
    filas_a = len(a)
    filas_b = len(b)
    columnas_a = len(a[0])
    columnas_b = len(b[0])
    if columnas_a != filas_b:
        print('no es posible realizar este producto')
        return 0

    ######
    
    producto=np.empty([filas_a,columnas_b])
    
    for c in range(columnas_b):
        for i in range(filas_a):
            suma = 0
            for j in range(columnas_a):
                suma += a[i][j]*b[j][c]
            producto[i][c] = suma
    return producto



print(producto_matrices([[1,2],[3,4],[5,6]],[[1,2,3],[3,4,5]]))    

print(producto_matrices([[1,2,3,4,5,6],[3,4],[5,6]],[[1,2,3],[3,4,5]]))    
