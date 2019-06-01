// tet
#include "Movimentacao.h"
#include "Configuracao.h"
#include <Adafruit_MotorShield.h>
#include "Controlador.h" 
#include "Arduino.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LEFT_MOTOR = AFMS.getMotor(LEFT_MOTOR_INPUT);
Adafruit_DCMotor *RIGHT_MOTOR = AFMS.getMotor(RIGHT_MOTOR_INPUT);  
Controlador controladorMotorDireita(1);  
Controlador controladorMotorEsquerda(1); 
// Encoder encoderMotorEsquerda(LEFT_ENCODER_PIN);
// Encoder encoderMotorDireita(RIGHT_ENCODER_PIN);

void rightMotorInterruptHandler()
{
  encoderMotorEsquerda.IncrementaVoltas();
}

void leftMotorInterruptHandler()
{
  encoderMotorDireita.IncrementaVoltas();
}

void SETUP_MOVIMENTACAO(){
  AFMS.begin();
  set_speed();
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
}


void para(){
  LEFT_MOTOR->run(RELEASE);
  RIGHT_MOTOR->run(RELEASE);
  delay(100);
}

void anda(int d)
{
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD );
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
}

void andaComDelay(int d)
{
  double tempoInicio = millis();
  anda();
  while(millis() - tempoInicio < d);
}

void andaReComDelay()
{
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
}

void andaReComDelay(int d){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  d=d*TEMPO_ANDA;
  delay(d);
  para();
}

void gira_sentido_horario(double t){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  t=t*TEMPO_GIRA;
  delay(t);
  para();
}

void gira_sentido_antihorario(double t){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  t=t*TEMPO_GIRA;
  delay(t);
  para();
}

void set_speed(){
  set_speed(DEFAULT_LEFT_SPEED, DEFAULT_RIGHT_SPEED );
}

void set_speed(int left_speed, int right_speed ){
  LEFT_MOTOR->setSpeed(left_speed);
  RIGHT_MOTOR->setSpeed(right_speed);
}

void vira_esquerda(int d, int a){
  para();
  set_speed(DEFAULT_LEFT_SPEED*a,DEFAULT_RIGHT_SPEED);
  anda(d);
  set_speed(DEFAULT_LEFT_SPEED,DEFAULT_RIGHT_SPEED);

}

void vira_direita(int d, int a){
  para();
  set_speed(DEFAULT_LEFT_SPEED,DEFAULT_RIGHT_SPEED*a);
  anda(d);
  set_speed(DEFAULT_LEFT_SPEED,DEFAULT_RIGHT_SPEED);

}

void setControledRPMSpeed(int leftSpeed, int rightSpeed )
{

  int erroEsquerda = leftSpeed - encoderMotorDireita.RetornaRPM(); 
  int erroDireita = rightSpeed - encoderMotorDireita.RetornaRPM() ;
  int leftVelocityOutput  = controladorMotorEsquerda.LeiDeControle(erroEsquerda);
  int rightVelocityOutput = controladorMotorDireita.LeiDeControle(erroDireita);
  LEFT_MOTOR->setSpeed(leftVelocityOutput);
  RIGHT_MOTOR->setSpeed(rightVelocityOutput);
}

