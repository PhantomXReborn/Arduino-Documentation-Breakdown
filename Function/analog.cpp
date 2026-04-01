
// analogRead()

/*
Description
Reads the value from a specified analog input pin.

An Arduino UNO, for example, contains a multichannel, 10-bit analog to digital converter (ADC). 
This means that it will map input voltages between 0 and the operating voltage (+5 VDC) into integer values between 0 and 1023. 
This yields a resolution between readings of: 5 volts / 1024 units or 0.0049 volts (4.9 mV) per unit.

The voltage input range can be changed using analogReference(). The default analogRead() resolution on Arduino boards is set to 10 bits, 
for compatibility. You need to use analogReadResolution() to change it to a higher resolution.

Syntax
Use the following function to get a sample reading of an analog input:

analogRead(pin)

Parameters
The function admits the following parameter:

pin: the name of the analog input pin to read from.

Returns
The function returns the analog reading on the pin. Although it is limited to the resolution of the analog to digital converter 
(0-1023 for 10 bits, 0-4095 for 12 bits, etc). Data type: int.

Example Code
The code reads the analog value on analogPin and displays it.
*/


int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and VCC
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  Serial.println(val);          // debug value
  delay(200);
}


// You can convert the raw analog reading into a voltage value by using the following method:


// Constants
const float V_REF = 5.0;     // Analog reference voltage (e.g., 5V or 3.3V)
const float R_BITS = 10.0;   // ADC resolution (bits)
const float ADC_STEPS = (1 << int(R_BITS)) - 1; // Number of steps (2^R_BITS - 1)

const int potentiometerPin = A3; // Potentiometer wiper connected to analog pin A3

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println(ADC_STEPS);
}

void loop() {
  int rawValue = analogRead(potentiometerPin); // Read the analog input
  float voltage = (rawValue / ADC_STEPS) * V_REF; // Convert to voltage

  Serial.print("Voltage: ");
  Serial.print(voltage, 3); // Print voltage with 3 decimal places
  Serial.println(" V");
  
  delay(200); // Small delay to avoid flooding the serial monitor
}


/*
Notes and Warnings
If the analog input pin is not connected to anything, the value returned by analogRead() will fluctuate based on a number of factors 
(e.g. the values of the other analog inputs, how close your hand is to the board, etc.).
*/


//-----------------------------------------------------------------------------------------------------------------//

// analogReadResolution()

/*
Description
analogReadResolution() is an extension of the Analog API that let you set the resolution (in bits) of the value returned by analogRead(). 
It defaults to 10 bits (returns values between 0-1023) for backward compatibility with AVR based boards.

Within the Arduino boards you can find a variety of resolutions that lead to different ranges:

10 bits: allow values between 0 and 1023. 12 bits: allow values between 0 and 4095. 
14 bits: allow values between 0 and 16383. 16 bits: allow values between 0 and 65535.

Syntax
Use the following function to set the ADC resolution of your board:

analogReadResolution(bits)

Parameters
The function admits the following parameter:

bits: determines the resolution (in bits) of the value returned by the analogRead() function.

You can set this between 1 and 32. You can set resolutions higher than the supported 12 or 16 bits, 
but values returned by analogRead() will suffer approximation. See the note below for details.

Returns
The function returns nothing.

Example Code
The code shows how to use ADC with different resolutions.
*/


void setup() {
  // open a serial connection
  Serial.begin(9600);
}

void loop() {
  // read the input on A3 at default resolution (10 bits)
  // and send it out the serial connection
  analogReadResolution(10);
  Serial.print("ADC 10-bit (default) : ");
  Serial.print(analogRead(A3));

  // change the resolution to 12 bits and read A3
  analogReadResolution(12);
  Serial.print(", 12-bit : ");
  Serial.print(analogRead(A3));

  // change the resolution to 16 bits and read A3
  analogReadResolution(16);
  Serial.print(", 16-bit : ");
  Serial.print(analogRead(A3));

  // change the resolution to 8 bits and read A3
  analogReadResolution(8);
  Serial.print(", 8-bit : ");
  Serial.println(analogRead(A3));

  // a little delay to not hog Serial Monitor
  delay(100);
}


/*
Notes and Warnings
If you set the analogReadResolution() value to a value higher than your board’s capabilities, 
the Arduino board will only report back at its highest resolution, padding the extra bits with zeros.

For example: using the UNO R4 with analogReadResolution(16) will give you an approximated 16-bit number 
with the first 14 bits containing the real ADC reading and the last 2 bits padded with zeros.

If you set the analogReadResolution() value to a value lower than your board’s capabilities, 
the extra least significant bits read from the ADC will be discarded.

Using a 16 bit resolution (or any resolution higher than actual hardware capabilities) allows you to write sketches 
that automatically handle devices with a higher resolution ADC when these become available on future boards without changing a line of code.
*/


