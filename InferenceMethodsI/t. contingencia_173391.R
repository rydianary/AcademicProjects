#H0 = son dependientes vs Ha= son independientes

tabla <- matrix(c(24,9,13,289,100,565),byrow=TRUE,
                nrow=2)
colnames(tabla)<- c("No vacuna","una vacuna","dos vacunas")
rownames(tabla)<- c("gripe", "no gripe")
tabla
chisq.test(tabla)

#Un grafico de mosaico despliega informacion para examinar la relacion ente dos  o más variables categoricas.
mosaicplot(tabla,color=T)
prop.table(tabla)

#El barplot describe las frecuencias de todas las observaciones de las variables categoricas.
barplot(tabla, legend = rownames(tabla),
        beside=F,axis.lty=1)

#Otra forma de presentar es ajustando las categorias en orden separado, dependiendo 
#de cual es el interes en la forma de como presentar sus resultados.
barplot(tabla, legend=rownames(tabla),
        beside=T,axis.lty=2)

#Conclusi?n: se rechaza H0, si son independientes el numero de vacunas.El hecho de que te de gripe no depende de si te vacunaste.


#Ejemplo 2

#H0 = son independientes vs Ha= son dependientes

tabla <- matrix(c(15,21,45,13,26,31,34,5,33,17,49,20),byrow=TRUE,
                nrow=3)
colnames(tabla)<- c("A","B","C","D")
rownames(tabla)<- c("1","2","3")
tabla
chisq.test(tabla)

#Un grafico de mosaico despliega informacion para examinar la relacion ente dos  o más variables categoricas.
mosaicplot(tabla,color=T)
prop.table(tabla)

#El barplot describe las frecuencias de todas las observaciones de las variables categoricas.
barplot(tabla, legend = rownames(tabla),
        beside=F,axis.lty=1)

#Otra forma de presentar es ajustando las categorias en orden separado, dependiendo 
#de cual es el interes en la forma de como presentar sus resultados.
barplot(tabla, legend=rownames(tabla),
        beside=T,axis.lty=2)

#CONCLUSION: Se rechaza H0, son dependientes.

#Ejemplo 2

#H0 = son independientes vs Ha= son dependientes

tabla <- matrix(c(15,21,45,13,26,31,34,5,33,17,49,20),byrow=TRUE,
                nrow=3)
colnames(tabla)<- c("A","B","C","D")
rownames(tabla)<- c("1","2","3")
tabla
chisq.test(tabla)

#Un grafico de mosaico despliega informacion para examinar la relacion ente dos  o más variables categoricas.
mosaicplot(tabla,color=T)
prop.table(tabla)

#El barplot describe las frecuencias de todas las observaciones de las variables categoricas.
barplot(tabla, legend = rownames(tabla),
        beside=F,axis.lty=1)

#Otra forma de presentar es ajustando las categorias en orden separado, dependiendo 
#de cual es el interes en la forma de como presentar sus resultados.
barplot(tabla, legend=rownames(tabla),
        beside=T,axis.lty=2)

#CONCLUSION: Se rechaza H0, son dependientes.