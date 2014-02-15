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
int pwmOut1 = 11;
int pwmOut2 = 12;
int pwmOut3 = 2;
int pwmOut4 = 3;
int32_t frequency = 10000; //frequency (in Hz)

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success1 = SetPinFrequencySafe(pwmOut1, frequency);
  bool success2 = SetPinFrequencySafe(pwmOut2, frequency);
  bool success3 = SetPinFrequencySafe(pwmOut3, frequency);
  bool success4 = SetPinFrequencySafe(pwmOut4, frequency);


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
  pwmWrite(pwmOut1, 128);
  pwmWrite(pwmOut2, 128);
  pwmWrite(pwmOut3, 128);
  pwmWrite(pwmOut4, 128);
  
  delay(60);
      
}


