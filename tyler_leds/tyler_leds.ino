// https://github.com/maykon/ButtonDebounce
#include <ButtonDebounce.h>

// https://github.com/biagiom/LedBlinky
#include <LedBlinky.h>

const int pinLedUB = 5;
const int pinLedRD = 6;
const int pinLedYW = 3;
const int pinLedGR = 4;
const int pinLedBU = 2;
const int onTime = 150;
const int offTime = 150;
LedBlinky myLedUB(pinLedUB, OFF, PULL_DOWN);
LedBlinky myLedRD(pinLedRD, OFF, PULL_DOWN);
LedBlinky myLedYW(pinLedYW, OFF, PULL_DOWN);
LedBlinky myLedGR(pinLedGR, OFF, PULL_DOWN);
LedBlinky myLedBU(pinLedBU, OFF, PULL_DOWN);

void onBtnBUChange(int state) {
  myLedBU.on();
}
void onBtnYWChange(int state) {
  myLedYW.on();
}
void onBtnRDChange(int state) {
  myLedRD.on();
}
void onBtnGRChange(int state) {
  myLedGR.on();
}
void onBtnTRChange(int state) {
  myLedUB.on();
  myLedRD.on();
  myLedGR.on();
  myLedYW.on();
  myLedBU.on();
}
void onBtnTLChange(int state) {
  myLedUB.off();
  myLedRD.off();
  myLedGR.off();
  myLedYW.off();
  myLedBU.off();
}

ButtonDebounce btnBU(9,250);
ButtonDebounce btnYW(8,250);
ButtonDebounce btnRD(10,250);
ButtonDebounce btnGR(11,250);
ButtonDebounce btnTR(12,250);
ButtonDebounce btnTL(7,250);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) ;
  myLedUB.begin();
  myLedRD.begin();
  myLedYW.begin();
  myLedGR.begin();
  myLedBU.begin();
  
  btnBU.setCallback(onBtnBUChange);
  btnYW.setCallback(onBtnYWChange);
  btnRD.setCallback(onBtnRDChange);
  btnGR.setCallback(onBtnGRChange);
  btnTR.setCallback(onBtnTRChange);
  btnTL.setCallback(onBtnTLChange);

  myLedUB.blink(onTime, offTime, 255);
  myLedRD.blink(onTime, offTime, 255);
  myLedYW.blink(onTime, offTime, 255);
  myLedGR.blink(onTime, offTime, 255);
  myLedBU.blink(onTime, offTime, 255);

  myLedUB.off();
  myLedRD.off();
  myLedYW.off();
  myLedGR.off();
  myLedBU.off();
}

void loop() {
  btnBU.update();
  btnYW.update();
  btnRD.update();
  btnGR.update();
  btnTR.update();
  btnTL.update();
//  myLedYW.blink(onTime,offTime, 255);
//  myLedGR.blink(onTime,offTime, 255);
//  myLedBU.blink(onTime,offTime, 255);
//  myLedUB.blink(onTime,offTime, 255);
}
