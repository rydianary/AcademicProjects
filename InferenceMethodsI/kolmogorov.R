#Prueba de kolmogorov-smirnov

# probar que dos muestras X y Y provienen de la misma distribución

set.seed(190423)
x<-rexp(150, rate = 2) #rate = 1/lambda
y<-rexp(150, rate = 3)
empx<-ecdf(x) #empicircal cumulative density function
empy<-ecdf(y)
plot(empx, col="blue2")
par(new=TRUE)
plot(empy, col="red2")
ks.test(x,y,alternative = "two.side")

#dos muestras X y Y provienen de diferente distribución 

set.seed(190423)
x<-rexp(100, rate = 2.5) #rate = 1/lambda
y<-rweibull(100, shape = 3, scale = 1)
empx<-ecdf(x) #empicircal cumulative density function
empy<-ecdf(y)
plot(empx, col="blue2")
par(new=TRUE)
plot(empy, col="red2")
ks.test(x,y,alternative = "two.side")