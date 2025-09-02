#FORMULACIÓN DATA FRAME
respuesta<-c(1.12,1.73,1.04,1.86,1.47,2.10,1.15,1.72,1.10,1.87,1.46,2.15)
varcat1<-c(rep(c("compu 1", "compu 2"), c(6,6)))
varcat2<-rep(c("p1","p2","p3","p4","p5","p6"), each =1, times =2)

datos <-data.frame(varcat1 = varcat1, varcat2=as.factor(varcat2), respuesta = respuesta) 
datos

# BOXPLOTS
library(ggplot2)
library(gridExtra)
ggplot(data = datos, aes(x = varcat2, y = respuesta)) +
  geom_boxplot() + theme_bw()

ggplot(data = datos, aes(x = varcat1, y = respuesta)) +
  geom_boxplot() + theme_bw()

ggplot(data = datos, aes(x = varcat2, y = respuesta, colour = varcat1)) +
  geom_boxplot() + theme_bw()

#GRÁFICOS DE INTERACCIÓN
interaction.plot(varcat1, varcat2, respuesta, col = 1:6, type = "b")
interaction.plot(varcat2, varcat1, respuesta,col = 2:5, type = "b")

#ANOVA
anova <- aov(respuesta ~ varcat1 * varcat2, data = datos)
summary(anova)
anovadd <- aov(respuesta ~ varcat1 + varcat2, data = datos)
summary(anovadd)

#Suposición previa boxplot

# Intepretación de los gráficos de interacción

#Hipótesis
#VARCAT 1: 
#  $H_0:\mu_1=\mu_2=...=\mu_6$
#  $H_a: \quad\text{alguna} \,\mu\, \text{es diferente}$
#VARCAT 2: 
#  $H_0:\mu_1=\mu_2=...=\mu_6$
#  $H_a: \quad\text{alguna} \,\mu\, \text{es diferente}$  

#Elgimos el modelo multiplicativo cuando la magnitud del patrón estacional en los datos dependa 
#de la magnitud de los datos. En otras palabras, la magnitud del patrón estacional aumenta a
#medida que aumentan los valores de los datos y disminuye a medida que disminuyen los valores 
#de los datos.

#Elija el modelo aditivo cuando la magnitud del patrón estacional en los datos no 
#dependa de la magnitud de los datos. En otras palabras, la magnitud del patrón estacional 
#no cambia a medida que la serie sube o baja.

#Elegimos entre los dos procedimientos aditivo y multiplicativo, el MULTIPLICATIVO/ ADITIVO puesto que tiene 
#medidas de precisión más pequeñas.

# Conclusión
#Dafo que Pr NUM<> 0.5