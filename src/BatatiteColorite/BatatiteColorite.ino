#include "Movimentacao.h"
#include "Configuracao.h"
#include "Encoder.h"

Encoder primeiroEncoder = new Encoder(21);


void func()
{
  primeiroEncoder.IncrementaVoltas();
}


void setup(){
  
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(21), func , RISING );
}

void loop(){
  
  Serial.print("Ola, o valor atual ");
  Serial.println( primeiroEncoder.RetornaVolta() );
  delay(2000);
}


