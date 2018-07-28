/*
 Sorting Hat for Carrie
 This code could work for your sorting hat, using a Lilypad Arduino.
 I was intrigued by your idea for generating random numbers, so I 
 figured out a way to do it.
 Feel free to tweak, modify, use, or discard this code.
 Courtesy of Jill Dawson
 */

 
const int buttonPin = A5; //Clip a momentary push-button to pin A5.  This pin has an internal pull-up resistor.
                          //This pull-up resistor will allow you to not worry about adding a resistor here.

int led1 = 5; //Feel free to change these pins...you could add more than one LED, sewn in parallel, to each pin for a
              //more dynamic light-up effect
int led2 = 6;
int led3 = A2;
int led4 = A4;

// variables will change:
long randNumber; //This will help you get your random number

void setup(){
  Serial.begin(115200); //Your serial monitor, which you can look at by clicking on the little magnifying glass in the top
                        //right corner of this screen...AFTER YOU'VE UPLOADED YOUR CODE, my default to a baud rate or 9600.  
                        //So, if you don't see anything in your serial monitor, change the 115200 to 9600.
                        

  pinMode(buttonPin, INPUT_PULLUP);// Lilypad buttons, on pin A5, need to use an internal pullup resistor
  pinMode (led1, OUTPUT); // Set your LEDs as OUTPUTs
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  digitalWrite (led1, LOW); //This code sets the LEDs OFF to start
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  
}

void loop() {
  int buttonState; //this is a variable to keep track of the value of your push button
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
  
  if (buttonState == LOW) //If the button is pushed ...I know...this isn't intuitive
    {
  // print a random number from 1 to 4
  randNumber = random(1, 5); // If you want the range to include a total of 4 number choices (for 4 houses) start at 1 and end at 5.
  Serial.println(randNumber); // The serial port will allow you to see which random number has been generated, 
                              // to make sure that your code is working properly.  The LilyPad push button
                              // is a little weird.  As long as you are holding it down, the microcontroller will
                              // be generating random numbers.  When you finally let go of the button, it will land
                              // on one and then call a related function.
     }
  if (randNumber == 1) // if the computer selects 1
     {
     Hufflepuff(); // the Hufflepuff function (detailed below) will be called
     }
  else if (randNumber == 2) // if the computer selects 2
    { 
     Slytherin(); // the Slytherin function (detailed below) will be called
    }
  else if (randNumber == 3) // if the computer selects 3
    {
     Gryffindor(); // the Gryffindor function (detailed below) will be called
    }
  else if (randNumber == 4) // if the computer selects 4
    {
      Ravenclaw(); // the Ravenclaw function (detailed below) will be called
    }
}

//These are the four Hogwarts functions that will be called

void Hufflepuff(){ //This function will be called if the random number 1 is generated
  digitalWrite (led1, HIGH); // Any LEDs you have attached to this pin will turn on
  digitalWrite (led2, LOW);  // LEDs on other pins will turn off
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  }

void Slytherin(){ //This function will be called if the random number 2 is generated
  digitalWrite (led2, HIGH);
  digitalWrite (led1, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  }

void Gryffindor(){ //This function will be called if the random number 3 is generated
  digitalWrite (led3, HIGH);
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led4, LOW);
  }

 void Ravenclaw(){ //This function will be called if the random number 4 is generated
  digitalWrite (led4, HIGH);
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  }
