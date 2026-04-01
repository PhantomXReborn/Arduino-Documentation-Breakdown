
// bit()

/*
Description
Create a bitmask with a single bit set at a specific position. Useful for bitwise operations, 
like setting, clearing, or testing specific bits in a byte or register.

Syntax
Use the following function to set the bit state on the n position:

bit(n)

Parameters
The function admits the following parameter:

n: the bit position whose value to compute. Note that n needs to be between 0-31 (32 bit). Position 0 is the least-significant (rightmost) bit.

Returns
The function returns an unsigned byte (aka uint8_t) with only bit n set to 1, and all others set to 0.

Example Code
Modify a given byte x by turning its 6th bit to 1:
*/


uint8_t x = 0b00000000; // initial byte 

void setup() {
  Serial.begin(9600);
  
  int index = 6; // index of the bit to modify
  
  x |= bit(index-1);

  Serial.print("The resulting byte is: ");
  Serial.println(x, BIN);
 
}

void loop() {
}


/*
Note
This is what the bit() function does behind the scenes:
*/

#define bit(n) (1 << (n))


//-----------------------------------------------------------------------------------------------------------------//

// bitClear()

/*
Description
Clears (writes a 0 to) a bit of a numeric variable at a specific position. 
Useful when you're doing low-level bit manipulation, especially when working with hardware registers, flags, or memory-mapped I/O.

Syntax
Use the following function to clear the bit state on the n position of the x variable:

bitClear(x, n)

Parameters
The function admits the following parameters:

x: the numeric variable whose bit to clear.
n: which bit to clear, starting at 0 for the least-significant (rightmost) bit.
Returns
The function returns the value of the numeric variable after the bit at position n is cleared.

Example Code
Modify a given byte x by turning its 6th bit to 0:
*/


uint8_t x = 0b11111111; // initial byte 

void setup() {
  Serial.begin(9600);
  
  int index = 6; // index of the bit to modify
  
  x = bitClear(x, index-1);

  Serial.print("The resulting byte is: ");
  Serial.println(x, BIN);
 
}

void loop() {
}


/*
Note
This is what the bitClear() function does behind the scenes:
*/


#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))


//-----------------------------------------------------------------------------------------------------------------//

// bitRead()

/*
Description
Reads a bit of a variable on a specific position, e.g. bool, int. Note that float & double are not supported. 
You can read the bit of variables up to an unsigned long long (64 bits / 8 bytes).

Syntax
Use the following function to read the bit state on the n position of the variable x:

bitRead(x, n)

Parameters
The function admits the following parameters:

x: the variable from which to read.
n: which bit to read, starting at 0 for the least-significant (rightmost) bit.

Returns
The function returns the value of the bit (0 or 1).

Example Code
This example code demonstrates how to read two variables, one increasing counter, one decreasing counter, 
and print out both the binary and decimal values of the variables.

The readBit() function loops through each bit of the variable (starting from the rightmost bit), and prints it out.
*/


long negative_var = -0;  //
unsigned long long positive_var = 0;

//predefined sizes when looping through bits
//e.g. long_size is 32 bit (which is 0-31). Therefore, we subtract "1".
const int bool_size = (1 - 1);
const int int_size = (8 - 1);
const int long_size = (32 - 1);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //run readBit function, passing the pos/neg variables
  readBit("Positive ", positive_var);
  readBit("Negative ", negative_var);
  Serial.println();

  //increase and decrease the variables
  negative_var--;
  positive_var++;

  delay(1000);
}

/*this function takes a variable, prints it out bit by bit (starting from the right)
then prints the decimal number for comparison.*/
void readBit(String direction, long counter) {
  Serial.print(direction + "Binary Number: ");
  //loop through each bit
  for (int b = long_size; b >= 0; b--) {
    byte bit = bitRead(counter, b);
    Serial.print(bit);
  }
  Serial.print(" Decimal Number: ");
  Serial.println(counter);
}


//-----------------------------------------------------------------------------------------------------------------//

// bitSet()

