/*
lilypad_neopixel_switch
This code has been modified from code found at the Electronic Handbag Project.  You may reference the original code at
https://web.archive.org/web/20170228191434/http://www.electronicfashion.co.uk/workshop_checklists.htm

This particular sketch has been customized for the LilyPad
Please visit https://www.rapidtables.com/web/color/pink-color.html to find additional hexcodes fo changing colors
*/

//Coding E-Textiles:  Create Make Learn 2018
#include <Adafruit_NeoPixel.h>

//set variables with colors you want to use
uint32_t color1 = 0x00ff00, // green
         color2 = 0x0000ff; // blue

//attach one side of the switch to pin 6 and the other to the power (+) pin.
int switchpin = 6;

//attach the NeoPixel's data-in pin to 5
int neopin = 5;

//there is only one NeoPixel, and it is controlled through the data-in pin (ie. neopin)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel (1, neopin);

//The setup will only run once
void setup(){
  //tell the Lilypad to listen to input on the switchpin
  pinMode(switchpin, INPUT);
  //declare the neopixel an output
  pinMode(neopin, OUTPUT);
  digitalWrite(switchpin, LOW); //setting the switchpin to low upon start will open the switch
  //prepare NeoPixel(s)
  pixels.begin();
  pixels.setBrightness(25);
}

//The loop will repeat
void loop(){
  //see if the switch is open or closed, then set the NeoPixel color
  if(digitalRead(switchpin)== HIGH){
    neoPattern(color1);}
  else {neoPattern(color2);}
  delay(100);
  }

 //this is the function you called in the loop
 void neoPattern(uint32_t acol){
  pixels.setPixelColor(0, acol); //the 0 here refers to the first pixel
  pixels.show();
  delay(200);
  pixels.setPixelColor(0,0); 
  pixels.show();
  delay(200);
}