//-----------------------------------------------------------------------------------------------------------------//

// analogReference()

/*
Description
Configures the reference voltage used for analog input (i.e. the maximum voltage that can be sensed). The options are:

Arduino AVR Boards (UNO, Mega, Leonardo, etc.)
    DEFAULT: the default analog reference of 5 volts (on 5 VDC Arduino boards) or 3.3 volts (on 3.3 VDC Arduino boards).
    INTERNAL: a built-in reference, equal to 1.1 volts on the ATmega168 or ATmega328P and 2.56 volts on the ATmega32U4 and ATmega8 
    (not available on the Arduino Mega).
    INTERNAL1V1: a built-in 1.1 VDC reference (Arduino Mega only).
    INTERNAL2V56: a built-in 2.56 VDC reference (Arduino Mega only).
    EXTERNAL: the voltage applied to the AREF pin (0 to 5 VDC only) is used as the reference.

Arduino Renesas Boards (UNO R4, Portenta C33)
    AR_DEFAULT: the default analog reference of 5 volts.
    AR_INTERNAL: a built-in reference, equal to 1.5 Volts on the RA4M1 of the UNO R4.
    AR_INTERNAL_1_5V: a built-in reference, equal to 1.5 VDC on the R7FA6M5 of the Portenta C33.
    AR_INTERNAL_2_0V: a built-in reference, equal to 2.0 VDC on the R7FA6M5 of the Portenta C33.
    AR_INTERNAL_2_5V: a built-in reference, equal to 2.5 VDC on the R7FA6M5 of the Portenta C33.
    AR_EXTERNAL: the voltage applied to the AREF pin (0 to 5 VDC only) is used as the reference.

Arduino SAMD Boards (Zero, etc.)
    AR_DEFAULT: the default analog reference of 3.3 VDC.
    AR_INTERNAL: a built-in 2.23 VDC reference.
    AR_INTERNAL1V0: a built-in 1.0 VDC reference.
    AR_INTERNAL1V65: a built-in 1.65 VDC reference
    AR_INTERNAL2V23: a built-in 2.23 VDC reference
    AR_EXTERNAL: the voltage applied to the AREF pin is used as the reference

Arduino megaAVR Boards (UNO WiFi Rev2, Arduino Nano Every)
    DEFAULT: a built-in 0.55 VDC reference
    INTERNAL: a built-in 0.55 VDC reference
    VDD: Vdd of the ATmega4809. 5 VDC on the Uno WiFi Rev2 and Nano Every
    INTERNAL0V55: a built-in 0.55 VDC reference
    INTERNAL1V1: a built-in 1.1 VDC reference
    INTERNAL1V5: a built-in 1.5 VDC reference
    INTERNAL2V5: a built-in 2.5 VDC reference
    INTERNAL4V3: a built-in 4.3 VDC reference
    EXTERNAL: the voltage applied to the AREF pin (0 to 5 VDC only) is used as the reference

Arduino SAM Boards (Due)
    AR_DEFAULT: the default analog reference of 3.3 VDC. This is the only supported option for the Due.
    Arduino Mbed OS Nano Boards (Nano 33 BLE), Arduino Mbed OS Edge Boards (Edge Control)
    AR_VDD: the default 3.3 VDC reference
    AR_INTERNAL: built-in 0.6 VDC reference
    AR_INTERNAL1V2: 1.2 VDC reference (internal 0.6 VDC reference with 2x gain)
    AR_INTERNAL2V4: 2.4 VDC reference (internal 0.6 VDC reference with 4x gain)
*/


/*
Syntax
Use the following function to change the voltage reference for analog inputs in supported boards:

analogReference(type)

Parameters
The function supports the following parameter:

type: which type of reference to use (see list of options in the description).

Returns
This function returns nothing.

Notes and Warnings
After changing the analog reference, the first few readings from analogRead() may not be accurate.

Don’t use anything less than 0V or more than 5 VDC for external reference voltage on the AREF pin! 
If you’re using an external reference on the AREF pin, you must set the analog reference to EXTERNAL before calling analogRead().

Otherwise, you will short together the active reference voltage (internally generated) and the AREF pin, 
possibly damaging the microcontroller on your Arduino board.

Alternatively, you can connect the external reference voltage to the AREF pin through a 5 K resistor, 
allowing you to switch between external and internal reference voltages. 
Note that the resistor will alter the voltage that gets used as the reference because there is an internal 32 K resistor on the AREF pin. 
The two act as a voltage divider, so, for example, 2.5 VDC applied through the resistor will yield 2.5 * 32 / (32 + 5) = ~2.2 VDC at the AREF pin.
*/


