#include "DHT.h"

#define DHTTYPE DHT11   
#define DHTPIN 9  
DHT dht(DHTPIN, DHTTYPE);

#define enA  6
#define in1  5
#define in2 4

int t1 = 0;

float temperature = 0;
float humidity = 0;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  Serial.begin(9600);

  dht.begin();
}

void loop() {

  //delay(1000);
  
  if ((millis() - t1) > 1000){
    humidity = dht.readHumidity();
    // Read temperature as Celsius (the default)
    temperature = dht.readTemperature();
    Serial.println(temperature);
    t1 = millis();
  }

  if (temperature > 30 && temperature < 35){
    analogWrite(enA, 50);
  }
  else if (temperature >= 35){
    analogWrite(enA, 150);    
    }
  else{
    analogWrite(enA,0);
    }
}
