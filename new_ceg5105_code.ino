/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#include "otp_cipher.h"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

const char c0[] = {134,192,106,69,251,131,33,169,200,134,208,209,8,196,135,141,55,47,132,235,225,61,183,159,92,44,136,242,65,199,138,6,74};
const char c1[] = {238,165,6,41,148,163,86,198,186,234,180,241,123,161,245,228,86,67,164,155,142,79,195,191,53,95,168,195,112,242,184,54,122};
char xor2[34];
OTP_Cipher(c0, c1, 33, xor2);
  Serial.println(xor2);

  Serial.begin(115200);
  
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

const char c3[] = {42,241,29,245,59,76,175,125,148,208,226};
const char c4[] = {66,148,113,153,84,108,216,18,230,188,134};
char xor5[12];
OTP_Cipher(c3, c4, 11, xor5);
  Serial.println(xor5);
const char c6[] = {111,117,160,32,72,95,51};
const char c7[] = {2,12,128,78,41,50,86};
char xor8[8];
OTP_Cipher(c6, c7, 7, xor8);
  Serial.println(xor8);
}

