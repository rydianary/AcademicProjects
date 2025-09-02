library(ggplot2)
#poner bien el f-value
#poner la muestra adecuada 
#valores que no estan con NA
#comentario en boxplot
#conclusion



#hipotesis
# H_0:\mu_1=\mu_2=\mu_3=0 \quad vs \quad
# H_a \text{Al menos una diferente de cero}

#Datos
tabla <- matrix(
  c(8,7,9,13,10,
    14,16,12,17,11,
    10,12,16,15,12), nrow = 5
)
colnames(tabla) <- c("ND","DL","DC")
tabla
alpha <- 0.05
grupos <- 3
muestras <- 15
df1 <- grupos -1  
df2 <- muestras - grupos
fa <- qf(alpha,df1,df2,lower.tail = FALSE)
fa

data <- data.frame(tabla)
data <- stack(data)
data

#Graficos
ggplot(data=data,aes(x=ind,y=values,color=ind))+
  geom_boxplot()+
  theme_bw()

#Comentario: se sospecha que el grupo ND tiene una diferencia significativa en su media.

#Funcion de anova
anova_data <- aov(values~ind,data=data)
anova_data
summary(anova_data)

#pvalor
pvalor <- pf(4.933,df1,df2,lower.tail = FALSE)
pvalor
if(pvalor<alpha){
  print("Se rechaza H_0, hay al menos una media diferente de 0")
  print("Se debe proceder a la siguiente fase")
}else{
  print("No se rechaza H_0")
}

#Identificar los grupos con media diferente de cero
intervalos <- TukeyHSD(anova_data,conf.level = 1-alpha)
intervalos

plot(intervalos)

#conclusion, la diferencia significativa ocurre con el grupo DL y ND.
