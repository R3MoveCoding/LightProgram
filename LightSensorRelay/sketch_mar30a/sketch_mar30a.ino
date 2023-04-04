#include <BH1750.h>
#include<Wire.h>
BH1750 lightMeter;
int Relay1 = 2;
int Relay2 = 3;
int lux = 0;

void setup() {
    Serial.begin(9600); //Starting serialComunation
  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
  //End initialize

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);
  

  
}
void loop() {
   float lux = lightMeter.readLightLevel();// reading the lux from sensor
  if (lux > 1000) {
    digitalWrite(Relay1, LOW);
    digitalWrite(Relay2, LOW);
  }
  while(lux<1000){
    
  if (lux < 700 && lux > 500){
    delay(200000);
    digitalWrite(Relay1,HIGH);
  }
    if (lux <400 && lux > 200){
      delay(60000);
      digitalWrite(Relay2,HIGH);
    if (Relay2 == HIGH){
      delay(400000);
    digitalWrite(Relay1, HIGH);
    }
   if(lux == 100){
    delay(60000);
    digitalWrite(Relay2,LOW);
   }
    }  
  }

}
