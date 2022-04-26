      
/*
 * Simple Touch Potentiometer Example with Arduino
 *
 * Reads the pot value and controls the brightness of the Arduino LED on
 * Digital Pin 13.  Also logs new values to the serial port.  Utilizes
 * both the direct and indirect command interface forms.
 *
 * Assumes Touch Pot is at I2C Address 8
 *
 * Released into the public domain by Dan Julio.  This software is supplied on an as-is 
 * basis and no warranty as to its suitability for any particular purpose is either made
 * or implied.  danjuliodesigns, LLC. will not accept any claim for damages howsoever
 * arising as a result of use or failure of this software.
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "Wire.h"

#define STRAND_1 9
#define STRAND_2 10
#define STRAND_3 11
#define STRAND_4 12
#define STRAND_5 13

// Setup associated Neopixel strips
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(15, STRAND_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(15, STRAND_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(15, STRAND_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(15, STRAND_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(15, STRAND_5, NEO_GRB + NEO_KHZ800);

int i2cAddr = 8; // Direct access at i2cAddr, indirect registers at i2cAddr+1

uint8_t prevValue;
uint8_t curValue;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
  strip4.begin();
  strip4.show();
  strip5.begin();
  strip5.show();
  setColorStrip1(strip1.Color(225,30,0));
  setColorStrip2(strip2.Color(225,30,0));
  setColorStrip3(strip3.Color(225,30,0));
  setColorStrip4(strip4.Color(225,30,0));
  setColorStrip5(strip5.Color(225,30,0));
  // Demonstrate access to Touch Potentiometer registers
  WriteTpReg(1, 128); // set to 50% by writing to register 1
  curValue = ReadTpReg(1); // read back value just set
  
  prevValue = curValue;
  
}

void loop() {
  delay(1);  // Read ~20 times/second

  // Demonstrate direct access to Touch Potentiometer value
  curValue = ReadTpValue(); // faster I2C access than register read
  if (curValue != prevValue) {
    Serial.println(curValue);
    prevValue = curValue;
    switch(curValue) {
     case 0:
    setColorStrip1(strip1.Color(255,0,0));
    setColorStrip2(strip2.Color(255,0,0));
    setColorStrip3(strip3.Color(255,0,0));
    setColorStrip4(strip4.Color(255,0,0));
    setColorStrip5(strip5.Color(255,0,0));
    break;
case 1:
    setColorStrip1(strip1.Color(253,2,0));
    setColorStrip2(strip2.Color(253,2,0));
    setColorStrip3(strip3.Color(253,2,0));
    setColorStrip4(strip4.Color(253,2,0));
    setColorStrip5(strip5.Color(253,2,0));
    break;
case 2:
    setColorStrip1(strip1.Color(250,5,0));
    setColorStrip2(strip2.Color(250,5,0));
    setColorStrip3(strip3.Color(250,5,0));
    setColorStrip4(strip4.Color(250,5,0));
    setColorStrip5(strip5.Color(250,5,0));
    break;
case 3:
    setColorStrip1(strip1.Color(248,7,0));
    setColorStrip2(strip2.Color(248,7,0));
    setColorStrip3(strip3.Color(248,7,0));
    setColorStrip4(strip4.Color(248,7,0));
    setColorStrip5(strip5.Color(248,7,0));
    break;
case 4:
    setColorStrip1(strip1.Color(245,10,0));
    setColorStrip2(strip2.Color(245,10,0));
    setColorStrip3(strip3.Color(245,10,0));
    setColorStrip4(strip4.Color(245,10,0));
    setColorStrip5(strip5.Color(245,10,0));
    break;
case 5:
    setColorStrip1(strip1.Color(243,12,0));
    setColorStrip2(strip2.Color(243,12,0));
    setColorStrip3(strip3.Color(243,12,0));
    setColorStrip4(strip4.Color(243,12,0));
    setColorStrip5(strip5.Color(243,12,0));
    break;
case 6:
    setColorStrip1(strip1.Color(240,15,0));
    setColorStrip2(strip2.Color(240,15,0));
    setColorStrip3(strip3.Color(240,15,0));
    setColorStrip4(strip4.Color(240,15,0));
    setColorStrip5(strip5.Color(240,15,0));
    break;
case 7:
    setColorStrip1(strip1.Color(238,17,0));
    setColorStrip2(strip2.Color(238,17,0));
    setColorStrip3(strip3.Color(238,17,0));
    setColorStrip4(strip4.Color(238,17,0));
    setColorStrip5(strip5.Color(238,17,0));
    break;
case 8:
    setColorStrip1(strip1.Color(235,20,0));
    setColorStrip2(strip2.Color(235,20,0));
    setColorStrip3(strip3.Color(235,20,0));
    setColorStrip4(strip4.Color(235,20,0));
    setColorStrip5(strip5.Color(235,20,0));
    break;
case 9:
    setColorStrip1(strip1.Color(233,22,0));
    setColorStrip2(strip2.Color(233,22,0));
    setColorStrip3(strip3.Color(233,22,0));
    setColorStrip4(strip4.Color(233,22,0));
    setColorStrip5(strip5.Color(233,22,0));
    break;
case 10:
    setColorStrip1(strip1.Color(230,25,0));
    setColorStrip2(strip2.Color(230,25,0));
    setColorStrip3(strip3.Color(230,25,0));
    setColorStrip4(strip4.Color(230,25,0));
    setColorStrip5(strip5.Color(230,25,0));
    break;
case 11:
    setColorStrip1(strip1.Color(228,27,0));
    setColorStrip2(strip2.Color(228,27,0));
    setColorStrip3(strip3.Color(228,27,0));
    setColorStrip4(strip4.Color(228,27,0));
    setColorStrip5(strip5.Color(228,27,0));
    break;
case 12:
    setColorStrip1(strip1.Color(225,30,0));
    setColorStrip2(strip2.Color(225,30,0));
    setColorStrip3(strip3.Color(225,30,0));
    setColorStrip4(strip4.Color(225,30,0));
    setColorStrip5(strip5.Color(225,30,0));
    break;
case 13:
    setColorStrip1(strip1.Color(223,33,0));
    setColorStrip2(strip2.Color(223,33,0));
    setColorStrip3(strip3.Color(223,33,0));
    setColorStrip4(strip4.Color(223,33,0));
    setColorStrip5(strip5.Color(223,33,0));
    break;
case 14:
    setColorStrip1(strip1.Color(220,35,0));
    setColorStrip2(strip2.Color(220,35,0));
    setColorStrip3(strip3.Color(220,35,0));
    setColorStrip4(strip4.Color(220,35,0));
    setColorStrip5(strip5.Color(220,35,0));
    break;
case 15:
    setColorStrip1(strip1.Color(218,37,0));
    setColorStrip2(strip2.Color(218,37,0));
    setColorStrip3(strip3.Color(218,37,0));
    setColorStrip4(strip4.Color(218,37,0));
    setColorStrip5(strip5.Color(218,37,0));
    break;
case 16:
    setColorStrip1(strip1.Color(215,40,0));
    setColorStrip2(strip2.Color(215,40,0));
    setColorStrip3(strip3.Color(215,40,0));
    setColorStrip4(strip4.Color(215,40,0));
    setColorStrip5(strip5.Color(215,40,0));
    break;
case 17:
    setColorStrip1(strip1.Color(213,42,0));
    setColorStrip2(strip2.Color(213,42,0));
    setColorStrip3(strip3.Color(213,42,0));
    setColorStrip4(strip4.Color(213,42,0));
    setColorStrip5(strip5.Color(213,42,0));
    break;
case 18:
    setColorStrip1(strip1.Color(210,45,0));
    setColorStrip2(strip2.Color(210,45,0));
    setColorStrip3(strip3.Color(210,45,0));
    setColorStrip4(strip4.Color(210,45,0));
    setColorStrip5(strip5.Color(210,45,0));
    break;
case 19:
    setColorStrip1(strip1.Color(208,47,0));
    setColorStrip2(strip2.Color(208,47,0));
    setColorStrip3(strip3.Color(208,47,0));
    setColorStrip4(strip4.Color(208,47,0));
    setColorStrip5(strip5.Color(208,47,0));
    break;
case 20:
    setColorStrip1(strip1.Color(205,50,0));
    setColorStrip2(strip2.Color(205,50,0));
    setColorStrip3(strip3.Color(205,50,0));
    setColorStrip4(strip4.Color(205,50,0));
    setColorStrip5(strip5.Color(205,50,0));
    break;
case 21:
    setColorStrip1(strip1.Color(203,52,0));
    setColorStrip2(strip2.Color(203,52,0));
    setColorStrip3(strip3.Color(203,52,0));
    setColorStrip4(strip4.Color(203,52,0));
    setColorStrip5(strip5.Color(203,52,0));
    break;
case 22:
    setColorStrip1(strip1.Color(200,55,0));
    setColorStrip2(strip2.Color(200,55,0));
    setColorStrip3(strip3.Color(200,55,0));
    setColorStrip4(strip4.Color(200,55,0));
    setColorStrip5(strip5.Color(200,55,0));
    break;
case 23:
    setColorStrip1(strip1.Color(198,57,0));
    setColorStrip2(strip2.Color(198,57,0));
    setColorStrip3(strip3.Color(198,57,0));
    setColorStrip4(strip4.Color(198,57,0));
    setColorStrip5(strip5.Color(198,57,0));
    break;
case 24:
    setColorStrip1(strip1.Color(195,60,0));
    setColorStrip2(strip2.Color(195,60,0));
    setColorStrip3(strip3.Color(195,60,0));
    setColorStrip4(strip4.Color(195,60,0));
    setColorStrip5(strip5.Color(195,60,0));
    break;
case 25:
    setColorStrip1(strip1.Color(193,62,0));
    setColorStrip2(strip2.Color(193,62,0));
    setColorStrip3(strip3.Color(193,62,0));
    setColorStrip4(strip4.Color(193,62,0));
    setColorStrip5(strip5.Color(193,62,0));
    break;
case 26:
    setColorStrip1(strip1.Color(190,65,0));
    setColorStrip2(strip2.Color(190,65,0));
    setColorStrip3(strip3.Color(190,65,0));
    setColorStrip4(strip4.Color(190,65,0));
    setColorStrip5(strip5.Color(190,65,0));
    break;
case 27:
    setColorStrip1(strip1.Color(188,67,0));
    setColorStrip2(strip2.Color(188,67,0));
    setColorStrip3(strip3.Color(188,67,0));
    setColorStrip4(strip4.Color(188,67,0));
    setColorStrip5(strip5.Color(188,67,0));
    break;
case 28:
    setColorStrip1(strip1.Color(185,70,0));
    setColorStrip2(strip2.Color(185,70,0));
    setColorStrip3(strip3.Color(185,70,0));
    setColorStrip4(strip4.Color(185,70,0));
    setColorStrip5(strip5.Color(185,70,0));
    break;
case 29:
    setColorStrip1(strip1.Color(183,72,0));
    setColorStrip2(strip2.Color(183,72,0));
    setColorStrip3(strip3.Color(183,72,0));
    setColorStrip4(strip4.Color(183,72,0));
    setColorStrip5(strip5.Color(183,72,0));
    break;
case 30:
    setColorStrip1(strip1.Color(180,75,0));
    setColorStrip2(strip2.Color(180,75,0));
    setColorStrip3(strip3.Color(180,75,0));
    setColorStrip4(strip4.Color(180,75,0));
    setColorStrip5(strip5.Color(180,75,0));
    break;
case 31:
    setColorStrip1(strip1.Color(178,77,0));
    setColorStrip2(strip2.Color(178,77,0));
    setColorStrip3(strip3.Color(178,77,0));
    setColorStrip4(strip4.Color(178,77,0));
    setColorStrip5(strip5.Color(178,77,0));
    break;
case 32:
    setColorStrip1(strip1.Color(175,80,0));
    setColorStrip2(strip2.Color(175,80,0));
    setColorStrip3(strip3.Color(175,80,0));
    setColorStrip4(strip4.Color(175,80,0));
    setColorStrip5(strip5.Color(175,80,0));
    break;
case 33:
    setColorStrip1(strip1.Color(173,82,0));
    setColorStrip2(strip2.Color(173,82,0));
    setColorStrip3(strip3.Color(173,82,0));
    setColorStrip4(strip4.Color(173,82,0));
    setColorStrip5(strip5.Color(173,82,0));
    break;
case 34:
    setColorStrip1(strip1.Color(170,85,0));
    setColorStrip2(strip2.Color(170,85,0));
    setColorStrip3(strip3.Color(170,85,0));
    setColorStrip4(strip4.Color(170,85,0));
    setColorStrip5(strip5.Color(170,85,0));
    break;
case 35:
    setColorStrip1(strip1.Color(168,87,0));
    setColorStrip2(strip2.Color(168,87,0));
    setColorStrip3(strip3.Color(168,87,0));
    setColorStrip4(strip4.Color(168,87,0));
    setColorStrip5(strip5.Color(168,87,0));
    break;
case 36:
    setColorStrip1(strip1.Color(165,90,0));
    setColorStrip2(strip2.Color(165,90,0));
    setColorStrip3(strip3.Color(165,90,0));
    setColorStrip4(strip4.Color(165,90,0));
    setColorStrip5(strip5.Color(165,90,0));
    break;
case 37:
    setColorStrip1(strip1.Color(163,92,0));
    setColorStrip2(strip2.Color(163,92,0));
    setColorStrip3(strip3.Color(163,92,0));
    setColorStrip4(strip4.Color(163,92,0));
    setColorStrip5(strip5.Color(163,92,0));
    break;
case 38:
    setColorStrip1(strip1.Color(160,95,0));
    setColorStrip2(strip2.Color(160,95,0));
    setColorStrip3(strip3.Color(160,95,0));
    setColorStrip4(strip4.Color(160,95,0));
    setColorStrip5(strip5.Color(160,95,0));
    break;
case 39:
    setColorStrip1(strip1.Color(158,97,0));
    setColorStrip2(strip2.Color(158,97,0));
    setColorStrip3(strip3.Color(158,97,0));
    setColorStrip4(strip4.Color(158,97,0));
    setColorStrip5(strip5.Color(158,97,0));
    break;
case 40:
    setColorStrip1(strip1.Color(155,100,0));
    setColorStrip2(strip2.Color(155,100,0));
    setColorStrip3(strip3.Color(155,100,0));
    setColorStrip4(strip4.Color(155,100,0));
    setColorStrip5(strip5.Color(155,100,0));
    break;
case 41:
    setColorStrip1(strip1.Color(153,102,0));
    setColorStrip2(strip2.Color(153,102,0));
    setColorStrip3(strip3.Color(153,102,0));
    setColorStrip4(strip4.Color(153,102,0));
    setColorStrip5(strip5.Color(153,102,0));
    break;
case 42:
    setColorStrip1(strip1.Color(150,105,0));
    setColorStrip2(strip2.Color(150,105,0));
    setColorStrip3(strip3.Color(150,105,0));
    setColorStrip4(strip4.Color(150,105,0));
    setColorStrip5(strip5.Color(150,105,0));
    break;
case 43:
    setColorStrip1(strip1.Color(148,107,0));
    setColorStrip2(strip2.Color(148,107,0));
    setColorStrip3(strip3.Color(148,107,0));
    setColorStrip4(strip4.Color(148,107,0));
    setColorStrip5(strip5.Color(148,107,0));
    break;
case 44:
    setColorStrip1(strip1.Color(145,110,0));
    setColorStrip2(strip2.Color(145,110,0));
    setColorStrip3(strip3.Color(145,110,0));
    setColorStrip4(strip4.Color(145,110,0));
    setColorStrip5(strip5.Color(145,110,0));
    break;
case 45:
    setColorStrip1(strip1.Color(143,112,0));
    setColorStrip2(strip2.Color(143,112,0));
    setColorStrip3(strip3.Color(143,112,0));
    setColorStrip4(strip4.Color(143,112,0));
    setColorStrip5(strip5.Color(143,112,0));
    break;
case 46:
    setColorStrip1(strip1.Color(140,115,0));
    setColorStrip2(strip2.Color(140,115,0));
    setColorStrip3(strip3.Color(140,115,0));
    setColorStrip4(strip4.Color(140,115,0));
    setColorStrip5(strip5.Color(140,115,0));
    break;
case 47:
    setColorStrip1(strip1.Color(138,117,0));
    setColorStrip2(strip2.Color(138,117,0));
    setColorStrip3(strip3.Color(138,117,0));
    setColorStrip4(strip4.Color(138,117,0));
    setColorStrip5(strip5.Color(138,117,0));
    break;
case 48:
    setColorStrip1(strip1.Color(135,120,0));
    setColorStrip2(strip2.Color(135,120,0));
    setColorStrip3(strip3.Color(135,120,0));
    setColorStrip4(strip4.Color(135,120,0));
    setColorStrip5(strip5.Color(135,120,0));
    break;
case 49:
    setColorStrip1(strip1.Color(133,122,0));
    setColorStrip2(strip2.Color(133,122,0));
    setColorStrip3(strip3.Color(133,122,0));
    setColorStrip4(strip4.Color(133,122,0));
    setColorStrip5(strip5.Color(133,122,0));
    break;
case 50:
    setColorStrip1(strip1.Color(130,125,0));
    setColorStrip2(strip2.Color(130,125,0));
    setColorStrip3(strip3.Color(130,125,0));
    setColorStrip4(strip4.Color(130,125,0));
    setColorStrip5(strip5.Color(130,125,0));
    break;
case 51:
    setColorStrip1(strip1.Color(128,127,0));
    setColorStrip2(strip2.Color(128,127,0));
    setColorStrip3(strip3.Color(128,127,0));
    setColorStrip4(strip4.Color(128,127,0));
    setColorStrip5(strip5.Color(128,127,0));
    break;
case 52:
    setColorStrip1(strip1.Color(125,130,0));
    setColorStrip2(strip2.Color(125,130,0));
    setColorStrip3(strip3.Color(125,130,0));
    setColorStrip4(strip4.Color(125,130,0));
    setColorStrip5(strip5.Color(125,130,0));
    break;
case 53:
    setColorStrip1(strip1.Color(123,132,0));
    setColorStrip2(strip2.Color(123,132,0));
    setColorStrip3(strip3.Color(123,132,0));
    setColorStrip4(strip4.Color(123,132,0));
    setColorStrip5(strip5.Color(123,132,0));
    break;
case 54:
    setColorStrip1(strip1.Color(120,135,0));
    setColorStrip2(strip2.Color(120,135,0));
    setColorStrip3(strip3.Color(120,135,0));
    setColorStrip4(strip4.Color(120,135,0));
    setColorStrip5(strip5.Color(120,135,0));
    break;
case 55:
    setColorStrip1(strip1.Color(118,137,0));
    setColorStrip2(strip2.Color(118,137,0));
    setColorStrip3(strip3.Color(118,137,0));
    setColorStrip4(strip4.Color(118,137,0));
    setColorStrip5(strip5.Color(118,137,0));
    break;
case 56:
    setColorStrip1(strip1.Color(115,140,0));
    setColorStrip2(strip2.Color(115,140,0));
    setColorStrip3(strip3.Color(115,140,0));
    setColorStrip4(strip4.Color(115,140,0));
    setColorStrip5(strip5.Color(115,140,0));
    break;
case 57:
    setColorStrip1(strip1.Color(113,142,0));
    setColorStrip2(strip2.Color(113,142,0));
    setColorStrip3(strip3.Color(113,142,0));
    setColorStrip4(strip4.Color(113,142,0));
    setColorStrip5(strip5.Color(113,142,0));
    break;
case 58:
    setColorStrip1(strip1.Color(110,145,0));
    setColorStrip2(strip2.Color(110,145,0));
    setColorStrip3(strip3.Color(110,145,0));
    setColorStrip4(strip4.Color(110,145,0));
    setColorStrip5(strip5.Color(110,145,0));
    break;
case 59:
    setColorStrip1(strip1.Color(108,147,0));
    setColorStrip2(strip2.Color(108,147,0));
    setColorStrip3(strip3.Color(108,147,0));
    setColorStrip4(strip4.Color(108,147,0));
    setColorStrip5(strip5.Color(108,147,0));
    break;
case 60:
    setColorStrip1(strip1.Color(105,150,0));
    setColorStrip2(strip2.Color(105,150,0));
    setColorStrip3(strip3.Color(105,150,0));
    setColorStrip4(strip4.Color(105,150,0));
    setColorStrip5(strip5.Color(105,150,0));
    break;
case 61:
    setColorStrip1(strip1.Color(103,152,0));
    setColorStrip2(strip2.Color(103,152,0));
    setColorStrip3(strip3.Color(103,152,0));
    setColorStrip4(strip4.Color(103,152,0));
    setColorStrip5(strip5.Color(103,152,0));
    break;
case 62:
    setColorStrip1(strip1.Color(100,155,0));
    setColorStrip2(strip2.Color(100,155,0));
    setColorStrip3(strip3.Color(100,155,0));
    setColorStrip4(strip4.Color(100,155,0));
    setColorStrip5(strip5.Color(100,155,0));
    break;
case 63:
    setColorStrip1(strip1.Color(98,157,0));
    setColorStrip2(strip2.Color(98,157,0));
    setColorStrip3(strip3.Color(98,157,0));
    setColorStrip4(strip4.Color(98,157,0));
    setColorStrip5(strip5.Color(98,157,0));
    break;
case 64:
    setColorStrip1(strip1.Color(95,160,0));
    setColorStrip2(strip2.Color(95,160,0));
    setColorStrip3(strip3.Color(95,160,0));
    setColorStrip4(strip4.Color(95,160,0));
    setColorStrip5(strip5.Color(95,160,0));
    break;
case 65:
    setColorStrip1(strip1.Color(93,162,0));
    setColorStrip2(strip2.Color(93,162,0));
    setColorStrip3(strip3.Color(93,162,0));
    setColorStrip4(strip4.Color(93,162,0));
    setColorStrip5(strip5.Color(93,162,0));
    break;
case 66:
    setColorStrip1(strip1.Color(90,165,0));
    setColorStrip2(strip2.Color(90,165,0));
    setColorStrip3(strip3.Color(90,165,0));
    setColorStrip4(strip4.Color(90,165,0));
    setColorStrip5(strip5.Color(90,165,0));
    break;
case 67:
    setColorStrip1(strip1.Color(88,167,0));
    setColorStrip2(strip2.Color(88,167,0));
    setColorStrip3(strip3.Color(88,167,0));
    setColorStrip4(strip4.Color(88,167,0));
    setColorStrip5(strip5.Color(88,167,0));
    break;
case 68:
    setColorStrip1(strip1.Color(85, 170,0));
    setColorStrip2(strip2.Color(85, 170,0));
    setColorStrip3(strip3.Color(85, 170,0));
    setColorStrip4(strip4.Color(85, 170,0));
    setColorStrip5(strip5.Color(85, 170,0));
    break; 
case 69: 
    setColorStrip1(strip1.Color(83, 172,0));
    setColorStrip2(strip2.Color(83, 172,0));
    setColorStrip3(strip3.Color(83, 172,0));
    setColorStrip4(strip4.Color(83, 172,0));
    setColorStrip5(strip5.Color(83, 172,0));
    break; 
case 70: 
    setColorStrip1(strip1.Color(80, 175,0));
    setColorStrip2(strip2.Color(80, 175,0));
    setColorStrip3(strip3.Color(80, 175,0));
    setColorStrip4(strip4.Color(80, 175,0));
    setColorStrip5(strip5.Color(80, 175,0));
    break;
case 71:
    setColorStrip1(strip1.Color(78, 177,0));
    setColorStrip2(strip2.Color(78, 177,0));
    setColorStrip3(strip3.Color(78, 177,0));
    setColorStrip4(strip4.Color(78, 177,0));
    setColorStrip5(strip5.Color(78, 177,0));
    break;
case 72:
    setColorStrip1(strip1.Color(75, 180,0));
    setColorStrip2(strip2.Color(75, 180,0));
    setColorStrip3(strip3.Color(75, 180,0));
    setColorStrip4(strip4.Color(75, 180,0));
    setColorStrip5(strip5.Color(75, 180,0));
    break;
case 73:
    setColorStrip1(strip1.Color(73, 182,0));
    setColorStrip2(strip2.Color(73, 182,0));
    setColorStrip3(strip3.Color(73, 182,0));
    setColorStrip4(strip4.Color(73, 182,0));
    setColorStrip5(strip5.Color(73, 182,0));
    break;
case 74:
    setColorStrip1(strip1.Color(70, 185,0));
    setColorStrip2(strip2.Color(70, 185,0));
    setColorStrip3(strip3.Color(70, 185,0));
    setColorStrip4(strip4.Color(70, 185,0));
    setColorStrip5(strip5.Color(70, 185,0));
    break;
case 75:
    setColorStrip1(strip1.Color(68, 187,0));
    setColorStrip2(strip2.Color(68, 187,0));
    setColorStrip3(strip3.Color(68, 187,0));
    setColorStrip4(strip4.Color(68, 187,0));
    setColorStrip5(strip5.Color(68, 187,0));
    break;
case 76:
    setColorStrip1(strip1.Color(65, 190,0));
    setColorStrip2(strip2.Color(65, 190,0));
    setColorStrip3(strip3.Color(65, 190,0));
    setColorStrip4(strip4.Color(65, 190,0));
    setColorStrip5(strip5.Color(65, 190,0));
    break;
case 77:
    setColorStrip1(strip1.Color(63, 192,0));
    setColorStrip2(strip2.Color(63, 192,0));
    setColorStrip3(strip3.Color(63, 192,0));
    setColorStrip4(strip4.Color(63, 192,0));
    setColorStrip5(strip5.Color(63, 192,0));
    break;
case 78:
    setColorStrip1(strip1.Color(60, 195,0));
    setColorStrip2(strip2.Color(60, 195,0));
    setColorStrip3(strip3.Color(60, 195,0));
    setColorStrip4(strip4.Color(60, 195,0));
    setColorStrip5(strip5.Color(60, 195,0));
    break;
case 79:
    setColorStrip1(strip1.Color(58, 197,0));
    setColorStrip2(strip2.Color(58, 197,0));
    setColorStrip3(strip3.Color(58, 197,0));
    setColorStrip4(strip4.Color(58, 197,0));
    setColorStrip5(strip5.Color(58, 197,0));
    break;
case 80:
    setColorStrip1(strip1.Color(55, 200,0));
    setColorStrip2(strip2.Color(55, 200,0));
    setColorStrip3(strip3.Color(55, 200,0));
    setColorStrip4(strip4.Color(55, 200,0));
    setColorStrip5(strip5.Color(55, 200,0));
    break;
case 81:
    setColorStrip1(strip1.Color(53, 202,0));
    setColorStrip2(strip2.Color(53, 202,0));
    setColorStrip3(strip3.Color(53, 202,0));
    setColorStrip4(strip4.Color(53, 202,0));
    setColorStrip5(strip5.Color(53, 202,0));
    break;
case 82:
    setColorStrip1(strip1.Color(50, 205,0));
    setColorStrip2(strip2.Color(50, 205,0));
    setColorStrip3(strip3.Color(50, 205,0));
    setColorStrip4(strip4.Color(50, 205,0));
    setColorStrip5(strip5.Color(50, 205,0));
    break;
case 83:
    setColorStrip1(strip1.Color(48, 207,0));
    setColorStrip2(strip2.Color(48, 207,0));
    setColorStrip3(strip3.Color(48, 207,0));
    setColorStrip4(strip4.Color(48, 207,0));
    setColorStrip5(strip5.Color(48, 207,0));
    break;
case 84:
    setColorStrip1(strip1.Color(45, 210,0));
    setColorStrip2(strip2.Color(45, 210,0));
    setColorStrip3(strip3.Color(45, 210,0));
    setColorStrip4(strip4.Color(45, 210,0));
    setColorStrip5(strip5.Color(45, 210,0));
    break;
case 85:
    setColorStrip1(strip1.Color(43, 212,0));
    setColorStrip2(strip2.Color(43, 212,0));
    setColorStrip3(strip3.Color(43, 212,0));
    setColorStrip4(strip4.Color(43, 212,0));
    setColorStrip5(strip5.Color(43, 212,0));
    break;
case 86:
    setColorStrip1(strip1.Color(40, 215,0));
    setColorStrip2(strip2.Color(40, 215,0));
    setColorStrip3(strip3.Color(40, 215,0));
    setColorStrip4(strip4.Color(40, 215,0));
    setColorStrip5(strip5.Color(40, 215,0));
    break;
case 87:
    setColorStrip1(strip1.Color(38, 217,0));
    setColorStrip2(strip2.Color(38, 217,0));
    setColorStrip3(strip3.Color(38, 217,0));
    setColorStrip4(strip4.Color(38, 217,0));
    setColorStrip5(strip5.Color(38, 217,0));
    break;
case 88:
    setColorStrip1(strip1.Color(35, 220,0));
    setColorStrip2(strip2.Color(35, 220,0));
    setColorStrip3(strip3.Color(35, 220,0));
    setColorStrip4(strip4.Color(35, 220,0));
    setColorStrip5(strip5.Color(35, 220,0));
    break;
case 89:
    setColorStrip1(strip1.Color(33, 222,0));
    setColorStrip2(strip2.Color(33, 222,0));
    setColorStrip3(strip3.Color(33, 222,0));
    setColorStrip4(strip4.Color(33, 222,0));
    setColorStrip5(strip5.Color(33, 222,0));
    break;
case 90:
    setColorStrip1(strip1.Color(30, 225,0));
    setColorStrip2(strip2.Color(30, 225,0));
    setColorStrip3(strip3.Color(30, 225,0));
    setColorStrip4(strip4.Color(30, 225,0));
    setColorStrip5(strip5.Color(30, 225,0));
    break;
case 91:
    setColorStrip1(strip1.Color(28, 227,0));
    setColorStrip2(strip2.Color(28, 227,0));
    setColorStrip3(strip3.Color(28, 227,0));
    setColorStrip4(strip4.Color(28, 227,0));
    setColorStrip5(strip5.Color(28, 227,0));
    break;
case 92:
    setColorStrip1(strip1.Color(25, 230,0));
    setColorStrip2(strip2.Color(25, 230,0));
    setColorStrip3(strip3.Color(25, 230,0));
    setColorStrip4(strip4.Color(25, 230,0));
    setColorStrip5(strip5.Color(25, 230,0));
    break;
case 93:
    setColorStrip1(strip1.Color(23, 232,0));
    setColorStrip2(strip2.Color(23, 232,0));
    setColorStrip3(strip3.Color(23, 232,0));
    setColorStrip4(strip4.Color(23, 232,0));
    setColorStrip5(strip5.Color(23, 232,0));
    break;
case 94:
    setColorStrip1(strip1.Color(20, 235,0));
    setColorStrip2(strip2.Color(20, 235,0));
    setColorStrip3(strip3.Color(20, 235,0));
    setColorStrip4(strip4.Color(20, 235,0));
    setColorStrip5(strip5.Color(20, 235,0));
    break;
case 95:
    setColorStrip1(strip1.Color(18, 237,0));
    setColorStrip2(strip2.Color(18, 237,0));
    setColorStrip3(strip3.Color(18, 237,0));
    setColorStrip4(strip4.Color(18, 237,0));
    setColorStrip5(strip5.Color(18, 237,0));
    break;
case 96:
    setColorStrip1(strip1.Color(15, 240,0));
    setColorStrip2(strip2.Color(15, 240,0));
    setColorStrip3(strip3.Color(15, 240,0));
    setColorStrip4(strip4.Color(15, 240,0));
    setColorStrip5(strip5.Color(15, 240,0));
    break;
case 97:
    setColorStrip1(strip1.Color(13, 242,0));
    setColorStrip2(strip2.Color(13, 242,0));
    setColorStrip3(strip3.Color(13, 242,0));
    setColorStrip4(strip4.Color(13, 242,0));
    setColorStrip5(strip5.Color(13, 242,0));
    break;
case 98:
    setColorStrip1(strip1.Color(10, 245,0));
    setColorStrip2(strip2.Color(10, 245,0));
    setColorStrip3(strip3.Color(10, 245,0));
    setColorStrip4(strip4.Color(10, 245,0));
    setColorStrip5(strip5.Color(10, 245,0));
    break;
case 99:
    setColorStrip1(strip1.Color(8, 247,0));
    setColorStrip2(strip2.Color(8, 247,0));
    setColorStrip3(strip3.Color(8, 247,0));
    setColorStrip4(strip4.Color(8, 247,0));
    setColorStrip5(strip5.Color(8, 247,0));
    break;
case 100:
    setColorStrip1(strip1.Color(5, 250,0));
    setColorStrip2(strip2.Color(5, 250,0));
    setColorStrip3(strip3.Color(5, 250,0));
    setColorStrip4(strip4.Color(5, 250,0));
    setColorStrip5(strip5.Color(5, 250,0));
    break;
case 101:
    setColorStrip1(strip1.Color(3, 252,0));
    setColorStrip2(strip2.Color(3, 252,0));
    setColorStrip3(strip3.Color(3, 252,0));
    setColorStrip4(strip4.Color(3, 252,0));
    setColorStrip5(strip5.Color(3, 252,0));
    break;
case 102:
    setColorStrip1(strip1.Color(0, 255,0));
    setColorStrip2(strip2.Color(0, 255,0));
    setColorStrip3(strip3.Color(0, 255,0));
    setColorStrip4(strip4.Color(0, 255,0));
    setColorStrip5(strip5.Color(0, 255,0));
    break;
case 103:
    setColorStrip1(strip1.Color(0,253,2));
    setColorStrip2(strip2.Color(0,253,2));
    setColorStrip3(strip3.Color(0,253,2));
    setColorStrip4(strip4.Color(0,253,2));
    setColorStrip5(strip5.Color(0,253,2));
    break;
case 104:
    setColorStrip1(strip1.Color(0,250,5));
    setColorStrip2(strip2.Color(0,250,5));
    setColorStrip3(strip3.Color(0,250,5));
    setColorStrip4(strip4.Color(0,250,5));
    setColorStrip5(strip5.Color(0,250,5));
    break;
case 105:
    setColorStrip1(strip1.Color(0,247,7));
    setColorStrip2(strip2.Color(0,247,7));
    setColorStrip3(strip3.Color(0,247,7));
    setColorStrip4(strip4.Color(0,247,7));
    setColorStrip5(strip5.Color(0,247,7));
    break;
case 106:
    setColorStrip1(strip1.Color(0,245,10));
    setColorStrip2(strip2.Color(0,245,10));
    setColorStrip3(strip3.Color(0,245,10));
    setColorStrip4(strip4.Color(0,245,10));
    setColorStrip5(strip5.Color(0,245,10));
    break;
case 107:
    setColorStrip1(strip1.Color(0,242,12));
    setColorStrip2(strip2.Color(0,242,12));
    setColorStrip3(strip3.Color(0,242,12));
    setColorStrip4(strip4.Color(0,242,12));
    setColorStrip5(strip5.Color(0,242,12));
    break;
case 108:
    setColorStrip1(strip1.Color(0,240,15));
    setColorStrip2(strip2.Color(0,240,15));
    setColorStrip3(strip3.Color(0,240,15));
    setColorStrip4(strip4.Color(0,240,15));
    setColorStrip5(strip5.Color(0,240,15));
    break;
case 109:
    setColorStrip1(strip1.Color(0,237,17));
    setColorStrip2(strip2.Color(0,237,17));
    setColorStrip3(strip3.Color(0,237,17));
    setColorStrip4(strip4.Color(0,237,17));
    setColorStrip5(strip5.Color(0,237,17));
    break;
case 110:
    setColorStrip1(strip1.Color(0,235,20));
    setColorStrip2(strip2.Color(0,235,20));
    setColorStrip3(strip3.Color(0,235,20));
    setColorStrip4(strip4.Color(0,235,20));
    setColorStrip5(strip5.Color(0,235,20));
    break;
case 111:
    setColorStrip1(strip1.Color(0,232,22));
    setColorStrip2(strip2.Color(0,232,22));
    setColorStrip3(strip3.Color(0,232,22));
    setColorStrip4(strip4.Color(0,232,22));
    setColorStrip5(strip5.Color(0,232,22));
    break;
case 112:
    setColorStrip1(strip1.Color(0,230,25));
    setColorStrip2(strip2.Color(0,230,25));
    setColorStrip3(strip3.Color(0,230,25));
    setColorStrip4(strip4.Color(0,230,25));
    setColorStrip5(strip5.Color(0,230,25));
    break;
case 113:
    setColorStrip1(strip1.Color(0,227,27));
    setColorStrip2(strip2.Color(0,227,27));
    setColorStrip3(strip3.Color(0,227,27));
    setColorStrip4(strip4.Color(0,227,27));
    setColorStrip5(strip5.Color(0,227,27));
    break;
case 114:
    setColorStrip1(strip1.Color(0,225,30));
    setColorStrip2(strip2.Color(0,225,30));
    setColorStrip3(strip3.Color(0,225,30));
    setColorStrip4(strip4.Color(0,225,30));
    setColorStrip5(strip5.Color(0,225,30));
    break;
case 115:
    setColorStrip1(strip1.Color(0,222,32));
    setColorStrip2(strip2.Color(0,222,32));
    setColorStrip3(strip3.Color(0,222,32));
    setColorStrip4(strip4.Color(0,222,32));
    setColorStrip5(strip5.Color(0,222,32));
    break;
case 116:
    setColorStrip1(strip1.Color(0,220,35));
    setColorStrip2(strip2.Color(0,220,35));
    setColorStrip3(strip3.Color(0,220,35));
    setColorStrip4(strip4.Color(0,220,35));
    setColorStrip5(strip5.Color(0,220,35));
    break;
case 117:
    setColorStrip1(strip1.Color(0,217,37));
    setColorStrip2(strip2.Color(0,217,37));
    setColorStrip3(strip3.Color(0,217,37));
    setColorStrip4(strip4.Color(0,217,37));
    setColorStrip5(strip5.Color(0,217,37));
    break;
case 118:
    setColorStrip1(strip1.Color(0,215,40));
    setColorStrip2(strip2.Color(0,215,40));
    setColorStrip3(strip3.Color(0,215,40));
    setColorStrip4(strip4.Color(0,215,40));
    setColorStrip5(strip5.Color(0,215,40));
    break;
case 119:
    setColorStrip1(strip1.Color(0,212,42));
    setColorStrip2(strip2.Color(0,212,42));
    setColorStrip3(strip3.Color(0,212,42));
    setColorStrip4(strip4.Color(0,212,42));
    setColorStrip5(strip5.Color(0,212,42));
    break;
case 120:
    setColorStrip1(strip1.Color(0,210,45));
    setColorStrip2(strip2.Color(0,210,45));
    setColorStrip3(strip3.Color(0,210,45));
    setColorStrip4(strip4.Color(0,210,45));
    setColorStrip5(strip5.Color(0,210,45));
    break;
case 121:
    setColorStrip1(strip1.Color(0,207,47));
    setColorStrip2(strip2.Color(0,207,47));
    setColorStrip3(strip3.Color(0,207,47));
    setColorStrip4(strip4.Color(0,207,47));
    setColorStrip5(strip5.Color(0,207,47));
    break;
case 122:
    setColorStrip1(strip1.Color(0,205,50));
    setColorStrip2(strip2.Color(0,205,50));
    setColorStrip3(strip3.Color(0,205,50));
    setColorStrip4(strip4.Color(0,205,50));
    setColorStrip5(strip5.Color(0,205,50));
    break;
case 123:
    setColorStrip1(strip1.Color(0,202,52));
    setColorStrip2(strip2.Color(0,202,52));
    setColorStrip3(strip3.Color(0,202,52));
    setColorStrip4(strip4.Color(0,202,52));
    setColorStrip5(strip5.Color(0,202,52));
    break;
case 124:
    setColorStrip1(strip1.Color(0,200,55));
    setColorStrip2(strip2.Color(0,200,55));
    setColorStrip3(strip3.Color(0,200,55));
    setColorStrip4(strip4.Color(0,200,55));
    setColorStrip5(strip5.Color(0,200,55));
    break;
case 125:
    setColorStrip1(strip1.Color(0,197,57));
    setColorStrip2(strip2.Color(0,197,57));
    setColorStrip3(strip3.Color(0,197,57));
    setColorStrip4(strip4.Color(0,197,57));
    setColorStrip5(strip5.Color(0,197,57));
    break;
case 126:
    setColorStrip1(strip1.Color(0,195,60));
    setColorStrip2(strip2.Color(0,195,60));
    setColorStrip3(strip3.Color(0,195,60));
    setColorStrip4(strip4.Color(0,195,60));
    setColorStrip5(strip5.Color(0,195,60));
    break;
case 127:
    setColorStrip1(strip1.Color(0,192,62));
    setColorStrip2(strip2.Color(0,192,62));
    setColorStrip3(strip3.Color(0,192,62));
    setColorStrip4(strip4.Color(0,192,62));
    setColorStrip5(strip5.Color(0,192,62));
    break;
case 128:
    setColorStrip1(strip1.Color(0,190,65));
    setColorStrip2(strip2.Color(0,190,65));
    setColorStrip3(strip3.Color(0,190,65));
    setColorStrip4(strip4.Color(0,190,65));
    setColorStrip5(strip5.Color(0,190,65));
    break;
case 129:
    setColorStrip1(strip1.Color(0,187,67));
    setColorStrip2(strip2.Color(0,187,67));
    setColorStrip3(strip3.Color(0,187,67));
    setColorStrip4(strip4.Color(0,187,67));
    setColorStrip5(strip5.Color(0,187,67));
    break;
case 130:
    setColorStrip1(strip1.Color(0,185,70));
    setColorStrip2(strip2.Color(0,185,70));
    setColorStrip3(strip3.Color(0,185,70));
    setColorStrip4(strip4.Color(0,185,70));
    setColorStrip5(strip5.Color(0,185,70));
    break;
case 131:
    setColorStrip1(strip1.Color(0,182,72));
    setColorStrip2(strip2.Color(0,182,72));
    setColorStrip3(strip3.Color(0,182,72));
    setColorStrip4(strip4.Color(0,182,72));
    setColorStrip5(strip5.Color(0,182,72));
    break;
case 132:
    setColorStrip1(strip1.Color(0,180,75));
    setColorStrip2(strip2.Color(0,180,75));
    setColorStrip3(strip3.Color(0,180,75));
    setColorStrip4(strip4.Color(0,180,75));
    setColorStrip5(strip5.Color(0,180,75));
    break;
case 133:
    setColorStrip1(strip1.Color(0,177,77));
    setColorStrip2(strip2.Color(0,177,77));
    setColorStrip3(strip3.Color(0,177,77));
    setColorStrip4(strip4.Color(0,177,77));
    setColorStrip5(strip5.Color(0,177,77));
    break;
case 134:
    setColorStrip1(strip1.Color(0,175,80));
    setColorStrip2(strip2.Color(0,175,80));
    setColorStrip3(strip3.Color(0,175,80));
    setColorStrip4(strip4.Color(0,175,80));
    setColorStrip5(strip5.Color(0,175,80));
    break;
case 135:
    setColorStrip1(strip1.Color(0,172,82));
    setColorStrip2(strip2.Color(0,172,82));
    setColorStrip3(strip3.Color(0,172,82));
    setColorStrip4(strip4.Color(0,172,82));
    setColorStrip5(strip5.Color(0,172,82));
    break;
case 136:
    setColorStrip1(strip1.Color(0,170,85));
    setColorStrip2(strip2.Color(0,170,85));
    setColorStrip3(strip3.Color(0,170,85));
    setColorStrip4(strip4.Color(0,170,85));
    setColorStrip5(strip5.Color(0,170,85));
    break;
case 137:
    setColorStrip1(strip1.Color(0,167,87));
    setColorStrip2(strip2.Color(0,167,87));
    setColorStrip3(strip3.Color(0,167,87));
    setColorStrip4(strip4.Color(0,167,87));
    setColorStrip5(strip5.Color(0,167,87));
    break;
case 138:
    setColorStrip1(strip1.Color(0,165,90));
    setColorStrip2(strip2.Color(0,165,90));
    setColorStrip3(strip3.Color(0,165,90));
    setColorStrip4(strip4.Color(0,165,90));
    setColorStrip5(strip5.Color(0,165,90));
    break;
case 139:
    setColorStrip1(strip1.Color(0,162,92));
    setColorStrip2(strip2.Color(0,162,92));
    setColorStrip3(strip3.Color(0,162,92));
    setColorStrip4(strip4.Color(0,162,92));
    setColorStrip5(strip5.Color(0,162,92));
    break;
case 140:
    setColorStrip1(strip1.Color(0,160,95));
    setColorStrip2(strip2.Color(0,160,95));
    setColorStrip3(strip3.Color(0,160,95));
    setColorStrip4(strip4.Color(0,160,95));
    setColorStrip5(strip5.Color(0,160,95));
    break;
case 141:
    setColorStrip1(strip1.Color(0,157,97));
    setColorStrip2(strip2.Color(0,157,97));
    setColorStrip3(strip3.Color(0,157,97));
    setColorStrip4(strip4.Color(0,157,97));
    setColorStrip5(strip5.Color(0,157,97));
    break;
case 142:
    setColorStrip1(strip1.Color(0,155,100));
    setColorStrip2(strip2.Color(0,155,100));
    setColorStrip3(strip3.Color(0,155,100));
    setColorStrip4(strip4.Color(0,155,100));
    setColorStrip5(strip5.Color(0,155,100));
    break;
case 143:
    setColorStrip1(strip1.Color(0,152,102));
    setColorStrip2(strip2.Color(0,152,102));
    setColorStrip3(strip3.Color(0,152,102));
    setColorStrip4(strip4.Color(0,152,102));
    setColorStrip5(strip5.Color(0,152,102));
    break;
case 144:
    setColorStrip1(strip1.Color(0,150,105));
    setColorStrip2(strip2.Color(0,150,105));
    setColorStrip3(strip3.Color(0,150,105));
    setColorStrip4(strip4.Color(0,150,105));
    setColorStrip5(strip5.Color(0,150,105));
    break;
case 145:
    setColorStrip1(strip1.Color(0,147,107));
    setColorStrip2(strip2.Color(0,147,107));
    setColorStrip3(strip3.Color(0,147,107));
    setColorStrip4(strip4.Color(0,147,107));
    setColorStrip5(strip5.Color(0,147,107));
    break;
case 146:
    setColorStrip1(strip1.Color(0,145,110));
    setColorStrip2(strip2.Color(0,145,110));
    setColorStrip3(strip3.Color(0,145,110));
    setColorStrip4(strip4.Color(0,145,110));
    setColorStrip5(strip5.Color(0,145,110));
    break;
case 147:
    setColorStrip1(strip1.Color(0,142,112));
    setColorStrip2(strip2.Color(0,142,112));
    setColorStrip3(strip3.Color(0,142,112));
    setColorStrip4(strip4.Color(0,142,112));
    setColorStrip5(strip5.Color(0,142,112));
    break;
case 148:
    setColorStrip1(strip1.Color(0,140,115));
    setColorStrip2(strip2.Color(0,140,115));
    setColorStrip3(strip3.Color(0,140,115));
    setColorStrip4(strip4.Color(0,140,115));
    setColorStrip5(strip5.Color(0,140,115));
    break;
case 149:
    setColorStrip1(strip1.Color(0,137,117));
    setColorStrip2(strip2.Color(0,137,117));
    setColorStrip3(strip3.Color(0,137,117));
    setColorStrip4(strip4.Color(0,137,117));
    setColorStrip5(strip5.Color(0,137,117));
    break;
case 150:
    setColorStrip1(strip1.Color(0,135,120));
    setColorStrip2(strip2.Color(0,135,120));
    setColorStrip3(strip3.Color(0,135,120));
    setColorStrip4(strip4.Color(0,135,120));
    setColorStrip5(strip5.Color(0,135,120));
    break;
case 151:
    setColorStrip1(strip1.Color(0,132,122));
    setColorStrip2(strip2.Color(0,132,122));
    setColorStrip3(strip3.Color(0,132,122));
    setColorStrip4(strip4.Color(0,132,122));
    setColorStrip5(strip5.Color(0,132,122));
    break;
case 152:
    setColorStrip1(strip1.Color(0,130,125));
    setColorStrip2(strip2.Color(0,130,125));
    setColorStrip3(strip3.Color(0,130,125));
    setColorStrip4(strip4.Color(0,130,125));
    setColorStrip5(strip5.Color(0,130,125));
    break;
case 153:
    setColorStrip1(strip1.Color(0,127,127));
    setColorStrip2(strip2.Color(0,127,127));
    setColorStrip3(strip3.Color(0,127,127));
    setColorStrip4(strip4.Color(0,127,127));
    setColorStrip5(strip5.Color(0,127,127));
    break;
case 154:
    setColorStrip1(strip1.Color(0,125,130));
    setColorStrip2(strip2.Color(0,125,130));
    setColorStrip3(strip3.Color(0,125,130));
    setColorStrip4(strip4.Color(0,125,130));
    setColorStrip5(strip5.Color(0,125,130));
    break;
case 155:
    setColorStrip1(strip1.Color(0,122,132));
    setColorStrip2(strip2.Color(0,122,132));
    setColorStrip3(strip3.Color(0,122,132));
    setColorStrip4(strip4.Color(0,122,132));
    setColorStrip5(strip5.Color(0,122,132));
    break;
case 156:
    setColorStrip1(strip1.Color(0,120,135));
    setColorStrip2(strip2.Color(0,120,135));
    setColorStrip3(strip3.Color(0,120,135));
    setColorStrip4(strip4.Color(0,120,135));
    setColorStrip5(strip5.Color(0,120,135));
    break;
case 157:
    setColorStrip1(strip1.Color(0,117,137));
    setColorStrip2(strip2.Color(0,117,137));
    setColorStrip3(strip3.Color(0,117,137));
    setColorStrip4(strip4.Color(0,117,137));
    setColorStrip5(strip5.Color(0,117,137));
    break;
case 158:
    setColorStrip1(strip1.Color(0,115,140));
    setColorStrip2(strip2.Color(0,115,140));
    setColorStrip3(strip3.Color(0,115,140));
    setColorStrip4(strip4.Color(0,115,140));
    setColorStrip5(strip5.Color(0,115,140));
    break;
case 159:
    setColorStrip1(strip1.Color(0,112,142));
    setColorStrip2(strip2.Color(0,112,142));
    setColorStrip3(strip3.Color(0,112,142));
    setColorStrip4(strip4.Color(0,112,142));
    setColorStrip5(strip5.Color(0,112,142));
    break;
case 160:
    setColorStrip1(strip1.Color(0,110,145));
    setColorStrip2(strip2.Color(0,110,145));
    setColorStrip3(strip3.Color(0,110,145));
    setColorStrip4(strip4.Color(0,110,145));
    setColorStrip5(strip5.Color(0,110,145));
    break;
case 161:
    setColorStrip1(strip1.Color(0,107,147));
    setColorStrip2(strip2.Color(0,107,147));
    setColorStrip3(strip3.Color(0,107,147));
    setColorStrip4(strip4.Color(0,107,147));
    setColorStrip5(strip5.Color(0,107,147));
    break;
case 162:
    setColorStrip1(strip1.Color(0,105,150));
    setColorStrip2(strip2.Color(0,105,150));
    setColorStrip3(strip3.Color(0,105,150));
    setColorStrip4(strip4.Color(0,105,150));
    setColorStrip5(strip5.Color(0,105,150));
    break;
case 163:
    setColorStrip1(strip1.Color(0,102,152));
    setColorStrip2(strip2.Color(0,102,152));
    setColorStrip3(strip3.Color(0,102,152));
    setColorStrip4(strip4.Color(0,102,152));
    setColorStrip5(strip5.Color(0,102,152));
    break;
case 164:
    setColorStrip1(strip1.Color(0,100,155));
    setColorStrip2(strip2.Color(0,100,155));
    setColorStrip3(strip3.Color(0,100,155));
    setColorStrip4(strip4.Color(0,100,155));
    setColorStrip5(strip5.Color(0,100,155));
    break;
case 165:
    setColorStrip1(strip1.Color(0,97, 157));
    setColorStrip2(strip2.Color(0,97, 157));
    setColorStrip3(strip3.Color(0,97, 157));
    setColorStrip4(strip4.Color(0,97, 157));
    setColorStrip5(strip5.Color(0,97, 157));
    break;
case 166:
    setColorStrip1(strip1.Color(0,95, 160));
    setColorStrip2(strip2.Color(0,95, 160));
    setColorStrip3(strip3.Color(0,95, 160));
    setColorStrip4(strip4.Color(0,95, 160));
    setColorStrip5(strip5.Color(0,95, 160));
    break; 
case 167: 
    setColorStrip1(strip1.Color(0,92, 162));
    setColorStrip2(strip2.Color(0,92, 162));
    setColorStrip3(strip3.Color(0,92, 162));
    setColorStrip4(strip4.Color(0,92, 162));
    setColorStrip5(strip5.Color(0,92, 162));
    break; 
case 168: 
    setColorStrip1(strip1.Color(0,90, 165));
    setColorStrip2(strip2.Color(0,90, 165));
    setColorStrip3(strip3.Color(0,90, 165));
    setColorStrip4(strip4.Color(0,90, 165));
    setColorStrip5(strip5.Color(0,90, 165));
    break;
case 169:
    setColorStrip1(strip1.Color(0,87, 167));
    setColorStrip2(strip2.Color(0,87, 167));
    setColorStrip3(strip3.Color(0,87, 167));
    setColorStrip4(strip4.Color(0,87, 167));
    setColorStrip5(strip5.Color(0,87, 167));
    break;
case 170:
    setColorStrip1(strip1.Color(0,85, 170));
    setColorStrip2(strip2.Color(0,85, 170));
    setColorStrip3(strip3.Color(0,85, 170));
    setColorStrip4(strip4.Color(0,85, 170));
    setColorStrip5(strip5.Color(0,85, 170));
    break; 
case 171: 
    setColorStrip1(strip1.Color(0,82, 172));
    setColorStrip2(strip2.Color(0,82, 172));
    setColorStrip3(strip3.Color(0,82, 172));
    setColorStrip4(strip4.Color(0,82, 172));
    setColorStrip5(strip5.Color(0,82, 172));
    break; 
case 172: 
    setColorStrip1(strip1.Color(0,80, 175));
    setColorStrip2(strip2.Color(0,80, 175));
    setColorStrip3(strip3.Color(0,80, 175));
    setColorStrip4(strip4.Color(0,80, 175));
    setColorStrip5(strip5.Color(0,80, 175));
    break;
case 173:
    setColorStrip1(strip1.Color(0,77, 177));
    setColorStrip2(strip2.Color(0,77, 177));
    setColorStrip3(strip3.Color(0,77, 177));
    setColorStrip4(strip4.Color(0,77, 177));
    setColorStrip5(strip5.Color(0,77, 177));
    break;
case 174:
    setColorStrip1(strip1.Color(0,75, 180));
    setColorStrip2(strip2.Color(0,75, 180));
    setColorStrip3(strip3.Color(0,75, 180));
    setColorStrip4(strip4.Color(0,75, 180));
    setColorStrip5(strip5.Color(0,75, 180));
    break; 
case 175: 
    setColorStrip1(strip1.Color(0,72, 182));
    setColorStrip2(strip2.Color(0,72, 182));
    setColorStrip3(strip3.Color(0,72, 182));
    setColorStrip4(strip4.Color(0,72, 182));
    setColorStrip5(strip5.Color(0,72, 182));
    break; 
case 176: 
    setColorStrip1(strip1.Color(0,70, 185));
    setColorStrip2(strip2.Color(0,70, 185));
    setColorStrip3(strip3.Color(0,70, 185));
    setColorStrip4(strip4.Color(0,70, 185));
    setColorStrip5(strip5.Color(0,70, 185));
    break;
case 177:
    setColorStrip1(strip1.Color(0,67, 187));
    setColorStrip2(strip2.Color(0,67, 187));
    setColorStrip3(strip3.Color(0,67, 187));
    setColorStrip4(strip4.Color(0,67, 187));
    setColorStrip5(strip5.Color(0,67, 187));
    break;
case 178:
    setColorStrip1(strip1.Color(0,65, 190));
    setColorStrip2(strip2.Color(0,65, 190));
    setColorStrip3(strip3.Color(0,65, 190));
    setColorStrip4(strip4.Color(0,65, 190));
    setColorStrip5(strip5.Color(0,65, 190));
    break; 
case 179: 
    setColorStrip1(strip1.Color(0,62, 192));
    setColorStrip2(strip2.Color(0,62, 192));
    setColorStrip3(strip3.Color(0,62, 192));
    setColorStrip4(strip4.Color(0,62, 192));
    setColorStrip5(strip5.Color(0,62, 192));
    break; 
case 180: 
    setColorStrip1(strip1.Color(0,60, 195));
    setColorStrip2(strip2.Color(0,60, 195));
    setColorStrip3(strip3.Color(0,60, 195));
    setColorStrip4(strip4.Color(0,60, 195));
    setColorStrip5(strip5.Color(0,60, 195));
    break;
case 181:
    setColorStrip1(strip1.Color(0,57, 197));
    setColorStrip2(strip2.Color(0,57, 197));
    setColorStrip3(strip3.Color(0,57, 197));
    setColorStrip4(strip4.Color(0,57, 197));
    setColorStrip5(strip5.Color(0,57, 197));
    break;
case 182:
    setColorStrip1(strip1.Color(0,55, 200));
    setColorStrip2(strip2.Color(0,55, 200));
    setColorStrip3(strip3.Color(0,55, 200));
    setColorStrip4(strip4.Color(0,55, 200));
    setColorStrip5(strip5.Color(0,55, 200));
    break; 
case 183: 
    setColorStrip1(strip1.Color(0,52, 202));
    setColorStrip2(strip2.Color(0,52, 202));
    setColorStrip3(strip3.Color(0,52, 202));
    setColorStrip4(strip4.Color(0,52, 202));
    setColorStrip5(strip5.Color(0,52, 202));
    break; 
case 184: 
    setColorStrip1(strip1.Color(0,50, 205));
    setColorStrip2(strip2.Color(0,50, 205));
    setColorStrip3(strip3.Color(0,50, 205));
    setColorStrip4(strip4.Color(0,50, 205));
    setColorStrip5(strip5.Color(0,50, 205));
    break;
case 185:
    setColorStrip1(strip1.Color(0,47, 207));
    setColorStrip2(strip2.Color(0,47, 207));
    setColorStrip3(strip3.Color(0,47, 207));
    setColorStrip4(strip4.Color(0,47, 207));
    setColorStrip5(strip5.Color(0,47, 207));
    break;
case 186:
    setColorStrip1(strip1.Color(0,45, 210));
    setColorStrip2(strip2.Color(0,45, 210));
    setColorStrip3(strip3.Color(0,45, 210));
    setColorStrip4(strip4.Color(0,45, 210));
    setColorStrip5(strip5.Color(0,45, 210));
    break; 
case 187: 
    setColorStrip1(strip1.Color(0,42, 212));
    setColorStrip2(strip2.Color(0,42, 212));
    setColorStrip3(strip3.Color(0,42, 212));
    setColorStrip4(strip4.Color(0,42, 212));
    setColorStrip5(strip5.Color(0,42, 212));
    break; 
case 188: 
    setColorStrip1(strip1.Color(0,40, 215));
    setColorStrip2(strip2.Color(0,40, 215));
    setColorStrip3(strip3.Color(0,40, 215));
    setColorStrip4(strip4.Color(0,40, 215));
    setColorStrip5(strip5.Color(0,40, 215));
    break;
case 189:
    setColorStrip1(strip1.Color(0,37, 217));
    setColorStrip2(strip2.Color(0,37, 217));
    setColorStrip3(strip3.Color(0,37, 217));
    setColorStrip4(strip4.Color(0,37, 217));
    setColorStrip5(strip5.Color(0,37, 217));
    break;
case 190:
    setColorStrip1(strip1.Color(0,35, 220));
    setColorStrip2(strip2.Color(0,35, 220));
    setColorStrip3(strip3.Color(0,35, 220));
    setColorStrip4(strip4.Color(0,35, 220));
    setColorStrip5(strip5.Color(0,35, 220));
    break; 
case 191: 
    setColorStrip1(strip1.Color(0,32, 222));
    setColorStrip2(strip2.Color(0,32, 222));
    setColorStrip3(strip3.Color(0,32, 222));
    setColorStrip4(strip4.Color(0,32, 222));
    setColorStrip5(strip5.Color(0,32, 222));
    break; 
case 192: 
    setColorStrip1(strip1.Color(0,30, 225));
    setColorStrip2(strip2.Color(0,30, 225));
    setColorStrip3(strip3.Color(0,30, 225));
    setColorStrip4(strip4.Color(0,30, 225));
    setColorStrip5(strip5.Color(0,30, 225));
    break;
case 193:
    setColorStrip1(strip1.Color(0,27, 227));
    setColorStrip2(strip2.Color(0,27, 227));
    setColorStrip3(strip3.Color(0,27, 227));
    setColorStrip4(strip4.Color(0,27, 227));
    setColorStrip5(strip5.Color(0,27, 227));
    break;
case 194:
    setColorStrip1(strip1.Color(0,25, 230));
    setColorStrip2(strip2.Color(0,25, 230));
    setColorStrip3(strip3.Color(0,25, 230));
    setColorStrip4(strip4.Color(0,25, 230));
    setColorStrip5(strip5.Color(0,25, 230));
    break; 
case 195: 
    setColorStrip1(strip1.Color(0,22, 232));
    setColorStrip2(strip2.Color(0,22, 232));
    setColorStrip3(strip3.Color(0,22, 232));
    setColorStrip4(strip4.Color(0,22, 232));
    setColorStrip5(strip5.Color(0,22, 232));
    break; 
case 196: 
    setColorStrip1(strip1.Color(0,20, 235));
    setColorStrip2(strip2.Color(0,20, 235));
    setColorStrip3(strip3.Color(0,20, 235));
    setColorStrip4(strip4.Color(0,20, 235));
    setColorStrip5(strip5.Color(0,20, 235));
    break;
case 197:
    setColorStrip1(strip1.Color(0,17, 237));
    setColorStrip2(strip2.Color(0,17, 237));
    setColorStrip3(strip3.Color(0,17, 237));
    setColorStrip4(strip4.Color(0,17, 237));
    setColorStrip5(strip5.Color(0,17, 237));
    break;
case 198:
    setColorStrip1(strip1.Color(0,15, 240));
    setColorStrip2(strip2.Color(0,15, 240));
    setColorStrip3(strip3.Color(0,15, 240));
    setColorStrip4(strip4.Color(0,15, 240));
    setColorStrip5(strip5.Color(0,15, 240));
    break; 
case 199: 
    setColorStrip1(strip1.Color(0,12, 242));
    setColorStrip2(strip2.Color(0,12, 242));
    setColorStrip3(strip3.Color(0,12, 242));
    setColorStrip4(strip4.Color(0,12, 242));
    setColorStrip5(strip5.Color(0,12, 242));
    break; 
case 200: 
    setColorStrip1(strip1.Color(0,10, 245));
    setColorStrip2(strip2.Color(0,10, 245));
    setColorStrip3(strip3.Color(0,10, 245));
    setColorStrip4(strip4.Color(0,10, 245));
    setColorStrip5(strip5.Color(0,10, 245));
    break;
case 201:
    setColorStrip1(strip1.Color(0,7, 247));
    setColorStrip2(strip2.Color(0,7, 247));
    setColorStrip3(strip3.Color(0,7, 247));
    setColorStrip4(strip4.Color(0,7, 247));
    setColorStrip5(strip5.Color(0,7, 247));
    break;
case 202:
    setColorStrip1(strip1.Color(0,5, 250));
    setColorStrip2(strip2.Color(0,5, 250));
    setColorStrip3(strip3.Color(0,5, 250));
    setColorStrip4(strip4.Color(0,5, 250));
    setColorStrip5(strip5.Color(0,5, 250));
    break; 
case 203: 
    setColorStrip1(strip1.Color(0,2, 252));
    setColorStrip2(strip2.Color(0,2, 252));
    setColorStrip3(strip3.Color(0,2, 252));
    setColorStrip4(strip4.Color(0,2, 252));
    setColorStrip5(strip5.Color(0,2, 252));
    break; 
case 204: 
    setColorStrip1(strip1.Color(0,0, 255));
    setColorStrip2(strip2.Color(0,0, 255));
    setColorStrip3(strip3.Color(0,0, 255));
    setColorStrip4(strip4.Color(0,0, 255));
    setColorStrip5(strip5.Color(0,0, 255));
    break;
case 205:
    setColorStrip1(strip1.Color(2,0, 253));
    setColorStrip2(strip2.Color(2,0, 253));
    setColorStrip3(strip3.Color(2,0, 253));
    setColorStrip4(strip4.Color(2,0, 253));
    setColorStrip5(strip5.Color(2,0, 253));
    break; 
case 206: 
    setColorStrip1(strip1.Color(5,0, 250));
    setColorStrip2(strip2.Color(5,0, 250));
    setColorStrip3(strip3.Color(5,0, 250));
    setColorStrip4(strip4.Color(5,0, 250));
    setColorStrip5(strip5.Color(5,0, 250));
    break; 
case 207: 
    setColorStrip1(strip1.Color(7,0, 248));
    setColorStrip2(strip2.Color(7,0, 248));
    setColorStrip3(strip3.Color(7,0, 248));
    setColorStrip4(strip4.Color(7,0, 248));
    setColorStrip5(strip5.Color(7,0, 248));
    break;
case 208:
    setColorStrip1(strip1.Color(10,0,245));
    setColorStrip2(strip2.Color(10,0,245));
    setColorStrip3(strip3.Color(10,0,245));
    setColorStrip4(strip4.Color(10,0,245));
    setColorStrip5(strip5.Color(10,0,245));
    break;
case 209:
    setColorStrip1(strip1.Color(12,0,243));
    setColorStrip2(strip2.Color(12,0,243));
    setColorStrip3(strip3.Color(12,0,243));
    setColorStrip4(strip4.Color(12,0,243));
    setColorStrip5(strip5.Color(12,0,243));
    break;
case 210:
    setColorStrip1(strip1.Color(15,0,240));
    setColorStrip2(strip2.Color(15,0,240));
    setColorStrip3(strip3.Color(15,0,240));
    setColorStrip4(strip4.Color(15,0,240));
    setColorStrip5(strip5.Color(15,0,240));
    break;
case 211:
    setColorStrip1(strip1.Color(17,0,238));
    setColorStrip2(strip2.Color(17,0,238));
    setColorStrip3(strip3.Color(17,0,238));
    setColorStrip4(strip4.Color(17,0,238));
    setColorStrip5(strip5.Color(17,0,238));
    break;
case 212:
    setColorStrip1(strip1.Color(20,0,235));
    setColorStrip2(strip2.Color(20,0,235));
    setColorStrip3(strip3.Color(20,0,235));
    setColorStrip4(strip4.Color(20,0,235));
    setColorStrip5(strip5.Color(20,0,235));
    break;
case 213:
    setColorStrip1(strip1.Color(22,0,233));
    setColorStrip2(strip2.Color(22,0,233));
    setColorStrip3(strip3.Color(22,0,233));
    setColorStrip4(strip4.Color(22,0,233));
    setColorStrip5(strip5.Color(22,0,233));
    break; 
case 214: 
    setColorStrip1(strip1.Color(25,0,230));
    setColorStrip2(strip2.Color(25,0,230));
    setColorStrip3(strip3.Color(25,0,230));
    setColorStrip4(strip4.Color(25,0,230));
    setColorStrip5(strip5.Color(25,0,230));
    break; 
case 215: 
    setColorStrip1(strip1.Color(27,0,228));
    setColorStrip2(strip2.Color(27,0,228));
    setColorStrip3(strip3.Color(27,0,228));
    setColorStrip4(strip4.Color(27,0,228));
    setColorStrip5(strip5.Color(27,0,228));
    break;
case 216:
    setColorStrip1(strip1.Color(30,0,225));
    setColorStrip2(strip2.Color(30,0,225));
    setColorStrip3(strip3.Color(30,0,225));
    setColorStrip4(strip4.Color(30,0,225));
    setColorStrip5(strip5.Color(30,0,225));
    break;
case 217:
    setColorStrip1(strip1.Color(32,0,223));
    setColorStrip2(strip2.Color(32,0,223));
    setColorStrip3(strip3.Color(32,0,223));
    setColorStrip4(strip4.Color(32,0,223));
    setColorStrip5(strip5.Color(32,0,223));
    break; 
case 218: 
    setColorStrip1(strip1.Color(35,0,220));
    setColorStrip2(strip2.Color(35,0,220));
    setColorStrip3(strip3.Color(35,0,220));
    setColorStrip4(strip4.Color(35,0,220));
    setColorStrip5(strip5.Color(35,0,220));
    break; 
case 219: 
    setColorStrip1(strip1.Color(37,0,218));
    setColorStrip2(strip2.Color(37,0,218));
    setColorStrip3(strip3.Color(37,0,218));
    setColorStrip4(strip4.Color(37,0,218));
    setColorStrip5(strip5.Color(37,0,218));
    break;
case 220:
    setColorStrip1(strip1.Color(40,0,215));
    setColorStrip2(strip2.Color(40,0,215));
    setColorStrip3(strip3.Color(40,0,215));
    setColorStrip4(strip4.Color(40,0,215));
    setColorStrip5(strip5.Color(40,0,215));
    break;
case 221:
    setColorStrip1(strip1.Color(42,0,213));
    setColorStrip2(strip2.Color(42,0,213));
    setColorStrip3(strip3.Color(42,0,213));
    setColorStrip4(strip4.Color(42,0,213));
    setColorStrip5(strip5.Color(42,0,213));
    break; 
case 222: 
    setColorStrip1(strip1.Color(45,0,210));
    setColorStrip2(strip2.Color(45,0,210));
    setColorStrip3(strip3.Color(45,0,210));
    setColorStrip4(strip4.Color(45,0,210));
    setColorStrip5(strip5.Color(45,0,210));
    break; 
case 223: 
    setColorStrip1(strip1.Color(47,0,208));
    setColorStrip2(strip2.Color(47,0,208));
    setColorStrip3(strip3.Color(47,0,208));
    setColorStrip4(strip4.Color(47,0,208));
    setColorStrip5(strip5.Color(47,0,208));
    break;
case 224:
    setColorStrip1(strip1.Color(50,0,205));
    setColorStrip2(strip2.Color(50,0,205));
    setColorStrip3(strip3.Color(50,0,205));
    setColorStrip4(strip4.Color(50,0,205));
    setColorStrip5(strip5.Color(50,0,205));
    break;
case 225:
    setColorStrip1(strip1.Color(52,0,203));
    setColorStrip2(strip2.Color(52,0,203));
    setColorStrip3(strip3.Color(52,0,203));
    setColorStrip4(strip4.Color(52,0,203));
    setColorStrip5(strip5.Color(52,0,203));
    break; 
case 226: 
    setColorStrip1(strip1.Color(55,0,200));
    setColorStrip2(strip2.Color(55,0,200));
    setColorStrip3(strip3.Color(55,0,200));
    setColorStrip4(strip4.Color(55,0,200));
    setColorStrip5(strip5.Color(55,0,200));
    break; 
case 227: 
    setColorStrip1(strip1.Color(57,0,198));
    setColorStrip2(strip2.Color(57,0,198));
    setColorStrip3(strip3.Color(57,0,198));
    setColorStrip4(strip4.Color(57,0,198));
    setColorStrip5(strip5.Color(57,0,198));
    break;
case 228:
    setColorStrip1(strip1.Color(60,0,195));
    setColorStrip2(strip2.Color(60,0,195));
    setColorStrip3(strip3.Color(60,0,195));
    setColorStrip4(strip4.Color(60,0,195));
    setColorStrip5(strip5.Color(60,0,195));
    break;
case 229:
    setColorStrip1(strip1.Color(62,0,193));
    setColorStrip2(strip2.Color(62,0,193));
    setColorStrip3(strip3.Color(62,0,193));
    setColorStrip4(strip4.Color(62,0,193));
    setColorStrip5(strip5.Color(62,0,193));
    break; 
case 230: 
    setColorStrip1(strip1.Color(65,0,190));
    setColorStrip2(strip2.Color(65,0,190));
    setColorStrip3(strip3.Color(65,0,190));
    setColorStrip4(strip4.Color(65,0,190));
    setColorStrip5(strip5.Color(65,0,190));
    break; 
case 231: 
    setColorStrip1(strip1.Color(67,0,188));
    setColorStrip2(strip2.Color(67,0,188));
    setColorStrip3(strip3.Color(67,0,188));
    setColorStrip4(strip4.Color(67,0,188));
    setColorStrip5(strip5.Color(67,0,188));
    break;
case 232:
    setColorStrip1(strip1.Color(70,0,185));
    setColorStrip2(strip2.Color(70,0,185));
    setColorStrip3(strip3.Color(70,0,185));
    setColorStrip4(strip4.Color(70,0,185));
    setColorStrip5(strip5.Color(70,0,185));
    break;
case 233:
    setColorStrip1(strip1.Color(72,0,183));
    setColorStrip2(strip2.Color(72,0,183));
    setColorStrip3(strip3.Color(72,0,183));
    setColorStrip4(strip4.Color(72,0,183));
    setColorStrip5(strip5.Color(72,0,183));
    break; 
case 234: 
    setColorStrip1(strip1.Color(75,0,180));
    setColorStrip2(strip2.Color(75,0,180));
    setColorStrip3(strip3.Color(75,0,180));
    setColorStrip4(strip4.Color(75,0,180));
    setColorStrip5(strip5.Color(75,0,180));
    break; 
case 235: 
    setColorStrip1(strip1.Color(77,0,178));
    setColorStrip2(strip2.Color(77,0,178));
    setColorStrip3(strip3.Color(77,0,178));
    setColorStrip4(strip4.Color(77,0,178));
    setColorStrip5(strip5.Color(77,0,178));
    break;
case 236:
    setColorStrip1(strip1.Color(80,0,175));
    setColorStrip2(strip2.Color(80,0,175));
    setColorStrip3(strip3.Color(80,0,175));
    setColorStrip4(strip4.Color(80,0,175));
    setColorStrip5(strip5.Color(80,0,175));
    break;
case 237:
    setColorStrip1(strip1.Color(82,0,173));
    setColorStrip2(strip2.Color(82,0,173));
    setColorStrip3(strip3.Color(82,0,173));
    setColorStrip4(strip4.Color(82,0,173));
    setColorStrip5(strip5.Color(82,0,173));
    break; 
case 238: 
    setColorStrip1(strip1.Color(85,0,170));
    setColorStrip2(strip2.Color(85,0,170));
    setColorStrip3(strip3.Color(85,0,170));
    setColorStrip4(strip4.Color(85,0,170));
    setColorStrip5(strip5.Color(85,0,170));
    break; 
case 239: 
    setColorStrip1(strip1.Color(87,0,168));
    setColorStrip2(strip2.Color(87,0,168));
    setColorStrip3(strip3.Color(87,0,168));
    setColorStrip4(strip4.Color(87,0,168));
    setColorStrip5(strip5.Color(87,0,168));
    break;
case 240:
    setColorStrip1(strip1.Color(90,0,165));
    setColorStrip2(strip2.Color(90,0,165));
    setColorStrip3(strip3.Color(90,0,165));
    setColorStrip4(strip4.Color(90,0,165));
    setColorStrip5(strip5.Color(90,0,165));
    break;
case 241:
    setColorStrip1(strip1.Color(92,0,163));
    setColorStrip2(strip2.Color(92,0,163));
    setColorStrip3(strip3.Color(92,0,163));
    setColorStrip4(strip4.Color(92,0,163));
    setColorStrip5(strip5.Color(92,0,163));
    break; 
case 242: 
    setColorStrip1(strip1.Color(95,0,160));
    setColorStrip2(strip2.Color(95,0,160));
    setColorStrip3(strip3.Color(95,0,160));
    setColorStrip4(strip4.Color(95,0,160));
    setColorStrip5(strip5.Color(95,0,160));
    break; 
case 243: 
    setColorStrip1(strip1.Color(97,0,168));
    setColorStrip2(strip2.Color(97,0,168));
    setColorStrip3(strip3.Color(97,0,168));
    setColorStrip4(strip4.Color(97,0,168));
    setColorStrip5(strip5.Color(97,0,168));
    break;
case 244:
    setColorStrip1(strip1.Color(100,0,155));
    setColorStrip2(strip2.Color(100,0,155));
    setColorStrip3(strip3.Color(100,0,155));
    setColorStrip4(strip4.Color(100,0,155));
    setColorStrip5(strip5.Color(100,0,155));
    break;
case 245:
    setColorStrip1(strip1.Color(102,0,153));
    setColorStrip2(strip2.Color(102,0,153));
    setColorStrip3(strip3.Color(102,0,153));
    setColorStrip4(strip4.Color(102,0,153));
    setColorStrip5(strip5.Color(102,0,153));
    break; 
case 246: 
    setColorStrip1(strip1.Color(105,0,150));
    setColorStrip2(strip2.Color(105,0,150));
    setColorStrip3(strip3.Color(105,0,150));
    setColorStrip4(strip4.Color(105,0,150));
    setColorStrip5(strip5.Color(105,0,150));
    break; 
case 247: 
    setColorStrip1(strip1.Color(107,0,148));
    setColorStrip2(strip2.Color(107,0,148));
    setColorStrip3(strip3.Color(107,0,148));
    setColorStrip4(strip4.Color(107,0,148));
    setColorStrip5(strip5.Color(107,0,148));
    break;
case 248:
    setColorStrip1(strip1.Color(110,0,145));
    setColorStrip2(strip2.Color(110,0,145));
    setColorStrip3(strip3.Color(110,0,145));
    setColorStrip4(strip4.Color(110,0,145));
    setColorStrip5(strip5.Color(110,0,145));
    break;
case 249:
    setColorStrip1(strip1.Color(112,0,143));
    setColorStrip2(strip2.Color(112,0,143));
    setColorStrip3(strip3.Color(112,0,143));
    setColorStrip4(strip4.Color(112,0,143));
    setColorStrip5(strip5.Color(112,0,143));
    break; 
case 250: 
    setColorStrip1(strip1.Color(115,0,140));
    setColorStrip2(strip2.Color(115,0,140));
    setColorStrip3(strip3.Color(115,0,140));
    setColorStrip4(strip4.Color(115,0,140));
    setColorStrip5(strip5.Color(115,0,140));
    break; 
case 251: 
    setColorStrip1(strip1.Color(117,0,138));
    setColorStrip2(strip2.Color(117,0,138));
    setColorStrip3(strip3.Color(117,0,138));
    setColorStrip4(strip4.Color(117,0,138));
    setColorStrip5(strip5.Color(117,0,138));
    break;
case 252:
    setColorStrip1(strip1.Color(120,0,135));
    setColorStrip2(strip2.Color(120,0,135));
    setColorStrip3(strip3.Color(120,0,135));
    setColorStrip4(strip4.Color(120,0,135));
    setColorStrip5(strip5.Color(120,0,135));
    break;
case 253:
    setColorStrip1(strip1.Color(122,0,133));
    setColorStrip2(strip2.Color(122,0,133));
    setColorStrip3(strip3.Color(122,0,133));
    setColorStrip4(strip4.Color(122,0,133));
    setColorStrip5(strip5.Color(122,0,133));
    break; 
case 254: 
    setColorStrip1(strip1.Color(125,0,130));
    setColorStrip2(strip2.Color(125,0,130));
    setColorStrip3(strip3.Color(125,0,130));
    setColorStrip4(strip4.Color(125,0,130));
    setColorStrip5(strip5.Color(125,0,130));
    break; 
case 255: 
    setColorStrip1(strip1.Color(127,0,128));
    setColorStrip2(strip2.Color(127,0,128));
    setColorStrip3(strip3.Color(127,0,128));
    setColorStrip4(strip4.Color(127,0,128));
    setColorStrip5(strip5.Color(127,0,128));
    break;
    }
  }
}

// Write a Touch Potentiometer register
void WriteTpReg(uint8_t addr, uint8_t data) {
  Wire.beginTransmission(i2cAddr+1);
  Wire.write('W');
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

// Get the Touch Potentiometer value
uint8_t ReadTpValue() {
  Wire.requestFrom(i2cAddr, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    return 0;
  }
}

// Read a Touch Potentiometer register
uint8_t ReadTpReg(uint8_t addr) {
  Wire.beginTransmission(i2cAddr+1);
  Wire.write('R');
  Wire.write(addr);
  Wire.endTransmission();

  Wire.requestFrom(i2cAddr+1, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    return 0;
  }
}

void setColorStrip1(uint32_t color) {
//  for(int i=0;i<15;i++) {
//    strip1.setPixelColor(i,  color);
//  }
// MClem
  strip1.setPixelColor(0,  color);
  strip1.setPixelColor(2,  color);
  strip1.setPixelColor(4,  color);
  strip1.setPixelColor(5,  color);
  strip1.setPixelColor(7,  color);
  strip1.setPixelColor(9,  color);
  strip1.setPixelColor(10,  color);
  strip1.setPixelColor(12,  color);
  strip1.setPixelColor(14,  color);
// Jeff
//  strip1.setPixelColor(14,  color);
//  strip1.setPixelColor(13,  color);
//  strip1.setPixelColor(12,  color);
//  strip1.setPixelColor(10,  color);
//  strip1.setPixelColor(9,  color);
//  strip1.setPixelColor(8,  color);
//  strip1.setPixelColor(6,  color);
//  strip1.setPixelColor(5,  color);
//  strip1.setPixelColor(4,  color);
//  strip1.setPixelColor(2,  color);
//  strip1.setPixelColor(1,  color);
//  strip1.setPixelColor(0,  color);
  strip1.show();
}

void setColorStrip2(uint32_t color) {
// MClem
  strip2.setPixelColor(0,  color);
  strip2.setPixelColor(1,  color);
  strip2.setPixelColor(2,  color);
  strip2.setPixelColor(5,  color);
  strip2.setPixelColor(7,  color);
  strip2.setPixelColor(10,  color);
  strip2.setPixelColor(12,  color);
  strip2.setPixelColor(13,  color);
  strip2.setPixelColor(14,  color);
// Jeff
//  strip2.setPixelColor(13,  color);
//  strip2.setPixelColor(10,  color);
//  strip2.setPixelColor(6,  color);
//  strip2.setPixelColor(2,  color);
  strip2.show();
}

void setColorStrip3(uint32_t color) {
// MClem
  strip3.setPixelColor(0,  color);
  strip3.setPixelColor(2,  color);
  strip3.setPixelColor(4,  color);
  strip3.setPixelColor(5,  color);
  strip3.setPixelColor(7,  color);
  strip3.setPixelColor(10,  color);
  strip3.setPixelColor(12,  color);
  strip3.setPixelColor(14,  color);
// Jeff
//  strip3.setPixelColor(13,  color);
//  strip3.setPixelColor(10,  color);
//  strip3.setPixelColor(9,  color);
//  strip3.setPixelColor(8,  color);
//  strip3.setPixelColor(6,  color);
//  strip3.setPixelColor(5,  color);
//  strip3.setPixelColor(4,  color);
//  strip3.setPixelColor(2,  color);
//  strip3.setPixelColor(1,  color);
//  strip3.setPixelColor(0,  color);
  strip3.show();
}

void setColorStrip4(uint32_t color) {
// MClem
  strip4.setPixelColor(0,  color);
  strip4.setPixelColor(2,  color);
  strip4.setPixelColor(5,  color);
  strip4.setPixelColor(7,  color);
  strip4.setPixelColor(10,  color);
  strip4.setPixelColor(12,  color);
  strip4.setPixelColor(14,  color);
// Jeff
//  strip4.setPixelColor(13,  color);
//  strip4.setPixelColor(10,  color);
//  strip4.setPixelColor(6,  color);
//  strip4.setPixelColor(2,  color);
  strip4.show();
}

void setColorStrip5(uint32_t color) {
// MClem
  strip5.setPixelColor(0,  color);
  strip5.setPixelColor(2,  color);
  strip5.setPixelColor(4,  color);
  strip5.setPixelColor(5,  color);
  strip5.setPixelColor(7,  color);
  strip5.setPixelColor(9,  color);
  strip5.setPixelColor(10,  color);
  strip5.setPixelColor(12,  color);
  strip5.setPixelColor(14,  color);
// Jeff
//  strip5.setPixelColor(14,  color);
//  strip5.setPixelColor(13,  color);
//  strip5.setPixelColor(10,  color);
//  strip5.setPixelColor(9,  color);
//  strip5.setPixelColor(8,  color);
//  strip5.setPixelColor(6,  color);
//  strip5.setPixelColor(2,  color);
  strip5.show();
}

