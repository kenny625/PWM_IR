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
int max = 0;
int min = 9999;
int temp[10];

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(pwmOut, frequency);
//  bool success2 = SetPinFrequencySafe(12, frequency);
  
  
  Serial.begin(9600);
  
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
  temp[count] = sensorValue;
//  sum += sensorValue;
  count++;
  if(sensorValue > max){
    max = sensorValue;
  }
  if(sensorValue < min){
    min = sensorValue;
  }
  if(count == 10){
    count = 0;
    int i;
    for(i=0;i<10;i++){
      if(temp[i] != max && temp[i] != min){
        sum += temp[i];
      }
    }
    Serial.println(sum/8);
    sum = 0;
    max = 0;
    min = 9999;
  }
  delay(30);      
}

