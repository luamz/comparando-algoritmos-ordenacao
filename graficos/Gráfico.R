library(readr)
bolha <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/bolha.txt", col_names = FALSE)
caixas <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/caixas.txt", col_names = FALSE)
merge <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/merge.txt", col_names = FALSE)
insertion <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/insertion.txt", col_names = FALSE)


plot(bolha$X1, bolha$X2,type="l", xlab="N", ylab="Tempo de Processamento",
     col="red", lwd = 2, main = "Comparação dos métodos de ordenação")
lines(caixas$X1,caixas$X2, col="royalblue", lwd = 2)
lines(merge$X1,merge$X2, col="green", lwd = 2)
lines(insertion$X1,insertion$X2, col="purple", lwd = 2)
legend(locator(1), xpd=TRUE, ncol=4,
     legend=c("Bolha", "Insertion", "Caixas","Merge"),
     fill=c("red", "purple","green", "royalblue"), bty="n")


