#ifndef __COLORFUL_MOVIMENTACAO__
#define __COLORFUL_MOVIMENTACAO__

#include "Configuracao.h"


void SETUP_MOVIMENTACAO();

void para();

void anda(int d);

void gira_sentido_horario(double t);

void anda_re(int d);

void gira_sentido_antihorario(double t);

void set_speed(int left_speed , int right_speed);

void set_speed();

#endif 
