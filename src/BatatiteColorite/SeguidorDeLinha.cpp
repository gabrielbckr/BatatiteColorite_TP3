#include "SeguidorDeLinha.h"
#include "Movimentacao.h"

using namespace SeguidorDeLinha;

void Seguir (int esquerda, int direita){

	anda();
	if(esquerda > LIMIAR_LINHA && direita > LIMIAR_LINHA){

		setControledRPMSpeed(LEFT_RPM, RIGHT_RPM); //SE OS DOIS ESTIVEREM DENTRO DA LINHA, O ROBO ANDARÁ PARA FRENTE

	}else if(esquerda < LIMIAR_LINHA && direita > LIMIAR_LINHA){ // SE O LADO ESQUERDO ESTIVER FORA, O ROBO FARÁ UMA CURVA PARA DIREITA

		setControledRPMSpeed(LEFT_RPM, RIGHT_RPM*TURNING_FACTOR);

	}else if (esquerda > LIMIAR_LINHA && direita < LIMIAR_LINHA){ //ANALOGO AO ANTERIOR, 

		setControledRPMSpeed(LEFT_RPM*TURNING_FACTOR, RIGHT_RPM);

	}else { //SE OS 2 LADOS ESTIVEREM FORA DA LINHA O ROBO GIRA NO PRÓPRIO EIXO PROCURANDO UMA LINHA

		setControledRPMSpeed(LEFT_RPM, -RIGHT_RPM);

	}


}