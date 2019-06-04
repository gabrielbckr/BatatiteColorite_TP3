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

int state = 0;

int read_LCD_buttons() {
  int adc_key_in = analogRead(0);      // read the value from the sensor
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;

  return btnNONE;  // when all others fail, return this...
}

//unsigned long tempoAntes = 0;

void task(){
  Tarefas::ExploraAmbiente();
  delay(10);
}

void setup(){
  
  lcd.begin(16, 2);  
  /**/

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftMotorInterruptHandler , RISING );
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightMotorInterruptHandler , RISING );
  SETUP_MOVIMENTACAO();
  LEFT_MOTOR->setSpeed(DEFAULT_LEFT_PWM_SPEED);
  RIGHT_MOTOR->setSpeed(DEFAULT_RIGHT_PWM_SPEED);

  //Tarefas::ExploraAmbiente();
  //Tarefas::ProcuraMaximo();
  //tempoAntes = millis();
} 

void loop()
{
  int button = read_LCD_buttons();
  if (button == btnRIGHT || button == btnUP)
  {
    state = 0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Parado");
    delay(200);
    para();
  } else if (button == btnLEFT || button == btnDOWN)
  {
    state = 1;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Rodando");
    delay(200);
    anda(0);
    Tarefas::ProcuraMaximo();
  }
  if (state){
    task();
  }
}
