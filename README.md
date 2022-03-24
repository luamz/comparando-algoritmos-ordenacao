# Comparando Algortimos de Ordenação
Desenvolvida por Luam Souza e Victoria Granja

Aplicação desenvolvida em C para cálculo e comparação dos tempos de processamento dos seguintes métodos de ordenação: Bolha, Caixas, Insertion e Merge.

Para executar configure no arquivo ```main.c``` o número máximo de N (números a serem ordenados), o passo com que esse número será incrementado e a semente com que os números aleatórios serão gerados.

Para a comparação do método das caixas de acordo com o tamanho de B, execute o arquivo ```comp_caixas.c```, informando as sementes desejadas para a comparação.

Os arquivos .txt resultantes das execuções são armazenados na pasta resultados, as sequências são escritas na pasta sequências conforme o programa roda, os métodos de ordenação estão na pasta metodos e no arquivo ```util.c``` estão algumas funções auxiliares.

Para as sequências aleatórias foi criada a função gera_sequencias, que utiliza a seed de um método que retorna o tempo passado e dividi-se ele com o resto de um valor especifícado. De maneira a conseguir gerar números aleatórios sem algum padrão.

Para gerar os gráficos foi utilizada a linguagem R com a biblioteca readr, o arquivo ```Gráfico.R``` gera gráficos comparando todos os métodos, o arquivo ```GráficosIndividuais.R``` é usado para gráficos individuais dos métodos, e o ```GráficoCompCaixas.R``` para a comparação do método das caixas segundo b.

### Alguns dos Gráficos Gerados
 <img src="https://user-images.githubusercontent.com/50959073/160017957-d53c7377-25e5-46c1-a6dd-3a58972e8e6b.png" width="500"> <img src="https://user-images.githubusercontent.com/50959073/160018255-4fa12538-d6f1-4594-8972-100f3803ee3b.png" width="500">
<img src="https://user-images.githubusercontent.com/50959073/160018309-94451480-3b53-4631-87e1-b083f7db2bc7.png" width="500"> <img src="https://user-images.githubusercontent.com/50959073/160018429-fbbf314a-2105-4ef7-a463-31d0dc856103.png" width="500">
<img src="https://user-images.githubusercontent.com/50959073/160018610-62b97be8-042b-44ea-9610-736d0703dbc7.png" width="500"> <img src="https://user-images.githubusercontent.com/50959073/160018625-2b96ce01-375a-4da0-9f96-782dc7c23217.png" width="500">
<p align="center">
  <img  align="center" src="https://user-images.githubusercontent.com/50959073/160018710-8b099b7a-55b8-4352-a749-8c72c246802a.png" width="500"> 
</p>
