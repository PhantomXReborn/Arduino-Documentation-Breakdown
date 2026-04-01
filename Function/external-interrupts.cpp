
// attachInterrupt()

/*
Using Interrupts
Interrupts help make things happen automatically in microcontroller programs and can help solve timing problems. 
Good tasks for using an interrupt may include reading a rotary encoder, or monitoring user input.

If you wanted to ensure that a program always caught the pulses from a rotary encoder, 
so that it never misses a pulse, it would make it very tricky to write a program to do anything else, 
because the program would need to constantly poll the sensor lines for the encoder, to catch pulses when they occurred. 
Other sensors have a similar interface dynamic, such as trying to read a sound sensor that detects a click, 
or an infrared slot sensor (photo-interrupter) that detects a coin drop. In all these situations, 
using an interrupt can free the microcontroller to do other work while still capturing the input.

Syntax
attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) (recommended)
attachInterrupt(interrupt, ISR, mode) (not recommended)
attachInterrupt(pin, ISR, mode) (Not recommended. Additionally, this syntax only works on Arduino SAMD Boards, UNO WiFi Rev2, Due, and 101.)

Parameters
interrupt: the number of the interrupt. Allowed data types: int.

pin: the Arduino pin number.

ISR: the ISR to call when the interrupt occurs; this function must take no parameters and return nothing. 
This function is sometimes referred to as an interrupt service routine.

mode: defines when the interrupt should be triggered. Four constants are predefined as valid values:
    LOW to trigger the interrupt whenever the pin is low,
    CHANGE to trigger the interrupt whenever the pin changes value
    RISING to trigger when the pin goes from low to high,
    FALLING for when the pin goes from high to low.

The Due, Zero and MKR1000 boards allow also:
    HIGH to trigger the interrupt whenever the pin is high.

Interrupt Service Routines (ISR)
ISRs are special kinds of functions that have unique limitations not shared by most other functions. 
An ISR cannot have any parameters and it should not return anything.

Generally, an ISR should be as short and fast as possible. If your sketch uses multiple ISRs, 
only one can run at a time; Other interrupts will be executed after the current one finishes, 
in an order that depends on their priority. millis() relies on interrupts to count, so it will never increment inside an ISR. 
Since delay() requires interrupts to work, it will not function if called inside an ISR. 
micros() works initially but starts behaving erratically after 1-2 ms. delayMicroseconds() does not use a counter, 
so it will work as usual.

Typically, global variables are used to pass data between an interrupt service routine (ISR) and the main program. 
To make sure variables shared between an ISR and the main program are updated correctly, declare them as volatile.

For more information on interrupts, see Nick Gammon’s notes.

Returns
Nothing

Example Code
*/

const byte ledPin = 13;
const byte interruptPin = 2;  // input pin that the interruption will be attached to
volatile byte state = LOW;  // variable that will be updated in the ISR

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink() {
  state = !state;
}

