library(readr)
caixas1 <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/comp_caixas/caixas1.txt", col_names = FALSE)
caixas2 <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/comp_caixas/caixas2.txt", col_names = FALSE)
caixas3 <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/comp_caixas/caixas3.txt", col_names = FALSE)
caixas4 <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/comp_caixas/caixas4.txt", col_names = FALSE)
caixas5 <- read_csv("~/Documentos/Análise e Projeto de Algoritmos/resultados/comp_caixas/caixas5.txt", col_names = FALSE)


plot(caixas1$X1, caixas1$X2,type="l", xlab="N", ylab="Tempo de Processamento", 
     col="red", lwd = 2, main = "Comparação do Método de Caixas",
     sub = "Levando em conta o valor de b", ylim=c(0,0.1))
lines(caixas2$X1,caixas2$X2, col="royalblue", lwd = 2)
lines(caixas3$X1,caixas3$X2, col="green", lwd = 2)
lines(caixas4$X1,caixas4$X2, col="purple", lwd = 2)
lines(caixas5$X1,caixas5$X2, col="orange", lwd = 2)
legend(locator(1), xpd=TRUE, ncol=5,
       legend=c("1.000", "10.000", "50.000","100.000", "1.000.000"),
       fill=c("red", "purple","green", "royalblue","orange"), bty="n")

