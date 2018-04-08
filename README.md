# Ricordi
This repository contains an Arduino project that reminds patients with congestive heart failure to use a scale provided by Humana. The scale is used to keep track of fluctuations of their weight daily in order to prevent expensive hospital visits. The project uses a PIR Motion Sensor, LED strip lights and a mini speaker.

Table of contents
=================

<!--ts-->
   * [About](#about)
   * [Features](#features)
   * [Photos](#photos)
   * [Getting Started](#getting-started)
      * [Prerequisites](#prerequisites)
      * [Deployment](#deployment)
   * [Contact](#contact)
   * [License](#license)
<!--te-->

## About

This is an add-on to an existing project by Humana. My team was given a digital scale that sends weight data to a server. Scales were distributed to patients with congestive heart failure by their doctors and patients are supposed to weigh in every day to keep track of fluctuations in their weight. If the weight gain passes a treshold it’ll raise an alarm with the nurse working for the doctor that proided the scale and the nurse will call and ask the patient if they're okay. If the patient doesn’t weigh in by 11AM they would receive a call to make sure everything is okay and to remind the patient to weigh in.
This particular repository contains the code that was uploaded to the Arduino to activate the lights, gently pulsate and play a sound to remind the patient to weigh in.


## Features
- The code includes notes and note durations for the sound
- If the PIR sensor detects motion, the Arduino will first play a sound, then cycle through colors and fade slowly. The speed at which the color cycle is completed can be changed by modifying "fadespeed"
- In this repository there are two songs that can be chosen
- Lights can cycle throught all colors or simply pulsate with one color


## Photos



## Getting Started

#### Prerequisites
- Arduino board
- LED light strip
- PIR Motion Sensor
- Mini Speaker
- 9V power plug recommended 

#### Deployment
* Download [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* Upload code to Arduino board
* Wire connect lights, motion sensor and speaker to appropriate pins
* 9V power plug allows the LED to be brighter


## Contact
* [Yani Mihaylov](https://www.linkedin.com/in/yani-mihaylov/) for questions about this repository

## License

Arduino
