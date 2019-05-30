#ifndef __COLORFUL_CONFIGURACAO__
#define __COLORFUL_CONFIGURACAO__


#include "Arduino.h"
//Se acontecer problema de redefinicao, mudar A8

/*      LED E LDR    */
// Pinos dos LEDs
const int RED_PIN   = 23; // Fio vermelho
const int GREEN_PIN = 25; // Fio azul
const int BLUE_PIN  = 27; // Fio laranja; Fio marrom é o terra
// Pino do LDR
const int LDR_PIN = A8; // VCC=vermelho, GND=marrom, SIG(A8)=amarelo
		
/*      LUZ E LUMINOSA   */		
const int THRESHOLD_OBSTACULO_DE_LUZ = 150;

/*      CORES        */
const char yellow = 'C';
const char black = 'D';
const char blue  = 'B';
const char red    = 'R';
const char green = 'G';

/*      MOTORES    */
const int LEFT_MOTOR_INPUT = 1;
const int RIGHT_MOTOR_INPUT = 2;
#define LEFT_MOTOR_FORWARD FORWARD
#define LEFT_MOTOR_BACKWARD BACKWARD
#define RIGHT_MOTOR_FORWARD  BACKWARD
#define RIGHT_MOTOR_BACKWARD FORWARD

/*       VELOCIDADES     */
#define DEFAULT_LEFT_SPEED 148
#define DEFAULT_RIGHT_SPEED 150

/*     BOTOES LCD      */
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
#define btnDELAY 200

// CONSTANTES DE TOMADA

// CONSTANTES DE PILHA
#define TEMPO_ANDA 91
#define TEMPO_GIRA 195


#endif 
