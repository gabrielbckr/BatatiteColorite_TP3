#include "Encoder.h"


float Encoder::RetornaRPM()
{
	int voltasTemp = this->Voltas;
	return this->CalculoRPMdeVoltas(voltasTemp);
}

float Encoder::CalculoRPMdeVoltas(int v)
{
	return 0.0;
}