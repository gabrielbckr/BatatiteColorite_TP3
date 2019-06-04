#include "Movimentacao.h"
#include "Configuracao.h"
#include "SeguidorDeLinha.h"
#include "Localizacao.h"
#include "Tarefas.h"


void Tarefas::AlinhaComLampada(){}

void Tarefas::PercorreLinha(){}

void Tarefas::PercorreQuadrado(){}

void Tarefas::PercorreTriangulo(){}

void Tarefas::ExploraAmbiente(){
  SeguidorDeLinha::Seguir(analogRead(LEFT_LINE_SENSOR_PIN), analogRead(RIGHT_LINE_SENSOR_PIN));

}

void Tarefas::ProcuraMaximo()
{
  Localizacao localizacao(DIFERENTIAL_SENSOR_PIN);
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  while(true){
    // controla velocidade
    if (localizacao.EstaAlinhado())
    {
      return;
    }
  }
}