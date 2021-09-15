#include <SoftwareSerial.h> 
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    mySerial.begin(9600);

}

void loop() {
  while (Serial.available()){
    String receivedData = Serial.readString();
    mySerial.println(receivedData);
    Serial.println(receivedData);
    
    if (receivedData=="hey" || receivedData=="hey\r" || receivedData== "hey\r\n"){
      Serial.println("bye");
      }
    }
}
