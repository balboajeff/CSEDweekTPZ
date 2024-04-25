#include <Arduino.h>
#include <Wire.h>
#include <ArtronShop_BH1750.h>

ArtronShop_BH1750 bh1750(0x23, &Wire); // Non Jump ADDR: 0x23, Jump ADDR: 0x5C
int lightVal[3];
 char key;
void setup() {
  Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
  Wire.begin();
  while (!bh1750.begin()) {
    Serial.println("BH1750 not found !");
    delay(1000);
  }
}

void loop() {
  if (Serial.available()>0)
  {
 key=Serial.read();
 if (key=='a')
 {
  
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
lightVal[0]= bh1750.light();

digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
lightVal[1]= bh1750.light();

digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
lightVal[2]= bh1750.light();

Serial.print(lightVal[0]);
Serial.print(", ");
Serial.print(lightVal[1]);
Serial.print(", ");
Serial.print(lightVal[2]);
Serial.print(", ");
Serial.print(analogRead(A0));
Serial.print(", ");
Serial.print(analogRead(A1));
Serial.print(", ");
Serial.println(analogRead(A2));
}
}
}
