
// abs()

/*
Description
This function calculates the absolute value of a given number.

Syntax
Use the following function to compute the absolute value of x:

abs(x)

Parameters
The function admits the following parameter:

x: the number to compute.

Returns
The function returns x if the input parameter is greater than or equal to 0.

The function returns -x if the input parameter is less than 0.

Example Code
Prints the absolute value of variable x to the Serial Monitor.
*/


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  int x = 42;
  Serial.print("The absolute value of ");
  Serial.print(x);
  Serial.print(" is ");
  Serial.println(abs(x));
  x = -42;
  Serial.print("The absolute value of ");
  Serial.print(x);
  Serial.print(" is ");
  Serial.println(abs(x));
}

void loop() {
}


/*
Notes and Warnings
Because of the way the abs() function is implemented, 
avoid using other functions inside the brackets, 
it may lead to incorrect results.
*/

abs(a++); // avoid this - yields incorrect results

// use this instead:
abs(a);
a++;  // keep other math outside the function


//-----------------------------------------------------------------------------------------------------------------//

// constrain()

/*
Description
Constraints a number to be within a range. The input of this function could be, for example, 
a sensor value that controls a motor position, with the lower and upper ranges of the function being the physical limits of possible movement.

Syntax
Use the following function to constrain the range of a given variable:

constrain(x, a, b)

Parameters
The function admits the following parameters:

x: the number to constrain. Allowed data types: all data types.
a: the lower end of the range. Allowed data types: all data types.
b: the upper end of the range. Allowed data types: all data types.

Returns
The function returns the following:

x: if the input parameter (x) is between a and b.
a: if the input parameter (x) is less than a.
b: if the input parameter (x) is greater than b.

Example Code
The code sets an emulated sensor value and prints its constrained result on the Serial Monitor.
*/


int sensVal = 50;  // try with 170 and 5 to verify the functionality

void setup() {
  Serial.begin(9600);

  sensVal = constrain(sensVal, 10, 150);  // limits range of sensor values between 10 and 150

  Serial.print("The sensor value is: ");
  Serial.println(sensVal);
}

void loop() {
}

/*
Notes and Warnings
Because of the way the constrain() function is implemented, 
avoid using other functions inside the brackets, it may lead to incorrect results.

This code will yield incorrect results:
*/


int constrainedInput = constrain(Serial.parseInt(), minimumValue, maximumValue);   // avoid this

// Use this instead:

int input = Serial.parseInt();  // keep other operations outside the constrain function
int constrainedInput = constrain(input, minimumValue, maximumValue);


//-----------------------------------------------------------------------------------------------------------------//

// map()

/*
Description
Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, 
a value of fromHigh to toHigh, values in-between to values in-between, etc.

Does not constrain values to within the range, because out-of-range values are sometimes intended and useful. 
The constrain() function may be used either before or after this function, if limits to the ranges are desired.

Note that the "lower bounds" of either range may be larger or smaller than the "upper bounds", 
so the map() function may be used to reverse a range of numbers, for example

y = map(x, 1, 50, 50, 1);

The function also handles negative numbers well, so that the following example is also valid and works well.

y = map(x, 1, 50, 50, -100);

The map() function uses integer math so will not generate fractions, when the math might indicate that it should do so. 
Fractional remainders are truncated, and are not rounded or averaged.

Syntax
Use the following function to re-map a variable range to another:

map(value, fromLow, fromHigh, toLow, toHigh)

Parameters
The function admits the following parameters:

value: the input variable with the number to map.
fromLow: the lower bound of the value’s current range.
fromHigh: the upper bound of the value’s current range.
toLow: the lower bound of the value’s target range.
toHigh: the upper bound of the value’s target range.
Returns
The mapped value. Data type: long.

Example Code
Maps a 10-bit (0-1023) analog input value to 8-bit (0-255) value and controls pin 9 PWM output. 
The input and output values are printed in the Serial Monitor.
*/


/* Map an analog value to 8 bits (0 to 255) */
void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);

  Serial.print("Input value: ");
  Serial.print(val);

  val = map(val, 0, 1023, 0, 255); // mapping function

  Serial.print(", Output value: ");
  Serial.println(val);

  analogWrite(9, val); // PWM output
  delay(200);
}


/*
If you connect a potentiometer to the analog pin (A0) and an LED to pin 9, you can control its brightness by turning the potentiometer.

Appendix
For the mathematically inclined, here’s the whole function.
*/


long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/*
Notes & Warnings

As previously mentioned, the map() function uses integer math. So fractions might get suppressed due to this. For example, 
fractions like 3/2, 4/3, 5/4 will all be returned as 1 from the map() function, despite their different actual values. 
So if your project requires precise calculations (e.g. voltage accurate to 3 decimal places), 
please consider avoiding map() and implementing the calculations manually in your code yourself.
*/


//-----------------------------------------------------------------------------------------------------------------//

// max()

