/*
Description
Reads the value from a specified digital pin, either HIGH or LOW.

Syntax
Use the following function to read the value of a digital pin:

digitalRead(pin)

Parameters
The function admits the following parameter:

pin: the Arduino pin number you want to read.

Returns
The function returns the boolean state of the read pin as HIGH or LOW.

Example Code
Control the Arduino built-in LED on pin 13 (output) by assigning the same value of a push button connected to pin 7 (input).
*/


int ledPin = 13;  // LED connected to digital pin 13
int inPin = 7;    // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT);    // sets the digital pin 7 as input
}

void loop() {
  val = digitalRead(inPin);   // read the input pin
  digitalWrite(ledPin, val);  // sets the LED to the button's value
}


/*
Notes and Warnings
If the pin isn’t connected to anything, digitalRead() can return either HIGH or LOW (and this can change randomly).

The analog input pins can be used as digital pins, referred to as A0, A1, etc. The exception is the Arduino Nano, 
Arduino Pro Mini, and Arduino Mini’s A6 and A7 pins, which can only be used as analog inputs.
*/


//-----------------------------------------------------------------------------------------------------------------//


/*
Description
Write a HIGH or a LOW value to a digital pin.

If the pin has been configured as an OUTPUT with pinMode(), 
its voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH and 0V (ground) for LOW.

If the pin is configured as an INPUT, digitalWrite() will enable (HIGH) or disable (LOW) the internal pull-up on the input pin. 
It is recommended to set the pinMode() to INPUT_PULLUP to enable the internal pull-up resistor. 

If you do not set the pin as an OUTPUT, and connect an LED to it, when calling digitalWrite(pin, HIGH), 
the LED may appear dim. Without explicitly setting pinMode(), digitalWrite() will have enabled the internal pull-up resistor, 
which acts like a large current-limiting resistor.


Syntax
Use the following function to write a digital value to a pin:

digitalWrite(pin, value)


Parameters
The function admits the following parameters:

pin: the Arduino pin number to be controlled.
value: HIGH or LOW
Returns
The function returns nothing.


Example Code
Set the Arduino digital pin 13 (built-in LED) as an OUTPUT and toggles it by alternating between HIGH and LOW at one second pace.
*/


void setup() {
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output
}

void loop() {
  digitalWrite(13, HIGH); // sets the digital pin 13 on
  delay(1000);            // waits for a second
  digitalWrite(13, LOW);  // sets the digital pin 13 off
  delay(1000);            // waits for a second
}


/*
Notes and Warnings

The analog input pins can be used as digital pins, referred to as A0, A1, etc. 
The exception is the Arduino Nano, Pro Mini, and Mini’s A6 and A7 pins, which can only be used as analog inputs.
*/

//-----------------------------------------------------------------------------------------------------------------//


/*
Description
Configures the specified pin to behave either as an INPUT or an OUTPUT. 

As of Arduino 1.0.1, it is possible to enable the internal pull-up resistors with the mode INPUT_PULLUP. 
Additionally, the INPUT mode explicitly disables the internal pull-up, regardless of the pin's previous state.

Syntax
Use the following function to set the behavior of a pin:

pinMode(pin, mode)

Parameters
The function admits the following parameters:

pin: the Arduino pin number to set the mode of.
mode: INPUT, OUTPUT, or INPUT_PULLUP. 
The function returns nothing.

Example Code
Set the Arduino digital pin 13 (built-in LED) as an OUTPUT and toggle it by alternating between HIGH and LOW at a one-second pace
*/


void setup() {
  pinMode(13, OUTPUT);    // Sets the digital pin 13 as output
}

void loop() {
  digitalWrite(13, HIGH); // Sets the digital pin 13 on
  delay(1000);            // Waits for a second
  digitalWrite(13, LOW);  // Sets the digital pin 13 off
  delay(1000);            // Waits for a second
}


/*
Notes and Warnings
The analog input pins can be used as digital pins, referred to as A0, A1, etc.
*/