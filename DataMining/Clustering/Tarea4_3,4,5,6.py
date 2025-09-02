# -*- coding: utf-8 -*-
"""
Created on Thu Sep 15 13:29:55 2022

@author: Hugo
"""
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

#Cargamos archivo y lo leemos por línea.
archivo = open("SSNMX_catalogo_19800101_20220908_m40_100_TAREA_4.txt", "r")
text = archivo.readlines()

#Leemos los datos sin las primeras ni últimas filas
cleandata = []
for i in range(len(text)-13):
    cleandata.append(text[i+6])

#Separamos los datos por categoría, sin embargo hay una coma que sí debería estar.
for i in range(len(cleandata)):
    cleandata[i] = cleandata[i].split(",")
    
#Enmendamos la coma necesitada.
for i in range(len(cleandata)):
    cleandata[i][6]+= "," + cleandata[i][7]

#Convertimos los valores "Numéricos" como valores float.
for i in range(len(cleandata)):
    cleandata[i][2] = float(cleandata[i][2])
    cleandata[i][3] = float(cleandata[i][3])
    cleandata[i][4] = float(cleandata[i][4])
    #Para profundidad, existe una categoría de "En revisión". En este caso la tomamos como -1 ya que no es posible una profundidad de -1. 
    if cleandata[i][5] == "en revision":
        cleandata[i][5] = -1
    else:
        cleandata[i][5] = float(cleandata[i][5])
    
    

#Creamos el dataframe con la data limpia y enmendamos el error de la coma.
df = pd.DataFrame(cleandata)
df.columns = ["Fecha","Hora","Magnitud","Latitud","Longitud","Profundidad","Referencia de localizacion","","Fecha UTC","Hora UTC","Estatus"]
del df[""]

#Encontramos los datos de los 10 terremotos con mayor magnitud y los imprimimos.
Mag = df.sort_values("Magnitud", ascending=False).head(10)
print("Información de los 10 terremotos con mayor magnitud:")
print(Mag)

print("\nEjercicio 3\n")
#Sabiendo el formato que tiene la fecha, usamos la función split con "-" posteriormente empatamos con el año correspondiente, se genera un promedio y después una lista.
for i in range(43):
    lista_año = []
    for j in range(len(df)):
        x = df["Fecha"].loc[j].split("-")[0]
        if(x == str(1980+i)):
            lista_año.append(df["Magnitud"].loc[j])
    print(f"La magnitud promedio del año {1980+i} es: {np.mean(lista_año)}")
#Se ulitiza el mismo método que en el ejercicio 3, en este cas para el mes
lista_mes=[]
for i in range(12):
    for j in range(len(df)):
        x = df["Fecha"].loc[j].split("-")[1]
        if(x == str(i+1) or x=="0"+str(i+1)):
            lista_mes.append(i+1)

#Se crea ek histograma
fig = plt.figure(figsize = (12,6))
plt.hist(lista_mes, bins=[1,2,3,4,5,6,7,8,9,10,11,12], align="mid", color = "b")
plt.title("Terremotos por mes")
fig.savefig("terremotos por mes.pdf", format="pdf", dpi = 1200)
fig = plt.figure(figsize = (12,6))
#Observando la figura, si es septiembre jajajaja

#Definimos como "x" y "y" al encontrar a los terremontos con Magnitud menor a 5
x = df[df["Magnitud"]<5.0]["Longitud"]
y = df[df["Magnitud"]<5.0]["Latitud"]
#Se crea la gráfica
plt.plot(x, y, linestyle = "None", marker = "x", color = "b", label = "Magnitud menor a 5 grados R")

#Definimos como "x" y "y" al encontrar a los terremontos con Magnitud mayor o igual a 5
x = df[df["Magnitud"]>=5.0]["Longitud"]
y = df[df["Magnitud"]>=5.0]["Latitud"]
#Se genera la gráfica 
plt.plot(x, y, linestyle = "None", marker = ".", color = "r", label = "Magnitud mayor o igual a 5 grados R")
plt.legend()
plt.title("Ubicación geográfica de terremotos desde 1980.")
fig.savefig("Terremotos_1980+.pdf", format="pdf", dpi = 1200)

#Ejercicio 6, se filtran los datos para hacer uso únicamente de los de 2021, y se hace un proceso igual al del ejercicio anterior
datos_2021 = []
for j in range(len(df)):
    x = df["Fecha"].loc[j].split("-")[0]
    if(x == str(2021)):
        datos_2021.append(df.loc[j])  
datos_2021 = pd.DataFrame(datos_2021)
datos_2021.columns = df.columns

fig = plt.figure(figsize = (12,6))
x = datos_2021[datos_2021["Magnitud"]<5.0]["Longitud"]
y = datos_2021[datos_2021["Magnitud"]<5.0]["Latitud"]

plt.plot(x, y, linestyle = "None", marker = "x", color = "black", label = "Magnitud menor a 5 grados R")

x = datos_2021[datos_2021["Magnitud"]>=5.0]["Longitud"]
y = datos_2021[datos_2021["Magnitud"]>=5.0]["Latitud"]

plt.plot(x, y, linestyle = "None", marker = ".", color = "red", label = "Magnitud mayor o igual a 5 grados R")
plt.legend()
plt.title("Ubicación geográfica de terremotos 2021.")
plt.show()
fig.savefig("Terremotos_2021.pdf", format="pdf", dpi = 1200)


