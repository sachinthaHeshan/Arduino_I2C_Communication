// I2C Slave  
#include <Wire.h> 

void setup() {
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}


void loop() {

}


void clearBuffer(char* buffer, int length) {
  for (int i = 0; i < length; i++) {
    buffer[i] = '\0';
  }
}


void receiveEvent(int howMany) {
  char receivedData[32];  // Buffer to store the received message 
  clearBuffer(receivedData, sizeof(receivedData));
  
  int i = 0; 

  while (Wire.available() && i < sizeof(receivedData) - 1) {
    receivedData[i++] = Wire.read();
  } 

  String data = String(receivedData); 
  char type = data[0];
  String value = data.substring(1); 
 
 

  if (type == 'X') {
    Serial.print(type);
    Serial.print(" - ");
    Serial.println(value.toInt()); 
  }else if(type == 'Y') {
    Serial.print(type);
    Serial.print(" * ");
    Serial.println(value.toInt()); 
  }

}

