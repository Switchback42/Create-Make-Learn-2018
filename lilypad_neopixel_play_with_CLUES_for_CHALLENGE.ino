/*
lilypad_neopixel_play_CLUES_for_CHALLENGE.ino

This code is an adaptation of code I found on Electronic Handbag Project website. 
I have modified it for the LilyPad and added my own spin, as well as comments.
You can find the original sketch on the Way Back Machine at:
https://web.archive.org/web/20170228191434/http://www.electronicfashion.co.uk/workshop_checklists.htm

Please visit https://www.rapidtables.com/convert/color/index.html to find additional hexcodes fo changing colors
*/

// Coding e-Textiles:  Create Make Learn 2018 
// Presentation by Jill Dawson
#include <Adafruit_NeoPixel.h> // This sketch requires you to download the Adafruit_NeoPixel library, which will give
                               // You access to some useful sample code

#define NEOPIN 5    // This is the number of the pad that connects to the NeoPixel's data-in pin
#define NUMPIXELS 4 // This is the number of NeoPixels in the strand
//#define LED1 11   // What might this line of code be used for?
                    // It has been commented out and is NOT currently part of this sketch. 
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIN); 
 
uint32_t color1 = 0xff000, // red  
         color2 = 0x00ff00, // green
         color3 = 0x0000ff; // blue
     
void setup() {
  pixels.begin();
  pixels.setBrightness(85);  // What would happen if you changed this value?
  //pinMode(LED1, OUTPUT);   //  What might this line do?  It is NOT currently being used in this sketch.
  //digitalWrite(LED1, LOW); //What might this line do?  It is NOT currently being used in this sketch.
}
 
void loop() {
//challenge(); // The function being called here is NOT currently being used in this sketch.
               // Do you know what a "function" does?
               
    pixels.setPixelColor(0, color1); // What do you think this line of code is doing?
    pixels.setPixelColor(1, color2);
    pixels.setPixelColor(2, color3);
    pixels.setPixelColor(3, color1);
    pixels.show();
    delay(200);                      // What do you think this line of code is doing?
    pixels.setPixelColor(0, 0);
    pixels.setPixelColor(1, 0);
    pixels.setPixelColor(2, 0);
    pixels.setPixelColor(3, 0);      // What do you think this line of code is doing?
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

//void challenge(){ // This function, which remains empty, is not currently doing anything in this sketch.  
                    // It has been placed here as a clue for an upcoming challenge activity.
                    // What might you add between the curly brackets, to personalize this program?
                    
//}
