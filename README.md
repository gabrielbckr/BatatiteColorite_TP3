# BatatiteColorite_TP3
Robô coletor de blocos e perseguidor de linha feito com Arduino e Lego
Projeto Final
## Introdução
O trabalho do projeto final teve o objetivo de aprimorar e corrigir problemas no robô com base no Trabalho Prático 3, de forma que ele fosse capaz de executar as seguintes tarefas na Competição de Robôs:

Ser capaz de ser calibrado em 60 segundos ou menos;
Entrar em modo de espera após a calibração;
Não queimar a largada;
Iniciar o cumprimento da tarefa após acesa a luz de início;
Ser capaz de se orientar segundo a luz polarizada;
Navegar autonomamente pelo campo;
Coletar os blocos/esferas que se encontram dispersos no campo;
Carregar o bloco/esfera até a base (ou mantê-lo preso ao robô);
Desligar todos os atuadores ao término de 60 segundos.
O robô foi capaz de executar todas as tarefas propostas.

O objetivo era ser capaz de participar da competição, com o desenho de campo abaixo:



Construímos o robô com a estratégia de pegar blocos não pretos e levar para a base.

Estrutura física
Houve mudanças significativas na estrutura física para acomodar melhor o kit Arduino dentro do robô, pois a estrutura anterior se demonstrava frágil nesse quesito. Fizemos uma montagem ao redor das rodas para ajudar na sustentação e proteção lateral robô.



Uma estrutura estática em forma de “U” foi construída para que fosse possível captar os blocos espalhados na mesa da competição. Além disso, nas corridas de teste que fizemos, notamos que blocos se encaixavam nas laterais do robô e eram arrastados de forma não intencional, então tivemos que montar estruturas dos dois lados para evitar esse problema.

![foto](https://homepages.dcc.ufmg.br/~doug/cursos/lib/exe/fetch.php?w=600&tok=ba1bf5&media=cursos:introrobotica:2019-1:grupo06:finalrobo1.jpeg)
![foto](https://homepages.dcc.ufmg.br/~doug/cursos/lib/exe/fetch.php?w=600&tok=7e2c19&media=cursos:introrobotica:2019-1:grupo06:finalrobo2.jpeg)
## Estratégia
A estratégia do robô consistia de uma máquina de estados, com a seguinte lógica de operação :

Esperar a luz de partida
Se localizar, girando em 360 graus a procura da luz polarizada
Girar em direção à luz polarizada
Girar 180 graus, se posicionando para andar em direção aos blocos.
Andar reto por um período de tempo, fazendo com que o robô ignore a primeira linha preta a sua frente. O objetivo aqui é ganhar tempo, visto que seguir todas as linhas tomaria muito tempo.
Ativar o seguidor de linha e a detecção de objetos.
Caso encontre um bloco preto, o robô realizará uma curva para direita, desviando do bloco, e em seguida retornará para a linha.
Caso encontre um bloco não preto, o robô:
Procura a luz polarizada
Gira em sua direção.
Anda por um período de tempo(levando o bloco até a base).
Recua (deixando teoricamente o bloco na base).
Gira em 180 graus
Anda pra frente (na teoria evitando novamente seguir a linha preta próxima ao local de partida).
Ativa o seguidor de linhas e a detecção de blocos para procurar um segundo objeto, retornando ao estado 6.
Algoritmo
Máquina de Estados
Como citado na sessão anterior, a máquina de estados era a base da lógica do robô. Ela possuía uma função principal, que chamava as funções de cada estados, por meio de um switch case. Dentro de cada estado são realizadas as lógicas e chamadas funções referentes a ações mais complexas.
##  Desafios
Os maiores desafios nesse ponto foram fazer o robô detectar com precisão os blocos e ajustar os giros quando ele estava se localizando, saindo da base e seguindo a linha. Na detecção de blocos, o bloco preto foi um desafio a parte, pois sua cor dificulta a detecção. Esta detecção falhou na competição. Tivemos problemas com os giros também devido à falha em cima da hora da apresentação de nossos encoders e a consequente necessidade de adaptar algumas funções para executarem com base em tempo e não mais na medição das rotações das rodas.
