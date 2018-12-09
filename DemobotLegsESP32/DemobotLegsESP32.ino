//ESP32 PICO Kit dev board

#include <Arduino.h>
#include "DancingServos.h"

/* Current Pins
 * hip  L: 14
 * hip R: 13
 * ankle L: 12
 * ankle R: 15
 */


void oscillatorTest();
void dancingServosTest();
void servoTest();
void calibrateTrims(DancingServos* bot);

DancingServos* bot;
Oscillator osc;

void setup() {
  //[hipL, hipR, ankleL, ankleR]
  bot = new DancingServos(14, 13, 12, 15);
  calibrateTrims(bot);

  //delay(1000);
  //Serial.begin(9600);
  //delay(2000);
}

void loop() {
  //oscillatorTest();
  //servoTest();
  //dancingServosTest();

  bot->position0();
  delay(1000);

  //dance moves here
  bot->demo1();
  bot->demo2();
  //add more moves

}

//manual calibration- based on how the servos are attatched to the parts
void calibrateTrims(DancingServos* bot) {
  //[hipL, hipR, ankleL, ankleR]
  bot->setTrims(75, 130, 45, 45);
}




//TEST FUNCTIONS
void servoTest(int angle) {
  osc.attach(12);
  osc.startO();
  osc.setAmp(40);
  osc.setOff(50);
  osc.setPer(2500);
  delay(2000);
  int x = osc.getPos();
  Serial.print(String(x));
  osc.setPos(angle);
  osc.stopO();
  while(true);
}

void oscillatorTest() {
  osc.attach(12);
  osc.startO();
  long period = 2500;
  long cycles = 5;
  long t0 = millis();
  for (long t = t0; t < (period * cycles + t0); t = millis()) {
    delay(30);
    osc.refreshPos();
  }
  osc.stopO();
  while(true);
}

void dancingServosTest() {
  bot->position0();
  delay(500);
  bot->themAnkles(5);
  delay(500);
  bot->position0();
  while(true);
}