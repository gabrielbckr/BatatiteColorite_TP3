#ifndef __COLORFUL_MOVIMENTACAO__
#define __COLORFUL_MOVIMENTACAO__


#include "Encoder.h"
#include "Configuracao.h"

Encoder encoderMotorEsquerda(LEFT_ENCODER_PIN);
Encoder encoderMotorDireita(RIGHT_ENCODER_PIN);



void SETUP_MOVIMENTACAO();

void para();

void andaComDelay(int d);

void anda();

void andaReComDelay();

void gira_sentido_horario(double t);

void anda_re(int d);

void gira_sentido_antihorario(double t);

void set_speed(int left_speed , int right_speed);

void set_speed();

void vira_esquerda(int d, int a); 

void vira_direita(int d, int a);

void setControledRPMSpeed(int , int);

#endif 