//-----------------------------------------------------------------------------------------------------------------//

// analogWrite()

/*
Description
Writes an analog value (PWM wave) to a pin. Can be used to light a LED at varying brightness or drive a motor at various speeds. 
After a call to analogWrite(), the pin will generate a steady rectangular wave of the specified duty cycle until the next call to analogWrite() 
(or a call to digitalRead() or digitalWrite()) on the same pin.

Check your board pinout to know which are the officially supported PWM pins. While some boards have additional pins capable of PWM,
using them is recommended only for advanced users that can account for timer availability and potential conflicts with other uses of those pins.

In addition to PWM capabilities some boards have true analog output when using analogWrite() on the DAC marked pins. 
Check your board pinout to find out if the DAC is available.

Only 4 different pins can be used at the same time. Enabling PWM on more than 4 pins will abort the running sketch and 
require resetting the board to upload a new sketch again.

You do not need to call pinMode() to set the pin as an output before calling analogWrite(). 
The analogWrite function has nothing to do with the analog pins or the analogRead function.

Syntax
Use the following function to generate a PWM signal on a given pin:

analogWrite(pin, value)

Parameters
The function admits the following parameters:

pin: the Arduino pin to output the PWM signal. Allowed data types: int
value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int
Returns
The function returns nothing.

Example Code
Sets the PWM duty cycle that controls the LED proportional to the value read from the potentiometer (connected to A3).
*/


int ledPin = 9;      // LED connected to digital pin 9
int analogPin = A3;   // potentiometer connected to analog pin 3 (A3)
int val = 0;         // variable to store the read value

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the pin as output
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}


/*
Notes and Warnings
The PWM outputs generated on pins 5 and 6 may have higher-than-expected duty cycles. 
This is because of interactions with the millis() and delay() functions, which share the same internal timer used to generate those PWM outputs. 
This will be noticed mostly on low duty-cycle settings (e.g. 0 - 10) and may result in a value of 0 not fully turning off the output on pins 5 and 6.
*/


//-----------------------------------------------------------------------------------------------------------------//

// analogWriteResolution()

/*
Description
analogWriteResolution() is an extension of the Analog API to set the resolution of the analogWrite() function. 
It defaults to 8 bits (values between 0 - 255) for backward compatibility with AVR based boards.

Syntax
Use the following function to leverage the full range of the DAC and PWM outputs:

analogWriteResolution(bits)

Parameters
The function admits the following parameter:

bits: determines the resolution (in bits) of the values used in the analogWrite() function. 
The value can range from 1 to 32. If you choose a resolution higher or lower than your board’s hardware capabilities, 
the value used in analogWrite() will be either truncated if it’s too high or padded with zeros if it’s too low. See the note below for details.

Returns
The function returns nothing.

Example Code
*/

void setup() {
  // open a serial connection
  Serial.begin(9600);
  // make our digital pin an output
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // read the input on A0 and map it to a PWM pin
  // with an attached LED
  int sensorVal = analogRead(A0);
  Serial.print("Analog Read : ");
  Serial.print(sensorVal);

  // the default PWM resolution
  analogWriteResolution(8);
  analogWrite(11, map(sensorVal, 0, 1023, 0, 255));
  Serial.print(" , 8-bit PWM value : ");
  Serial.print(map(sensorVal, 0, 1023, 0, 255));

  // change the PWM resolution to 12 bits
  analogWriteResolution(12);
  analogWrite(12, map(sensorVal, 0, 1023, 0, 4095));
  Serial.print(" , 12-bit PWM value : ");
  Serial.print(map(sensorVal, 0, 1023, 0, 4095));

  // change the PWM resolution to 4 bits
  analogWriteResolution(4);
  analogWrite(13, map(sensorVal, 0, 1023, 0, 15));
  Serial.print(", 4-bit PWM value : ");
  Serial.println(map(sensorVal, 0, 1023, 0, 15));

  delay(5);
}

/*
Notes and Warnings
Boards Capabilities
Boards with an 8-bit PWM resolution are capable of slicing the PWM duty cycle on 255 steps.
Boards with an 10-bit PWM resolution are capable of slicing the PWM duty cycle on 1024 steps.
Boards with an 12-bit PWM resolution are capable of slicing the PWM duty cycle on 4095 steps.
Boards with an 16-bit PWM resolution are capable of slicing the PWM duty cycle on 65536 steps.
Other Considerations
If you set the analogWriteResolution() value to a value higher than your board’s capabilities, the Arduino will discard the extra bits.

If you set the analogWriteResolution() value to a value lower than your board’s capabilities,
the missing bits will be padded with zeros to fill the hardware required size.
*/

// All Material is made and referenced by: ArduinoDocs at https://docs.arduino.cc/language-reference/#functions