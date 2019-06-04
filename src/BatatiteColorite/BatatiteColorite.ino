#include "Movimentacao.h"
#include "Configuracao.h"
#include "Encoder.h"
#include <LiquidCrystal.h>
#include "Arduino.h"

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

/*
  TestePH2();*/
  long int now = millis();

  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  while(millis()-now <15000)
  {
    setSpeedWithHisteresis(3, 30);
    delay(5);
  }
  

} 

void testeDeControle( )
{
  controladorMotorDireita.Tunning(0.5, 0, 20);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  long int now = millis();

  int rightSpeed = 5;

  while(millis() - now < 8000){
  ////////////////////////////////////////////////////////////////////// int erroEsquerda = leftSpeed - encoderMotorDireita.RetornaRPM(); 
    double vel = encoderMotorDireita.RetornaRPM() ;
    double erroDireita = rightSpeed - vel;
  ////////////////////////////////////////////////////////////////////// int leftVelocityOutput  = controladorMotorEsquerda.LeiDeControle(erroEsquerda);
    int rightVelocityOutput = controladorMotorDireita.LeiDeControle(erroDireita);
    if (rightVelocityOutput > 0){
      rightVelocityOutput = -1 * rightVelocityOutput;
      RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
    }
    rightVelocityOutput = rightVelocityConstrainting(rightVelocityOutput);
  ////////////////////////////////////////////////////////////////////// LEFT_MOTOR->setSpeed(leftVelocityConstrainting(leftVelocityOutput));
    RIGHT_MOTOR->setSpeed(rightVelocityOutput);
    lcd.setCursor(0, 0);
    lcd.print(String(vel)+ "   " +String(rightVelocityOutput));
    lcd.setCursor(0, 1);
    lcd.print(erroDireita);
    delay(300);
  }
  para();
}

void controlaRPM(double rightSpeed, double leftSpeed){

  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  //long int now = millis();
  
  //while(millis() - now < 400){
    double velDir = encoderMotorDireita.RetornaRPM() ;
    double velEsq = encoderMotorEsquerda.RetornaRPM() ;
    double erroDireita = rightSpeed - velDir;
    double erroEsquerda = leftSpeed - velEsq;
    float Kp = 4;
    Serial.println(leftSpeed); 
    Serial.print("leftSpeed");
    Serial.println(velEsq); 
    Serial.print("velocity antes eh");
    Serial.println(leftVelocityOutput);
    Serial.print("o erro eh");
    Serial.println(erroEsquerda);
    rightVelocityOutput = rightVelocityOutput +(erroDireita* Kp);

    leftVelocityOutput =  leftVelocityOutput + (erroEsquerda* Kp);
    
    /*
    if (erroDireita > 0.0){
      if(erroDireita > rightSpeed*0.1){
        rightVelocityOutput=rightVelocityOutput+10;
      }
      rightVelocityOutput=rightVelocityOutput+(erroDireita* Kp);
    } else {
  
      if(erroDireita*(-1) > rightSpeed*0.1){
        rightVelocityOutput=rightVelocityOutput-10;
      }
      rightVelocityOutput=rightVelocityOutput+(erroDireita* Kp);
    }

    if (erroEsquerda > 0.0){
      if(erroEsquerda > leftSpeed*0.1){
        leftVelocityOutput=leftVelocityOutput+10;
      }
      leftVelocityOutput=leftVelocityOutput+(erroEsquerda* Kp);
    } else {
      if(erroEsquerda*(-1) > leftSpeed*0.1){
        leftVelocityOutput=leftVelocityOutput-10;
      }
      leftVelocityOutput=leftVelocityOutput+(erroEsquerda* Kp);
    }
    */
    Serial.print("velocity eh");
    Serial.println(leftVelocityOutput);
    RIGHT_MOTOR->setSpeed(rightVelocityOutput);
    LEFT_MOTOR->setSpeed(leftVelocityOutput);
   
 // }
  delay(500);
}

void TestePH2(){

  int blwhEsq = analogRead(12);
  int blwhDir = analogRead(13);
  
  para();
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  LEFT_MOTOR->run(LEFT_MOTOR_BACKWARD);
  
  long int now = millis();


  int limite = 400;
  double velGeral = 3;

  while(millis() - now < 15000){
    int blwhEsq = analogRead(12);
    int blwhDir = analogRead(13);

    if (blwhEsq < limite && blwhDir < limite){
      controlaRPM(velGeral, velGeral);
    }else if(blwhEsq > limite && blwhDir < limite){
      controlaRPM(velGeral,velGeral*0.7);
    }else if(blwhEsq < limite && blwhDir > limite){
      controlaRPM(velGeral*0.7 ,velGeral);
    }else{
      controlaRPM(velGeral,-velGeral);   
  }
    lcd.setCursor(0, 0);
  
  lcd.setCursor(0, 0);
  lcd.print("       ");
  lcd.setCursor(0, 0);
  lcd.print(blwhEsq);
  lcd.setCursor(0, 1);
  lcd.print("       ");
  lcd.setCursor(0, 1);
  lcd.print(blwhDir);
  delay(10);
  }
  
  lcd.setCursor(5, 0);
  lcd.print("ACABOU");
  para();
  
}

void loop()
{
  
}
