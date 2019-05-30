#ifndef __ENCODER__TP__ROBOTICA__
#define __ENCODER__TP__ROBOTICA__


class Encoder
{
	public:

	int const Pino;
	int Voltas = 0;

	Encoder(const int p){ Pino = p; }

	void IncrementaVoltas() { Voltas++; }

	void operator++() { Voltas++; } 

	float RetornaRPM();

	void  ZeraVoltas();
};


#endif