/*
Description
Sets (writes a 1 to) a bit of a numeric variable at a specific position. Useful when you're doing low-level bit manipulation, 
especially when working with hardware registers, flags, or memory-mapped I/O.

Syntax
Use the following function to set the bit state on the n position of the x variable:

bitSet(x, n)

Parameters
The function admits the following parameters:

x: the numeric variable whose bit to set.
n: which bit to set, starting at 0 for the least-significant (rightmost) bit.

Returns
The function returns the value of the numeric variable after the bit at position n is set.

Example Code
Modify a given byte x by turning its 5th bit to 1:
*/


uint8_t x = 0b10000001; // initial byte 

void setup() {
  Serial.begin(9600);
  
  int index = 5; // index of the bit to modify
  
  x = bitSet(x, index-1);

  Serial.print("The resulting byte is: ");
  Serial.println(x, BIN);
 
}

void loop() {
}


/*
Note
This is what the bitSet() function does behind the scenes:
*/


#define bitSet(value, bit) ((value) |= (1UL << (bit)))


//-----------------------------------------------------------------------------------------------------------------//

// bitWrite()

/*
Description
Writes to a bit of a variable, e.g. bool, int, long. Note that float & double are not supported. 
You can write to a bit of variables up to an unsigned long (32 bits / 4 bytes).

Syntax
Use the following function to freely modify the bit state on the n position of the x variable:

bitWrite(x, n, b)

Parameters
The function admits the following parameters:

x: the numeric variable whose bit to modify.
n: which bit of the number to write, starting at 0 for the least-significant (rightmost) bit.
b: the value to write to the bit (0 or 1).
Returns
The function returns nothing.

Example Code
Demonstrates the use of bitWrite by printing the value of a variable to the Serial Monitor before and after the use of bitWrite().
*/


void setup() {
  Serial.begin(9600);
  while (!Serial) {}  // wait for serial port to connect. Needed for native USB port only
  byte x = 0b10000000;  // the 0b prefix indicates a binary constant
  Serial.println(x, BIN); // 10000000
  bitWrite(x, 0, 1);  // write 1 to the least significant bit of x
  Serial.println(x, BIN); // 10000001
}

void loop() {
}


//-----------------------------------------------------------------------------------------------------------------//

// highByte()

/*
Description
Extracts the high (most significant) 8 bits from a 16-bit integer (int, unsigned int, etc.), 
or the second lowest byte of a larger data type. Useful when you are dealing with communication protocols (like I2C, SPI, serial)
where data must be sent in bytes, or when manually splitting numbers.

Syntax
Use the following function to extract the most significant 8 bits from a 16 bit variable:

highByte(x)

Parameters
The function admits the following parameter:

x: input variable to extract from. Data type: any type.

Returns
The function returns the byte extracted from the original variable. Data type: byte.

Example Code:
*/


unsigned int x = 0xABCD; // Hexadecimal 43981

void setup() {
  Serial.begin(9600);
  
  byte high = highByte(x);  // Extracts 0xAB (171 decimal)

  Serial.print("The high byte is: ");
  Serial.println(high, HEX);  // Prints "AB"
 
}

void loop() {
}


/*
Note
This is what the highByte() function does behind the scenes:
*/


#define highByte(w) ((uint8_t) (((w) >> 8) & 0xFF))


//-----------------------------------------------------------------------------------------------------------------//

// lowByte()

/*
Description
Extracts the low (rightmost) 8 bits from a larger data type. Useful when you are dealing with communication protocols (like I2C, SPI, serial) 
where data must be sent in bytes, or when manually splitting numbers.

Syntax
Use the following function to extract the first 8 bits from a variable:

lowByte(x)

Parameters
The function admits the following parameter:

x: input variable to extract from. Data type: any type.

Returns
The function returns the byte extracted from the original variable. Data type: byte.

Example Code:
*/


unsigned int x = 0xABCD; // Hexadecimal 43981

void setup() {
  Serial.begin(9600);
  
  byte low = lowByte(x);  // Extracts 0xAB (171 decimal)

  Serial.print("The low byte is: ");
  Serial.println(low, HEX);  // Prints "CD"
 
}

void loop() {
}


/*
Note
This is what the lowByte() function does behind the scenes:
*/


#define lowByte(w) ((uint8_t) ((w) & 0xFF))


// All Material is made and referenced by: ArduinoDocs at https://docs.arduino.cc/language-reference/#functions