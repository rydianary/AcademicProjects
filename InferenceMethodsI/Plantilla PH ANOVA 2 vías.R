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

#RESUMEN DE INDICADORES
#variable categórica 1
with(data = datos,expr = tapply(varcat1, respuesta, mean))
with(data = datos,expr = tapply(varcat1, respuesta, sd))
#variable categórica 2 
with(data = datos,expr = tapply(varcat2, respuesta, mean))
#with(data = datos,expr = tapply(varcat2, respuesta, sd))
# variable 1 y variable 2
with(data = datos,expr = tapply(respuesta, list(varcat2,respuesta), mean))
with(data = datos,expr = tapply(respuesta, list(varcat2,respuesta), sd))

#GRÁFICOS DE INTERACCIÓN
interaction.plot(varcat1, varcat2, respuesta, col = 1:6, type = "b")
interaction.plot(varcat2, varcat1, respuesta,col = 2:5, type = "b")

ggplot(data = datos, aes(x = varcat2, y = respuesta, colour = varcat1,
                         group = varcat1)) +
  stat_summary(fun = mean, geom = "point") +
  stat_summary(fun = mean, geom = "line") +
  labs(y  =  'mean (resistencia)') +
  theme_bw()

#ANOVA
anova <- aov(respuesta ~ varcat1 * varcat2, data = datos)
summary(anova)
anovadd <- aov(respuesta ~ varcat1 + varcat2, data = datos)
summary(anovadd)

#Conclusión
#VARCAT 1: 
#  $H_0:\mu_1=\mu_2...\mu_6$
#  $H_a:\mu_1\neq\mu_2$
#VARCAT 2: 
#  $H_0:\mu_1=\mu_2...\mu_6$
#  $H_a:\mu_1\neq\mu_2$  
#  comentario conclusión