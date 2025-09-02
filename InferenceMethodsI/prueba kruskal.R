## prueba de kruskal 

#H0: mu1 = mu2 = mu3 vs al menos una media es diferente
#$H_0:\mu_1 = \mu_2 = \mu_3 \quad vs \quad H_a:\text{al menos una es diferente}$


A <-c(77,54,67,74,71,66)
B <-c(60,41,59,65,62,64,52)
C <- c(49,52,69,47,56)
k<-kruskal.test(list(A,B,C))
k

# se rechaza h0

#determinar que media es diferente
#install.packages("PMCMRplus")
library(PMCMRplus)
kwAllPairsDunnTest(list(A,B,C),p.adjust.method= "none")
kwAllPairsDunnTest(list(A,B,C),p.adjust.method= "holm")
kwAllPairsDunnTest(list(A,B,C),p.adjust.method= "bonferroni")