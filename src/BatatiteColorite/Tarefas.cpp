#include "Movimentacao.h"
#include "Configuracao.h"
#include "SeguidorDeLinha.h"
#include "Localizacao.h"
#include "Tarefas.h"


void Tarefas::AlinhaComLampada(){}

void Tarefas::PercorreLinha(){}

void Tarefas::PercorreQuadrado(){}

void Tarefas::PercorreTriangulo(){}

void Tarefas::ExploraAmbiente(){}
	


void Tarefas::ProcuraMaximo(Localizacao L)
{
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  while(true){
    // controla velocidade
    if (L.EstaAlinhado())
    {
      return;
    }
  }
}