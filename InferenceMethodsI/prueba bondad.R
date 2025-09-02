### PRUEBA CHI CUADRADA
# Ejemplo puertas ratas
puerta <-c("P1","P2","P3")
frobservada<-c(23,36,31) #n1,n2,n3 frecuencia 90 veces total
p1<-c(1/3,1/3,1/3)
chisq.test(x=frobservada, p=p1, correct=TRUE)

#instertar cuantail chisq
pchisq(2.866,2,lower.tail = FALSE)

p1<-dpois(1,0.48)
p2<-dpois(2,0.48)
p3<-dpois(3,0.48)
p4<-1-ppois(3,0.48)

acc <-c("y0","y1","y2","y3+")
frobservada<-c(32,12,36,0)
pi<-c(p1,p2,p3,p4)
chisq.test(x=frobservada, p=pi, correct=TRUE)