/*
Digital Pins With Interrupts
The first parameter of attachInterrupt() is an interrupt number. 
Normally, you should use digitalPinToInterrupt(pin) to translate the actual digital pin to the specific interrupt number. 
For example, if you connect to pin 3, use digitalPinToInterrupt(3) as the first parameter to attachInterrupt().


 * Board                          | Digital Pins Usable For Interrupts | Notes
 * -------------------------------|------------------------------------|-----------------------------------------------------------------------------
 * UNO R3, Nano, Mini, other      | 2, 3                               |
 * 328-based                      |                                    |
 * UNO R4 Minima, UNO R4 WiFi     | 2, 3                               |
 * UNO WiFi Rev2, Nano Every      | All digital pins                   |
 * Mega, Mega 2560, Mega ADK      | 2, 3, 18, 19, 20, 21               | pins 20 & 21 are not available to use for interrupts while they are used
 *                                |                                    | for I2C communication; they also have external pull-ups that cannot be
 *                                |                                    | disabled
 * Micro, Leonardo                | 0, 1, 2, 3, 7                      |
 * Zero                           | 0-3, 5-13, A0-A5                   | Pin 4 cannot be used as an interrupt.
 * MKR Family boards              | 0, 1, 4, 5, 6, 7, 8, 9, A1, A2     |
 * Nano 33 IoT                    | 2, 3, 9, 10, 11, 13, A1, A5, A7    |
 * Nano 33 BLE, Nano 33 BLE Sense | all pins                           |
 * (Rev 1 & 2)                    |                                    |
 * Nano RP2040 Connect            | 0-13, A0-A5                        |
 * Nano ESP32                     | all pins                           |
 * GIGA R1 WiFi                   | all pins                           |
 * Due                            | all digital pins                   | Only pins 2, 5, 7, 8, 10, 11, 12,
 *                                |                                    | 13 work with CHANGE.
 
 Interrupt Numbers
Normally you should use digitalPinToInterrupt(pin), rather than place an interrupt number directly into your sketch. 
The specific pins with interrupts and their mapping to interrupt number varies for each type of board. 
Direct use of interrupt numbers may seem simple, but it can cause compatibility trouble when your sketch runs on a different board.

However, older sketches often have direct interrupt numbers. Often number 0 (for digital pin 2) or number 1 (for digital pin 3) were used. 
The table below shows the available interrupt pins on various boards.

Note that in the table below, the interrupt numbers refer to the number to be passed to attachInterrupt(). 
For historical reasons, this numbering does not always correspond directly to the interrupt numbering on the ATmega chip 
(e.g. int.0 corresponds to INT4 on the ATmega2560 chip).

 * Board                      | int.0 | int.1 | int.2 | int.3 | int.4 | int.5 |
 * ---------------------------|-------|-------|-------|-------|-------|-------|
 * UNO, Ethernet              | 2     | 3     |       |       |       |       |
 * Mega 2560                  | 2     | 3     | 21    | 20    | 19    | 18    |
 * 32u4 based (e.g. Leonardo, | 3     | 2     | 0     | 1     | 7     |       |
 * Micro)                     |       |       |       |       |       |       |

 For UNO WiFi Rev2, Due, Zero, MKR Family and 101 boards the interrupt number = pin number.

Notes and Warnings
Note: the attached function, delay() won’t work and the value returned by millis() will not increment. 
Serial data received while in the function may be lost. You should declare as volatile any variables 
that you modify within the attached function. See the section on ISRs below for more information.
*/


//-----------------------------------------------------------------------------------------------------------------//

// detachInterrupt()

/*
Description
This function turns off a given interrupt that was attached previously.

Syntax
This function has the following variants:

detachInterrupt(digitalPinToInterrupt(pin)) (recommended)
detachInterrupt(interrupt) (not recommended)
detachInterrupt(pin) (Not recommended. Additionally, this only works on a specific set of boards.)
Parameters
The function admits the following parameters:

interrupt: the number of the interrupt to disable (see attachInterrupt() for more details)
pin: the Arduino pin number of the interrupt to disable
Returns
The function returns nothing.

Example Code
*/

void setup() {
  // Attach an interrupt on digital pin 2 (assuming you're using it with a button or sensor)
  //  attachInterrupt(digitalPinToInterrupt(2), myInterruptRoutine, RISING);

  // ... other setup code ...

  // Later, you can detach the interrupt when you no longer need it
  detachInterrupt(digitalPinToInterrupt(2)); // or detachInterrupt(2);
}

void loop() {
  // ... your main loop code ...
}

void myInterruptRoutine() {
  // This function will be executed when the interrupt on pin 2 is triggered
  // and it's still attached.  After detachInterrupt(), this routine won't be called.
}


//-----------------------------------------------------------------------------------------------------------------//

// digitalPinToInterrupt()

/*
Description
The digitalPinToInterrupt() function takes a pin as an argument, and returns the same pin if it can be used as an interrupt. 
For example, digitalPinToInterrupt(4) on an Arduino UNO will not work, as interrupts are only supported on pins 2 and 3.

See attachInterrupt() for a full list of supported interrupt pins on all boards.

Syntax
To verify if a given pin can be used an interrupt use the following function:

digitalPinToInterrupt(pin)

Parameters
The function admits the following parameter:

pin: the pin we want to use for an interrupt.
Returns
If the pin is available for interrupt, it will return the given pin (e.g. 2).
If the pin is not available for interrupt, it will return -1.

Example Code
This example checks if a pin can be used as an interrupt.
*/

int pin = 2;

void setup() {
  Serial.begin(9600);
  int checkPin = digitalPinToInterrupt(pin);

  if (checkPin == -1) {
    Serial.println("Not a valid interrupt pin!");
  } else {
    Serial.println("Valid interrupt pin.");
  }
}

void loop() {
}

// All Material is made and referenced by: ArduinoDocs at https://docs.arduino.cc/language-reference/#functions