#include "Movimentacao.h"
#include "Configuracao.h"


void setup(){
  
  Serial.begin(115200);
  SETUP_MOVIMENTACAO();
 // Tunning(1,0,0);
}

void loop(){
  // TESTE CONTROLADOR
  //double entrada = 1;
  //double saida;

  //erro = entrada - saida;
  //LeiDeControle(erro);

  //Serial.println( analogRead(12));
  int  botao = digitalRead(btnRIGHT);
  
  if(botao){
    vira_esquerda(100,1)  ;
  }
  

  
}
