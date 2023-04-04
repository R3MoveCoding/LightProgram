#include <BH1750.h>
#include<Wire.h>
BH1750 lightMeter;

int relay1 = 2;
int relay2 = 3;
int lightValue = 0;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop() {
     float lightValue = lightMeter.readLightLevel();// reading the lux from sensor
  // If lux +1000 turn on relay1&2
  if (lightValue > 2000) {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
  }

  // If lux drops
  if (lightValue < 2000) {

    // if lux drops 20-40% from 1000lux for more than 60seconds turn off led2
    if (lightValue < 800 && lightValue > 600) {
      delay(60000);
        digitalWrite(relay2, HIGH);
      
    }

    // If led2 off for more than 400seconds turn off led1 program restart
    if (digitalRead(relay2) == HIGH) {
      delay(400000);
      if (digitalRead(relay2) == HIGH) {
        digitalWrite(relay1, HIGH);

        // Restart program
        setup();
      }
    }

    // If lux drops 50-70% from 1000lux for more than 200seconds turn off led1
    if (lightValue < 600 && lightValue > 300) {
      delay(200000);
      if (lightValue < 300) {
        digitalWrite(relay1, HIGH);
      }
    }

    // When lux increases to 10% from 1000lux for more than 60seconds turn on led2
    if (lightValue > 1200 && lightValue < 1400) {
      delay(60000);
      if (lightValue > 1400) {
        digitalWrite(relay2, LOW);
      }
    }

  }

}
