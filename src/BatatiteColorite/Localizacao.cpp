#include "Localizacao.h"
#include "Arduino.h"
#include "Movimentacao.h"
#include "Configuracao.h"

#define LIMIAR_DE_MODULARIZAO 500

Localizacao::Localizacao(int pino)
{
    this->Pino = pino;
    for (int i = 0; i < this->numReadings; i++) {
        this->readings[i] = 0;
    }
}

int Localizacao::RetornaSinal()
{
    this->total = this->total - readings[this->readIndex];
    int sig =  analogRead(this->Pino) - LIMIAR_DE_MODULARIZAO;
    sig = (sig <= 0) ? -sig:sig;
    this->readings[this->readIndex] = sig;
    this->total = this->total + this->readings[this->readIndex];
    this->readIndex++;  
    if (this->readIndex >= this->numReadings) {
        this->readIndex = 0;
    }
    return this->total / this->numReadings;
}


bool Localizacao::EstaAlinhado()
{
    int sinalAnterior = 0 ;
    if (this->readIndex == 0)
    {
        sinalAnterior = readings[19];
    } 
    else
    {
        sinalAnterior = readings[this->readIndex -1];
    }
    
    if( RetornaSinal() < sinalAnterior)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
