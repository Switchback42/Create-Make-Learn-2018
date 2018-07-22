/*
lilypad_neopixel_play

You can find the original code that this sketch is based upon on the Way Back Machine at:
https://web.archive.org/web/20170228191434/http://www.electronicfashion.co.uk/workshop_checklists.htm

This sketch has been customized for the LilyPad
Please visit https://www.rapidtables.com/web/color/pink-color.html to find additional hexcodes for changing colors
*/

// Coding e-Textiles:  Create Make Learn 2018
// Presentation and Workshop by Jill Dawson

#include <Adafruit_NeoPixel.h>

#define PIN 5 // almost any pin would work here
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, PIN);
 
uint32_t color1 = 0xff000, // red  
         color2 = 0x00ff00, // green
         color3 = 0x0000ff; // blue
     
void setup() {
  pixels.begin();
  pixels.setBrightness(85);
}
 
void loop() {
    pixels.setPixelColor(0, color1);
    pixels.setPixelColor(1, color2);
    pixels.setPixelColor(2, color3);
    pixels.setPixelColor(3, color1);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
    pixels.setPixelColor(0, color2);
    pixels.setPixelColor(1, color3);
    pixels.setPixelColor(2, color1);
    pixels.setPixelColor(3, color2);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
    pixels.setPixelColor(0, color3);
    pixels.setPixelColor(1, color1);
    pixels.setPixelColor(2, color2);
    pixels.setPixelColor(3, color3);
    pixels.show();
    delay(200);
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);
    pixels.show();
    delay(400);
}
