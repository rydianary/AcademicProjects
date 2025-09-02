# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 18:34:59 2022

@author: diana
"""

import numpy as np 

L= np.array([
    [2, -1, 0, 0, -1, 0],
    [-1, 3, -1, 0,-1, 0],
    [0, -1, 2, -1, 0, 0],
    [0, 0, -1, 3, -1, -1],
    [-1, -1, 0, -1, 2, 0],
    [0, 0, -1, -1, 0, 1]
    ])

e, v=np.linalg.eig(L)
print("eigenvalues")
print(e)
print('Eigenvectors: ')
print(v)

#matriz de pesos


