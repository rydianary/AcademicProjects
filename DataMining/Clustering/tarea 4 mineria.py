# -*- coding: utf-8 -*-
"""
Created on Fri Sep 16 21:21:05 2022

@author: USER
"""

import pandas as df
from datetime import datetime
import matplotlib.pyplot as plt
import statistics as st

file = open("SSNMX_catalogo_19800101_20220908_m40_100_TAREA_4.txt")
text= file.readlines()
file.close()

#Encontrar los 10 terremotos con mayor magnitud
Mag = df.sort_values("Magnitud",ascending=False).head(10)
print("Informacion de los 10 terremotos con mayor magnitud")
print(Mag)
