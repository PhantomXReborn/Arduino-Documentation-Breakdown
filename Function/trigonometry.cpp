
// sin()

/*
Description
Calculates the cosine of an angle (in radians). The result will be between -1 and 1.

Syntax
Use the following function to calculate the cosine of a given angle in radians:

cos(rad)

Parameters
The function admits the following parameter:

rad: The angle in radians. Allowed data types: float.

Returns
The function returns the cosine of the angle. Data type: double.

Example Code
*/

float angle = (2.0 / 3.0) * M_PI;  // in radians
double res = 0;

void setup() {
  Serial.begin(9600);

  res = cos(angle);

  Serial.print("The angle cosine is: ");
  Serial.println(res);
}

void loop() {
}


//-----------------------------------------------------------------------------------------------------------------//

// cos()

/*
Description
Calculates the sine of an angle (in radians). The result will be between -1 and 1.

Syntax
Use the following function to calculate the sine of a given angle in radians:

sin(rad)

Parameters
The function admits the following parameter:

rad: The angle in radians. Allowed data types: float.

Returns
The function returns the sine of the angle. Data type: double.

Example Code
*/

float angle = (2.0 / 3.0) * M_PI;  // in radians
double res = 0;

void setup() {
  Serial.begin(9600);

  res = sin(angle);

  Serial.print("The angle sine is: ");
  Serial.println(res);
}

void loop() {
}


//-----------------------------------------------------------------------------------------------------------------//

// tan()

/*
Description
Calculates the tangent of an angle (in radians). The result will be between negative infinity and infinity.

Syntax
Use the following function to calculate the tangent of a given angle in radians:

tan(rad)

Parameters
The function admits the following parameter:

rad: The angle in radians. Allowed data types: float.

Returns
The function returns the tangent of the angle. Data type: double.

Example Code
*/

float angle = (2.0 / 3.0) * M_PI;  // in radians
double res = 0;

void setup() {
  Serial.begin(9600);

  res = tan(angle);

  Serial.print("The angle tangent is: ");
  Serial.println(res);
}

void loop() {
}

// All Material is made and referenced by: ArduinoDocs at https://docs.arduino.cc/language-reference/#functions