#define LEDPin 13
#define LDRPin A0

int LDRVoltage_dark = 4.1;

void setup() {
  // put your setup code here, to run once:
  pinMode (LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float LDRVoltage = analogRead(LDRPin) / 1024.0 * 5.0;
  if (LDRVoltage > LDRVoltage_dark){
    digitalWrite(LEDPin, HIGH);
    }
  else{
    digitalWrite(LEDPin, LOW);
    }
  

}
