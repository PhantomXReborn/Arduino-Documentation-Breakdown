
// noTone()

/*
Description
Stops the generation of a square wave triggered by tone(). Has no effect if no tone is being generated.

Syntax
Use the following function to stop a tone:

noTone(pin)

Parameters
The function admits the following parameter:

pin: the Arduino pin on which to stop generating the tone.

Returns
The function returns nothing.

Example Code
Generate a square wave on pin D0 for a second and then stop it repetitively.
*/

#define BUZZER_PIN D0 // Example pin

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, 1000); // 1 kHz tone
  delay(1000);
  noTone(BUZZER_PIN);      // Stop the tone
  delay(1000);
}

/*
Notes and Warnings
If you want to play different pitches on multiple pins, you need to call noTone() on one pin before calling tone() on the next pin.
*/