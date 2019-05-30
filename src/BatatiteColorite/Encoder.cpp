#include "Encoder.h"


int  Encoder::RetornaVoltas()
{
	int voltasTemp = this->Voltas;
	this->Voltas = 0;
	return voltasTemp;
}
