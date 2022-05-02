/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //setup serial
  Serial.begin(9600);
  Serial.print("Hello World!");

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Time since outage:");

  // Print start message to the serial port:
  Serial.print("Started!");
}

void loop() {
  // print the time to the Serial Monitor
  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  int days = 0;
  int months = 0;
  int years = 0;

  seconds = millis() / 1000; - minutes * 60;
  minutes = seconds / 60 - hours * 60;
  hours = minutes / 60 - days * 24;
  days = hours / 24 - months * 30;
  months = days / 30; //- years * 12;

  int overflows = 0;

  if (millis() == 2147483647) {
    overflows = overflows + 1;
    Serial.print("Overflow! number: " + String(overflows));
  }

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  if (1000 > millis()){
    lcd.print("Init...");
    Serial.print("Init...");
  } else {
    lcd.print(String(months) + "m " + String(days) + "d " + String(hours) + "h " + String(minutes) + "m " + String(seconds) + "s");
    Serial.print(String(years) + "y " + String(months) + "m " + String(days) + "d " + String(hours) + "h " + String(minutes) + "m " + String(seconds) + "s");
  }
}