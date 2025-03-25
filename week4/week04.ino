#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define Trig 13
#define Echo 12


LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600);  //초당9600비트를 전송
  pinMode(Trig, OUTPUT);//13번 핀을 아웃풋
  pinMode(Echo, INPUT); //12번 핀을 인풋
  
  lcd.init();
  lcd.backlight();
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{
  long duration,distance;
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duration = pulseIn(Echo, HIGH);
  
  distance = duration/58.2;
    
  delay(10);
  
  lcd.setCursor(0,0);//
  lcd.print(distance);
  lcd.print("cm");
  delay(500);
  lcd.clear();
}