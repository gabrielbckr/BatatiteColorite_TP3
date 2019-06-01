#include "Encoder.h"
#include "Configuracao.h"
#include "Arduino.h"

float Encoder::RetornaRPM()
{
	double tempoAtual = millis();
	double deltaTempo  = float(tempoAtual - this->TempoDesdeUltimoConsumo); 
	float  deltaRotacoes = this->CalculoVoltas(this->Voltas - this->VoltasDuranteUltimoConsumo);
	this->VoltasDuranteUltimoConsumo = this->Voltas;
	return deltaRotacoes*60000.0/deltaTempo; 
}

float Encoder::CalculoVoltas(int v)
{
	return v/NUMERO_DE_INTERRUPCOES_POR_VOLTA;
}

Encoder::Encoder(int pino):Pino(pino)
{
	TempoDesdeUltimoConsumo = millis();
}