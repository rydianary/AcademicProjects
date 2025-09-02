#Ejemplo diapositiva 8

#H0: p1=p2=p3=1/3 vs Ha: Al menos una es diferente

#variable categorica
puerta <- c("P1","P2","P3")

#variable que guarde las frecuencias de las categorias
fr.observada <- c(23,36,31)

#probabilidad de la categoria i
pi <- c(1/3,1/3,1/3)

chisq.test(x=fr.observada,p=pi,correct=TRUE)

p <- pchisq(2.87,2,lower.tail = FALSE) #Se debe hacer o del chisq.test lo tomo?
 if (p<0.05){
   print("Se rechaza H0")
 }else{
   print("No se rechaza H0")
 }
p

#################################################################################

#Ejercicio accidentes (probar si los datos provienen de una distribucion)


# H0 = Y se distribuye Poisson(lambda) vs Ha = Y no se distribuye poisson

#1. Enconcontrar EMV de lambda. Recordemos que lambda = promedio, entonces EMV=Xbar

Xbar <- (0*32+1*12+2*6)/50 #Promedio ponderado #por que?
Xbar

y <- c(0,1,2,3) #numero de accidentes
frec <-c(32,12,6,0) #Frecuencia del numero de accidentes (vector de pesos)
weighted.mean(y,frec)

n <- 50 #numero de semanas

p1 <- dpois(0,Xbar, log=FALSE)
p1
p2 <- dpois(1,Xbar, log=FALSE)
p2
p3 <- dpois(2,Xbar, log=FALSE)
p3
p4 <- 1 - (p1+p2+p3)
p4

#Valores esperados de npi E(ni) = n*pi

np1 <- n*p1
np1
np2 <- n*p2
np2
np3 <- n*p3
np3
np4 <- n*p4
np4

#COMENTARIO se suman np3 y np4 ya que npi<=5

#variable categorica
accidentes <- c("Y0","Y1","Y2")

#variable que guarde las frecuencias de las categorias
fr.observada <- c(32,12,6+0) #se suman las ultimas dos para que n>=5

#probabilidad de la categoria i
pi <- c(p1,p2,p3+p4) #se suman las ultimas dos para que n>=5

chisq.test(x=fr.observada,p=pi,correct=TRUE)

p <- pchisq(1.3447,2,lower.tail = FALSE)
if (p<0.05){
  print("Se rechaza H0")
}else{
  print("No se rechaza H0")
}
p

################################################################################

#Ejercicio diapositiva 14

#H0: A = .41 B=.1 AB=.04 y O=.45 vs Ha: al menos una igualdad es diferente

#variable categorica
gruposanguineo <- c("A","B","AB","O")

#variable que guarde las frecuencias de las categorias
fr.observada <- c(89,18,12,81)

#probabilidad de la categoria i
pi <- c(.41,.1,.04,.45)

chisq.test(x=fr.observada,p=pi,correct=TRUE)

p <- pchisq(3.6976,3,lower.tail = FALSE) 
if (p<0.05){
  print("Se rechaza H0")
}else{
  print("No se rechaza H0")
}
p

#No se rechaza H0, no existe suficiente evidencia para para afirmar que las proporciones actuales difieren de los valores historicos

################################################################################

#Ejercicio diapositiva 15

#H0: cafe =.13, amarillo=.14, rojo=.13, azul=.24, naranja=.2 y verde=.16
#Ha: al menos una igualdad es diferente

#variable categorica
color <- c("cafe","amarillo","rojo","azul","naranja","verde")

#variable que guarde las frecuencias de las categorias
fr.observada <- c(70,72,61,118,108,85)

#probabilidad de la categoria i
pi <- c(.13,.14,.13,.24,.20,.16)

chisq.test(x=fr.observada,p=pi,correct=TRUE)

p <- pchisq(1.2468,5,lower.tail = FALSE) 
if (p<0.05){
  print("Se rechaza H0")
}else{
  print("No se rechaza H0")
}
p

#No se rechaza H0, los datos justifican los porcentajes informados por Mars, Incorporated

################################################################################

#Ejercicio diapositiva 16

# H0 = Y se distribuye Poisson(lambda) vs Ha = Y no se distribuye poisson

#1. Enconcontrar EMV de lambda. Recordemos que lambda = promedio, entonces EMV=Xbar


y <- c(0,1,2,3,4,5,6,7,8,9,10,11,19) #numero de colonias
frec <-c(56,104,80,62,42,27,9,9,5,3,2,0,1) #Frecuencia del numero de colonias (vector de pesos)
Xbar <- weighted.mean(y,frec) #promedio ponderado?
Xbar

n <- 400 #numero de observaciones

p1 <- dpois(0,Xbar) #por que no da lo mismo?
p2 <- dpois(1,Xbar, log=FALSE)
p3 <- dpois(2,Xbar, log=FALSE)
p4 <- dpois(3,Xbar, log=FALSE)
p5 <- dpois(4,Xbar, log=FALSE)
p6 <- dpois(5,Xbar, log=FALSE)
p7 <- dpois(6,Xbar, log=FALSE)
p8 <- dpois(7,Xbar, log=FALSE)
p9 <- dpois(8,Xbar, log=FALSE)
p10 <- dpois(9,Xbar, log=FALSE)
p11 <- dpois(10,Xbar, log=FALSE)
p12 <- dpois(11,Xbar, log=FALSE)
p13 <- 1-(p1+p2+p3+p4+p5+p6+p7+p8+p9+p10+p11+p12)


#Valores esperados de npi E(ni) = n*pi

np1 <- n*p1
np1
np2 <- n*p2
np2
np3 <- n*p3
np3
np4 <- n*p4
np4
np5 <- n*p5
np5
np6 <- n*p6
np6
np7 <- n*p7
np7
np8 <- n*p8
np8
np9 <- n*p9
np9
np10 <- n*p10
np10
np11 <- n*p11
np11
np12 <- n*p12
np12
np13 <- n*p13
np13

np <- np8+np9+np10+np11+np12+np13
np

#COMENTARIO se suman np8+...+np13?

#variable categorica
colonias <- c("Y0","Y1","Y2")

#variable que guarde las frecuencias de las categorias
fr.observada <- c(56,104,80,62,42,27,9,9+5+3+2+1) #se suman las ultimas para que n>=5

#probabilidad de la categoria i
pi <- c(p1,p2,p3,p4,p5,p6,p7,p8+p9+p10+p11+p12+p13) #se suman las ultimas  para que n>=5

chisq.test(x=fr.observada,p=pi,correct=TRUE)

p <- pchisq(74.946,7,lower.tail = FALSE)
if (p<0.05){
  print("Se rechaza H0")
}else{
  print("No se rechaza H0")
}
p

#Se rechaza H0, hay suficiente evidencia para decir que los datos no se ajustan a la distribucion de Poisson