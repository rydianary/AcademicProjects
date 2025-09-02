## PRUEBA DE SUMA DE RANGOS DE WILCOXON

#ejemplo abejas

#n1 es el tamaño de muestra menor

samp1<-c(235,225,190,188)
samp2<-c(180,169,180,185,178,182)

a<-wilcox.test(samp1,samp2,paired=FALSE, conf.level = 0.975)
a<-wilcox.test(samp1,samp2,correct = FALSE)
a


##Mann witney 
#comparar medias entre 2 grupos cuando no conoces su distribución 

# papel estandar<tratado
# H_0:\mu_1 = \mu_2 \quad vs \quad H_a:\mu_1 < \mu_2
estandar<-c(1.43 ,1.21 ,1.35 ,1.39, 1.17, 1.48, 1.42, 1.29, 1.40)
tratado<-c(1.49 ,1.37, 1.67, 1.50, 1.31, 1.29, 1.52, 1.37, 1.44, 1.53)
a<-wilcox.test(x=estandar,y=tratado, alternative = "less", conf.level = 0.95)
a
