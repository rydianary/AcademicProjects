# Prueba de hipotesis para una varianza 

########PRUEBA COLA DERECHA########

#Datos
n <- 16
sig0 <- 4
scuad <- 6.1
alpha <- 0.05
df <- n-1
xa <- qchisq(alpha,df,lower.tail=FALSE)

#Hipotesis 
#H_0: scuad = sig0^2 vs H_a: scuad > sig0^2

#Estadistico
x <- (n-1)*scuad/sig0
sprintf("El valor del estadistico x es: %f",x)
sprintf("El valor del estadistico xa es: %f",xa)

#Region de rechazo
if(x>xa){
  print("Se rechaza H_0")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}

#P-valor
p <- pchisq(x,df,lower.tail=FALSE)
sprintf("El valor del pvalor es: %f",p)
if(p<=alpha){
  print("Se rechaza H_0 a un nivel alpha")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}


#############################################################################

#COLA IZQUIERDA

#Datos
n <- 16
sig0 <- 4
scuad <- 6.1
alpha <- 0.05
df <- n-1
xa <- qchisq(alpha,df)

#Hipotesis 
#H_0: scuad = sig0^2 vs H_a: scuad < sig0^2

#Estadistico
x <- (n-1)*scuad/sig0
sprintf("El valor del estadistico x es: %f",x)
sprintf("El valor del estadistico xa es: %f",xa)

#Region de rechazo
if(x<xa){
  print("Se rechaza H_0")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}

#P-valor
p <- pchisq(x,df)
sprintf("El valor del pvalor es: %f",p)
if(p<=alpha){
  print("Se rechaza H_0 a un nivel alpha")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}


#############################################################################

#DOS COLAS

#Datos
n <- 16
sig0 <- 4
scuad <- 6.1
alpha <- 0.05
df <- n-1
xad <- qchisq(alpha/2,df,lower.tail=FALSE)
xai <- qchisq(alpha/2,df)

#Hipotesis 
#H_0: scuad = sig0^2 vs H_a: scuad =! sig0^2

#Estadistico
x <- (n-1)*scuad/sig0
sprintf("El valor del estadistico x es: %f",x)
sprintf("El valor del estadistico xad es: %f",xad)
sprintf("El valor del estadistico xai es: %f",xai)

#Region de rechazo
if(x>xad || x<xai){
  print("Se rechaza H_0")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}

#P-valor
p <- 2*min(pchisq(x,df),pchisq(x,df,lower.tail=FALSE))
if(p<=alpha){
  print("Se rechaza H_0 a un nivel alpha")
}else{
  print("No se rechaza H_0 a un nivel alpha")
  print("No existe evidencia suficiente para afirmar H_1")
}


