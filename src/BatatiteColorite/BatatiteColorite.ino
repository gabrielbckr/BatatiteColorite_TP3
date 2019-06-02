#include "Movimentacao.h"
#include "Configuracao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int cont = 0;

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
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_SPEED);
  task();
} 

void task(){
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(15000);
  para();
  // Serial.print( "VoltasEsquerda = " + String(encoderMotorEsquerda.RetornaVolta()) + "\t");
  // Serial.println( "VoltasDireita = "  + String(encoderMotorDireita.RetornaVolta()) + "\t");
  lcd.setCursor(0,1);
  lcd.print(String(encoderMotorEsquerda.RetornaVolta()) + " "+  String(encoderMotorDireita.RetornaVolta()));
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}


void loop()
{

}