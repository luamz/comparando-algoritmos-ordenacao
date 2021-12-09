plot(bolha$X1, bolha$X2,type="l",,
     xlab="N", ylab="Tempo de Processamento",col="red", lwd = 2,
     main = "Comparação dos métodos de ordenação")
lines(caixas$X1,caixas$X2, col="royalblue", lwd = 2)
lines(merge$X1,merge$X2, col="green", lwd = 2)
lines(insertion$X1,insertion$X2, col="purple", lwd = 2)
legend(locator(1), xpd=TRUE, ncol=4, legend=c("Bolha", "Caixas","Merge", "Insertion"),
       fill=c("red", "royalblue","green", "purple"), bty="n")

