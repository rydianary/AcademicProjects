#Prueba de hipótesis cociente de varianzas


########PRUEBA COLA DERECHA########

#Datos
n1 <- 10
n2<-20
scuad1 <- 0.0003 #var 1
scuad2 <- 0.0001 #var 2
alpha <- 0.05
df1 <- n1-1
df2 <- n2-1
fa <- qf(alpha,df1, df2,lower.tail=FALSE)

#Hipotesis 
#H_0: sig1^2 = sig^2 vs H_a: sig1^2 > sig2^2

#Estadistico
fc<-scuad1/scuad2

sprintf("El valor del estadistico x es: %f",fa)
sprintf("El valor del estadistico xa es: %f",fc)

#Region de rechazo
if(fc>fa){
  print("Se rechaza H_0")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}

#P-valor
p <- pf(fc,df1,df2,lower.tail=FALSE)
sprintf("El valor del pvalor es: %f",p)
if(p<=alpha){
  print("Se rechaza H_0 a un nivel alpha")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}


#############################################################################

#COLA IZQUIERDA

#intercambiamos los indices de las muestras y aplicamos 
#prueaba cola derecha


#############################################################################

#DOS COLAS
#el tamaño de varianza más grande pertence a grupo n1 

#Datos
n1 <- 10
n2<-14
scuad1 <- 26.4
scuad2 <- 12.7
alpha <- 0.05
df1 <- n1-1
df2 <- n2-1
fa <- qf(alpha/2,df1, df2,lower.tail=FALSE)

#Hipotesis 
#H_0: sig1^2 = sig2^2 vs H_a: sig1^2=! sig2^2

#Estadistico
fc<-scuad1/scuad2

sprintf("El valor del estadistico x es: %f",fa)
sprintf("El valor del estadistico xa es: %f",fc)

#Region de rechazo
if(fc>fa){
  print("Se rechaza H_0")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}

#P-valor
p <- pf(fc,df1,df2,lower.tail=FALSE)
sprintf("El valor del pvalor es: %f",p)
if(p<=alpha){
  print("Se rechaza H_0 a un nivel alpha")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}