/*
Description
Find the larger of two numbers using the max() function.

Syntax
Use the following function to compare two numbers and find the larger:

max(x, y)

Parameters
The function admits the following parameters:

x: the first number to compare. Allowed data types: any data type.
y: the second number to compare. Allowed data types: any data type.

Returns
This function returns the larger of the two parameter values compared.

Example Code
Compares a and b and print the larger variable in the Serial Monitor.
*/


int a = 25;
int b = 14;

void setup() {
  Serial.begin(9600);

  int max = max(a, b);

  Serial.print("The larger value is: ");
  Serial.println(max);
}

void loop() {
}


/*
Another typical application could be to constrain a minimum value of a variable, 
as shown in the following example:
*/


sensVal = max(sensVal, 20); // assigns sensVal to the larger of sensVal or 20
                            // (effectively ensuring that it is at least 20)


/*
Notes and Warnings
Perhaps counter-intuitively, max() is often used to constrain the lower end of a variable’s range, 
while min() is used to constrain the upper end of the range.

Because of the way the max() function is implemented, avoid using other functions inside the brackets, 
it may lead to incorrect results
*/


max(a--, 0);  // avoid this - yields incorrect results

// use this instead:
max(a, 0);
a--;  // keep other math outside the function


//-----------------------------------------------------------------------------------------------------------------//

// min()

/*
Description
Find the smaller of two numbers using the min() function.

Syntax
Use the following function to compare two numbers and find the smaller:

min(x, y)

Parameters
The function admits the following parameters:

x: the first number to compare. Allowed data types: any data type.
y: the second number to compare. Allowed data types: any data type.
Returns
This function returns the smaller of the two parameter values compared.

Example Code
Compares a and b and print the smaller variable in the Serial Monitor.
*/


int a = 25;
int b = 14;

void setup() {
  Serial.begin(9600);

  int min = min(a, b);

  Serial.print("The smaller value is: ");
  Serial.println(min);
}

void loop() {
}


// Another typical application could be to constrain a maximum value of a variable, 
// as shown in the following example:


sensVal = min(sensVal, 100);  // assigns sensVal to the smaller of sensVal or 100
                              // ensuring that it never gets above 100.


/*
Notes and Warnings
Perhaps counter-intuitively, max() is often used to constrain the lower end of a variable’s range, 
while min() is used to constrain the upper end of the range.

Because of the way the min() function is implemented, avoid using other functions inside the brackets, 
it may lead to incorrect results
*/


min(a++, 100);  // avoid this - yields incorrect results

min(a, 100);
a++;  // use this instead - keep other math outside the function


//-----------------------------------------------------------------------------------------------------------------//

// pow()

/*
Description
Calculates the value of a number raised to a power. pow() can be used to raise a number to a fractional power.
This is useful for generating exponential mapping of values or curves.

Syntax
Use the following function to raise a number to a given power:

pow(base, exponent)

Parameters
The function admits the following parameters:

base: the function input number to compute. Allowed data types: float.
exponent: the power to which the base is raised. Allowed data types: float.

Returns
The function returns the result of the exponentiation. Data type: double.

Example Code
Calculate the value of x raised to the power of y:
*/


float x = 2.0;  // base number
float y = 10.0;  // exponent number

void setup() {
  Serial.begin(9600);

  double z = pow(x, y);

  Serial.print("The power result is: ");
  Serial.println(z);
}

void loop() {
}


//-----------------------------------------------------------------------------------------------------------------//

// sq()

/*
Description
Calculates the square of a number: the number multiplied by itself.

Syntax
Use the following function to compute the square of a number:

sq(x)

Parameters
The function admits the following parameter:

x: the input number. Allowed data types: any data type.

Returns
The function returns the square of the number. Data type: double.

Example Code
Calculate the square of x:
*/


float x = 2.0;  

void setup() {
  Serial.begin(9600);

  double square = sq(x);

  Serial.print("The result is: ");
  Serial.println(square);
}

void loop() {
}


/*
Notes and Warnings
Because of the way the sq() function is implemented, avoid using other functions inside the brackets, 
it may lead to incorrect results.

This code will yield incorrect results:
*/


int inputSquared = sq(Serial.parseInt()); // avoid this

// Use this instead:

int input = Serial.parseInt();  // keep other operations outside the sq function
int inputSquared = sq(input);


//-----------------------------------------------------------------------------------------------------------------//

// sqrt()

/*
Description
The function sqrt() calculates the square root of a number.

Syntax
Use the following function to find the square root of a given number:

sqrt(x)

Parameters
The function admits the following parameter:

x: the number to find the square root of. Allowed data types: any data type.

Returns
The function returns the input number’s square root. Data type: double.

Example Data
Calculate the square root of the x variable:
*/


float x = 9.0;  

void setup() {
  Serial.begin(9600);

  double root = sqrt(x);

  Serial.print("The square root is: ");
  Serial.println(root);
}

void loop() {
}


// All Material is made and referenced by: ArduinoDocs at https://docs.arduino.cc/language-reference/#functions