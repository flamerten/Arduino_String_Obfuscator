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

char c0[] = {141,72,148,218,96,3,164,191,200,129,245,116,99,105,77,72,128,130,240,109,225,162,196,28,73,166,75,238,188,131,44,199,136};
char c1[] = {229,45,248,182,15,35,211,208,186,237,145,84,16,12,63,33,225,238,208,29,142,208,176,60,32,213,107,223,141,182,30,247,184};
char xor2[34];
OTP_Cipher(c0, c1,33, xor2);
  Serial.println(xor2);

  Serial.begin(115200);
  
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

char c3[] = {68,201,208,43,198,78,70,211,150,98,126};
char c4[] = {44,172,188,71,169,110,49,188,228,14,26};
char xor5[12];
OTP_Cipher(c3, c4,11, xor5);
  Serial.println(xor5);
char c6[] = {236,174,128,157,127,48,118};
char c7[] = {129,215,160,243,30,93,19};
char xor8[8];
OTP_Cipher(c6, c7,7, xor8);
  Serial.println(xor8);
}

