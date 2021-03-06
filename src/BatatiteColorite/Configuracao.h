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
#define DEFAULT_LEFT__VOLT_SPEED 148
#define DEFAULT_RIGHT_VOLT_SPEED 152
#define DEFAULT_LEFT_LINEAR_SPEED 1
#define DEFAULT_RIGHT_LINEAR_SPEED 1
#define DEFAULT_LEFT_ANGULAR_SPEED 3
#define DEFAULT_RIGHT_ANGULAR_SPEED 3
#define DEFAULT_LEFT_RPM_SPEED 3
#define DEFAULT_RIGHT_RPM_SPEED 3
#define MIN_RIGHT_VELOCITY 0
#define MIN_LEFT_VELOCITY 0

/* ENCODER */ 
#define NUMERO_DE_INTERRUPCOES_POR_VOLTA 6
#define LEFT_ENCODER_PIN 18
#define RIGHT_ENCODER_PIN 19

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

// CONSTANTES DE SEGUIDOR DE LINHA
#define LEFT_RPM 10 // ESSE VALOR NÃO FOI TESTADO, PROVAVELMENTE PRECISARÁ SER MODIFICADO
#define RIGHT_RPM 10 // ESSE VALOR NÃO FOI TESTADO, PROVAVELMENTE PRECISARÁ SER MODIFICADO
#define TURNING_FACTOR 0.5 // COEFICIENTE DE REDUÇÃO DE VELOCIDADE PARA A REALIZAÇÃO DA CURVA - VALOR TBM NÃO TESTADO
#define LIMIAR_LINHA 400 // LIMIAR DE INTENSIDADE LUMINOSA DO IR QUANDO ESTA MRIANDO NA FOLHA DE PAPEL




#endif 
