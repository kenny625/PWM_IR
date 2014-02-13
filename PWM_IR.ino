/*

 Mimics the fade example but with an extra parameter for frequency. It should dim but with a flicker 
 because the frequency has been set low enough for the human eye to detect. This flicker is easiest to see when 
 the LED is moving with respect to the eye and when it is between about 20% - 60% brighness. The library 
 allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers. When 
 SetPinFrequency()/SetPinFrequencySafe() is called, a bool is returned which can be tested to verify the 
 frequency was actually changed.
 
 This example runs on mega and uno.
 */

#include <PWM.h>

//use pin 11 on the Mega instead, otherwise there is a frequency cap at 31 Hz
int pwmOut = 11;                // the pin that the LED is attached to
int32_t frequency = 10000; //frequency (in Hz)
int sensorPin = A0;
int sensorValue = 0;
int sum = 0;
int count = 0;
int preValue = 0;
int alpha = 0.5;

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(pwmOut, frequency);
  //  bool success2 = SetPinFrequencySafe(12, frequency);


  Serial.begin(9600);
//  analogReference(INTERNAL2V56);
  //if the pin frequency was set successfully, turn pin 13 on
  //  if(success) {
  //    pinMode(13, OUTPUT);
  //    digitalWrite(13, HIGH);    
  //  }
}

void loop()
{
  //use this functions instead of analogWrite on 'initialized' pins
  pwmWrite(pwmOut, 128);
  //  pwmWrite(12, 180);
  sensorValue = analogRead(sensorPin);
  sum += sensorValue;
//  if(preValue == 0){
//    preValue = sensorValue;
//  } 
//  int temp = sensorValue/10*alpha + preValue*(1-alpha);
delay(30);
  Serial.println(analogRead(A1));
//  sum += temp;
//  preValue = temp;
  count++;
  if(count == 10){
    count = 0;
//    Serial.println(sum/10);
    sum = 0;
  }
  delay(30);      
}


