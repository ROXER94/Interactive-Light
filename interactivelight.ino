//Empty string declaration
String Song;
// LED connected to digital pin D0
const int greenPin = D0;
// LED connected to digital pin D1
const int redPin = D1;
// Speaker connected to digital D2
const int Sound = D2;
// LED connected to digital pin D3
const int bluePin = D3;
// Button connected to digital pin 10
const int buttonPin = A0;
// Potentiometer connected to analog A1
const int Potentiometer = A1;
// initialize value as a long for use in the map function
long value;
// notes in the melody:
int melody[] = {0,0,0,0,0,0,0,0};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,4,4,4,4,4,4,4};
// Length of a dash in ms
const int dash = 300;
// length of a dot in ms
const int dot = 100;
// state of the button this iteration
byte current_button = LOW;
// previous state of the button
byte old_button = LOW;
// start of a pressed event
unsigned long int start_high;
// end of a pressed event
unsigned long int stop_high;
// start of a non-pressed event
unsigned long int start_low;
// end of a non-pressed event
unsigned long int stop_low;

// The setup() method runs once,
// when the sketch starts
void setup() {
// initialize the digital pins as an output:
pinMode(greenPin, OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);
// initialize the Speaker pin as an output:
pinMode(Sound, OUTPUT);
// initialize the button pin as an input:
pinMode(buttonPin, INPUT);
// Set up serial communication
Serial.begin(9600);
}

byte read_button(byte pin, byte ref_value) {
  // observed the state of the button
  byte current_button = digitalRead(pin);
  // There is a LOW -> HIGH transition
  // or a HIGH -> LOW transition
  if (((ref_value == LOW) && (current_button == HIGH)) || ((ref_value == HIGH) && (current_button == LOW))) {
    // wait for a while (5ms)
    delay(5);
    // update the state of the button
    current_button = digitalRead(pin);
  }
return(current_button);
}

void loop() {
value = analogRead(Potentiometer);
value = map(value,0,4095.0,0,255.0);

digitalWrite(greenPin, LOW); // set the greenLED off
digitalWrite(bluePin, LOW); // set the blueLED off
digitalWrite(redPin, LOW); // set the redLED off
// Read the current state
current_button = read_button(buttonPin, old_button);
// LOW -> HIGH transition
if ((old_button== LOW) && (current_button== HIGH)) {
  // Update timing
  start_high = millis();
  stop_low = start_high;
  }

// HIGH-> LOW transition
if ((old_button== HIGH) && (current_button== LOW)) {
  // Update timing
  stop_high = millis();
  start_low = stop_high;

  // detect dashs and dots
  if ((stop_high - start_high) >= 1.5*dash) {
    Song = Song + "-";
    digitalWrite(greenPin, HIGH); // set the greenLED on
    delay(250);
    Serial.write("\nCrafting Song:" + Song);
    } else {
        Song = Song + ".";
        digitalWrite(redPin, HIGH); // set the redLED on
        delay(250);
        Serial.write("\n Crafting Song:" + Song);

  }
}
old_button = current_button;

//Song Number correlates to 8 possible inputs (2^3 combinations)
if (Song.length() >= 3){
  //Song 1
  if (Song == "---"){
    int melody[] = {1908,2551,2551,2273,2551,0,2024,1908};
    Serial.write("\nSong Number: 1");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(redPin, LOW); // set the redLED off
        digitalWrite(greenPin, LOW); // set the greenLED off
        analogWrite(bluePin, value); // set the blueLED on
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }

  //Song 2
  }else if (Song == "--."){
    int melody[] = {2004,1908,2444,2444,0,1850,0,2004};
    Serial.write("\nSong Number: 2");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 3
  }else if (Song == "-.."){
    int melody[] = {1680,2410,1680,2410,2121,2121,2589,3100};
    Serial.write("\nSong Number: 3");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 4
  }else if (Song == "..."){
    int melody[] = {1980,2312,2202,0,1740,2072,1962,0};
    Serial.write("\nSong Number: 4");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 5
  }else if (Song == ".--"){
    int melody[] = {3875,3475,3075,2675,2275,1875,1475,1075};
    Serial.write("\nSong Number: 5");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 6
  }else if (Song == "..-"){
    int melody[] = {1820,2754,2980,1820,2754,2980,2698,2386};
    Serial.write("\nSong Number: 6");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 7
  } else if (Song == "-.-"){
    int melody[] = {1111,1444,1777,2222,2222,1777,1444,1111};
    Serial.write("\nSong Number: 7");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  //Song 8
  } else if (Song == ".-."){
    int melody[] = {2050,2610,2204,1895,2050,2610,1950,2222};
    Serial.write("\nSong Number: 8");
    for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000/noteDurations[thisNote];
        tone(Sound, melody[thisNote],noteDuration);
        digitalWrite(greenPin, LOW); // set the greenLED off
        digitalWrite(redPin, LOW); // set the redLED off
        analogWrite(bluePin, value); // set the blueLED on

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(Sound);
        Song = "";
      }
  }else{
    Song = "";
  }
}
}
