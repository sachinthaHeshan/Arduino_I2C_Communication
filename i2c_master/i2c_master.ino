// I2C Master
#include <Wire.h>

int x = 100;
int y = 300;

void setup() {
  Wire.begin(); 
}

void loop() {

  sendData('Y', y);
  delay(1000);

  sendData('X', x);
  delay(1000);
   
  x += 100;
  if(x > 1000) x = 0;

  y += 200;
  if(y > 1000) y = 0;
}


void sendData(char type, int value) {
  String message = String(type) + String(value);

  int length = message.length() + 1;
  char charArray[length];
  message.toCharArray(charArray, length);
  
  Wire.beginTransmission(9);
  Wire.write(charArray);
  Wire.endTransmission();
}
