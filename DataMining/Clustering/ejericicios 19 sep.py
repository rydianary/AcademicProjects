# -*- coding: utf-8 -*-
"""
Created on Mon Sep 19 19:12:59 2022

@author: diana
"""

import pandas as pd

archivo = open("iris.txt", "r")

lineas = archivo.readlines()
cleandata=[]
i=0
while i < len(lineas)-1:
    cleandata.append(lineas[i].split(sep=","))
    i+=1
print(cleandata[0]) 
for i in range(len(cleandata)):
    cleandata[i][0] = float(cleandata[i][0])
    cleandata[i][1] = float(cleandata[i][1])
    cleandata[i][2] = float(cleandata[i][2])
    cleandata[i][3] = float(cleandata[i][3])
df = pd.DataFrame(cleandata)
df.columns = ["Sepal_length","Sepal_width","Petal_length","Petal_width","Class"]
print(df)
mean1 = df['Sepal_length'].mean()
print(mean1)
max1 = df['Sepal_length'][1]
print("guaoooo",max1)
min1 = df['Sepal_length'].min()
print(min1)
std1 = df['Sepal_length'].std()
print(std1)
mean2 = df['Sepal_width'].mean()
print(mean2)
max2 = df['Sepal_width'].max()
print(max2)
min2 = df['Sepal_width'].min()
print(min2)
std2 = df['Sepal_width'].std()
print(std2)
mean3 = df['Petal_length'].mean()
print(mean3)
max3 = df['Petal_length'].max()
print(max3)
min3 = df['Petal_length'].min()
print(min3)
std3 = df['Petal_length'].std()
print(std3)
mean4 = df['Petal_width'].mean()
print(mean4) 
max4 = df['Petal_width'].max()
print(max4)
min4 = df['Petal_width'].min()
print(min4)
std4 = df['Petal_width'].std()