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
  
  long int tempo = millis(); 
  digitalWrite(LED_BUILTIN, HIGH);
  while(encoderMotorEsquerda.RetornaVolta()<=100){
    lcd.setCursor(0,0);
    lcd.print(String(encoderMotorEsquerda.RetornaVolta())+ " "+ String(encoderMotorDireita.RetornaVolta())
     + "    " + String((millis()-tempo)/1000.0) + "s"
    );
    lcd.setCursor(0,1);
    lcd.print(String(encoderMotorEsquerda.RetornaRPM())+ " "+ String(encoderMotorDireita.RetornaRPM()));
    delay(200);
  }
  lcd.setCursor(0,0);
  lcd.print(String(encoderMotorEsquerda.RetornaVolta())+ " "+ String(encoderMotorDireita.RetornaVolta()));
  lcd.setCursor(0,1);
  lcd.print(String(encoderMotorEsquerda.RetornaRPM())+ " "+ String(encoderMotorDireita.RetornaRPM()));
  para();
}

// void ControlTunning()
// {
//   controladorMotorEsquerda.Tunning(2, 0.5);
//   lcd.setCursor(0,0);
//   lcd.print(String()+" "+String()+" "+String());

//   unsigned long now = millis();
//   while(now - millis() < 3000){ 
//     double erro = velocidade - encoderMotorEsquerda.RetornaRPM();
//     LEFT_MOTOR->setSpeed( controladorMotorEsquerda.LeiDeControle(erro) );
//     lcd.setCursor(0,0);  
//     lcd.print(String()+" "+String()+" "+String());
//     delay(1);
//   }
// }

void loop()
{

}