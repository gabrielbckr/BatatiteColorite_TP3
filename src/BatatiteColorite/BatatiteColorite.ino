#include "Movimentacao.h"
#include "Configuracao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>
#include "Arduino.h"
#include "Tarefas.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int cont = 0;
double rightVelocityOutput=0;
double leftVelocityOutput=0;

void rightMotorInterruptHandler()
{
  encoderMotorDireita.IncrementaVoltas();
}

void leftMotorInterruptHandler()
{
  encoderMotorEsquerda.IncrementaVoltas();
}

void setup(){
  
  lcd.begin(16, 2);  
  /**/

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
  SETUP_MOVIMENTACAO();
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT__VOLT_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_LEFT__VOLT_SPEED);

  Tarefas::ExploraAmbiente();
  //Tarefas::ProcuraMaximo();
} 

void loop()
{
}
