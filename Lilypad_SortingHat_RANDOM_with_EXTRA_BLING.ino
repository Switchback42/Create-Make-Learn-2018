/*
 Lilypad_SortingHat_RANDOM_with_EXTRA_BLING
 
 Carrie, this code could work for your sorting hat, using a Lilypad Arduino.
 I was intrigued by your idea for generating random numbers, so I 
 figured out a way to do it.
 
 Feel free to tweak, modify, use, or discard this code.

 I added a function to the bottom of this sketch called oneOnAtATime()
 to add some flashy lights before the random pin gets selected.

 When using this with kids, have them reach into the hat and push the button to generate their house.
 They may need to keep it pressed down for more than a second.
 */

 
const int buttonPin = A5; //Sew a momentary push-button, such as a Lilypad Button Board to pin A5.  This pin has an internal pull-up resistor.
                          //This pull-up resistor will allow you to not worry about adding a resistor here.

/*
 Feel free to change these pins...you could add more than one LED, sewn in parallel
 for more dynamic light-up effects.
 If you change the pins here, they'll change in the array below. 
 */
int led1 = 5; 
int led2 = 6;
int led3 = A2;
int led4 = A4;

int ledPins[]= {led1, led2, led3, led4}; // This array will help you keep track of LEDs

// variables will change:
long randNumber; //This will help you get your random number

void setup(){
  Serial.begin(115200); 
  /*
  Your serial monitor, which you can look at by clicking on the little magnifying glass in the top
  right corner of this screen...AFTER YOU'VE UPLOADED YOUR CODE, may default to a baud rate of 9600.  
  So, if you don't see anything in your serial monitor, change the 115200 to 9600.
   */
                        
  pinMode(buttonPin, INPUT_PULLUP);// Lilypad buttons, on pin A5, need to use an internal pullup resistor
  pinMode (led1, OUTPUT); // Set your LEDs as OUTPUTs (I probably didn't need to duplicate this in the array below)
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  digitalWrite (led1, LOW); //This code sets the LEDs OFF to start
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW); 

  int index;
  for(index = 0; index <= 3; index++) // The first LED in the index is counted as 0 and the fourth one is counted as 3
  {
    pinMode(ledPins[index], OUTPUT); // I also set the LEDs as OUTPUTs above, but it was probably overkill
  }
}

void loop() {
  int buttonState; //this is a variable to keep track of the value of your push button
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value
  
  if (buttonState == LOW) //if the button is pushed
    {
  oneOnAtATime();  // call the oneOnAtATime function
  oneOnAtATime();  // I've called this function twice to extend the blinking, but you don't have to.
  // print a random number from 1 to 4 (since there are four Hogwarts houses)
  randNumber = random(1, 5); // If you want the range to include a total of 4 number choices (for 4 houses) start at 1 and end at 5.
  Serial.println(randNumber);
  
  /*
  The serial port will allow you to see which random number has been generated, to make sure that your code is working properly.
  The LilyPad push button is a little weird.  As long as you are holding it down, the microcontroller will be generating random numbers.
  When you finally let go of the button, it will land on one and then call a related function.
   */
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

void Hufflepuff(){          //This function will be called if the random number 1 is generated
  delay (1000);              // We're pausing
  digitalWrite (led1, HIGH); // Any LEDs you have attached to this pin will turn on
  digitalWrite (led2, LOW);  // LEDs on other pins will turn off
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  }

void Slytherin(){             //This function will be called if the random number 2 is generated
  delay(1000);                // We're pausing
  digitalWrite (led2, HIGH);  // Any LEDs you have attached to this pin will turn on
  digitalWrite (led1, LOW);
  digitalWrite (led3, LOW);
  digitalWrite (led4, LOW);
  }

void Gryffindor(){             //This function will be called if the random number 3 is generated
  delay(1000);                 // We're pausing
  digitalWrite (led3, HIGH);   // Any LEDs you have attached to this pin will turn on
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led4, LOW);
  }

 void Ravenclaw(){            //This function will be called if the random number 4 is generated
  delay(1000);                // We're pausing
  digitalWrite (led4, HIGH);  // Any LEDs you have attached to this pin will turn on
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
  }

/* 
The function below came from Arduino sample code that I've tweaked.
This function will turn your LEDs on and off again sequentially when the function is called.
*/
void oneOnAtATime() 
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                       // make this smaller for faster switching
  
  // step through the LEDs, from 0 to 3
  for(index = 0; index <= 3; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
 }
