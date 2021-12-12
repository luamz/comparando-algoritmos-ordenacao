library(readr)
merge <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/grafico1/merge.txt", col_names = FALSE)
#1
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge",
     sub = "Números entre 0 e 1000, passo de 10")
#2
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge", 
     sub = "Números entre 0 e 1000, passo de 100")

#3
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge",
     sub = "N= 1.000, Números entre 0 e 1000, passo de 10")
#4
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge",
     sub = "N= 10.000, Números entre 0 e 1000, passo de 10")


#5
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge",
     sub = "Números aleatórios entre 0 e 1000, passo de 100")

#6
plot(merge$X1, merge$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="royalblue", lwd = 2, main = "Método Merge",
     sub = "Números aleatórios entre 0 e 10000, passo de 100")



