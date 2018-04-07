/*
 * PIR sensor tester
 */
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 5
#include"pitches.h"


int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int tempo[] = {
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 6,
 
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
 
  5, 5, 5,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
 
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
 
  5, 5, 5,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
};

//Victory sound
int victoryMelody[] = {
  262, 196,196, 220, 196,0, 247, 262};
  
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

  int speed=90;  //higher value, slower notes
 
int ledPin = 13;                // choose the pin for the LED
int pirPin = 7;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  pinMode(LEDpin, OUTPUT);
  
  Serial.begin(9600);
}
 
void loop(){

  //values for light strip
  int r, g, b;

 /* fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading); 

  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
  */

/*  if (fsrReading > 100){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
      tone(13, victoryMelody[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(13);
      }
  }*/
  
  
  val = digitalRead(pirPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");

      //super mario theme song
                    Serial.println(" 'Mario Theme'");
                    int size = sizeof(melody) / sizeof(int);
                    for (int thisNote = 0; thisNote < size; thisNote++) {
                 
                      // to calculate the note duration, take one second
                      // divided by the note type.
                      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
                      int noteDuration = 1000 / tempo[thisNote];
                 
                      tone(13, melody[thisNote],noteDuration*0.95);
                 
                      // to distinguish the notes, set a minimum time between them.
                      // the note's duration + 30% seems to work well:
                      int pauseBetweenNotes = noteDuration * 1.3;
                      delay(noteDuration);
                 
                      // stop the tone playing:
                      noTone(13);
                    } 
      
            for (r = 0; r < 256; r++) { 
              analogWrite(REDPIN, r);
              analogWrite(BLUEPIN, r);
              delay(FADESPEED);
            } 
            // fade from violet to red
            for (b = 255; b >= 0; b--) { 
              analogWrite(BLUEPIN, b);
              delay(FADESPEED);
            } 
            // fade from red to yellow
            for (g = 0; g < 256; g++) { 
              analogWrite(GREENPIN, g);
              delay(FADESPEED);
            } 
            // fade from yellow to green
            for (r = 255; r >= 0; r--) { 
              analogWrite(REDPIN, r);
              delay(FADESPEED);
            } 
            // fade from green to teal
            for (b = 0; b < 256; b++) { 
              analogWrite(BLUEPIN, b);
              delay(FADESPEED);
            } 
            // fade from teal to blue
            for (g = 255; g >= 0; g--) { 
              analogWrite(GREENPIN, g);
              delay(FADESPEED);
            } 
      // We only want to print on the output change, not state
      pirState = HIGH;

                
    }
  } 
  else {
    digitalWrite(pirPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
//              analogWrite(GREENPIN, 0);
//              analogWrite(BLUEPIN, 0);
//              analogWrite(REDPIN, 0);

              for(b = 255; b>=0; b--){
                analogWrite(BLUEPIN, b);
                delay(FADESPEED);

              }
    /*  for (g = 255; g >= 0; g--) { 
              analogWrite(GREENPIN, g);
              analogWrite(BLUEPIN, g);
              analogWrite(REDPIN, g);
              delay(FADESPEED);
            } */
      

      // We only want to print on the output change, not state
      pirState = LOW;

        
    }
  }

  delay(500);
}
