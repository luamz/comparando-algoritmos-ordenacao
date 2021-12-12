library(readr)
bolha <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/todos100k/bolha.txt", col_names = FALSE)
caixas <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/todos100k/caixas.txt", col_names = FALSE)
merge <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/todos100k/merge.txt", col_names = FALSE)
insertion <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/todos100k/insertion.txt", col_names = FALSE)


plot(bolha$X1, bolha$X2,type="l", xlab="N", ylab="Tempo de Processamento", 
     col="red", lwd = 2, main = "Comparação dos métodos de ordenação", sub = "N=100.000, passo de 1.000")
lines(caixas$X1,caixas$X2, col="royalblue", lwd = 2)
lines(merge$X1,merge$X2, col="green", lwd = 2)
lines(insertion$X1,insertion$X2, col="purple", lwd = 2)
legend(locator(1), xpd=TRUE, ncol=4,
     legend=c("Bolha", "Insertion", "Caixas","Merge"),
     fill=c("red", "purple","green", "royalblue"), bty="n")


