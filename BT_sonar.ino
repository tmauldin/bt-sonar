#include "Maxbotix.h"

Maxbotix rangeSensorPW(10, Maxbotix::PW, Maxbotix::LV, Maxbotix::MEDIAN);

//left vibe
int leftVibe = 6;

//right vibe
int rightVibe = 16;

void setup()  { 
  // for debugging
  Serial.begin(9600);
  
  pinMode(leftVibe, OUTPUT);
  pinMode(rightVibe, OUTPUT);
  digitalWrite(leftVibe, LOW); 
  digitalWrite(rightVibe, LOW);
}

void loop()  { 
  
  // get distance
  float readingCm = rangeSensorPW.getRange();
  
  write_it(readingCm);
  Serial.print(readingCm);
  Serial.print("cm\n");  
  
  delay(50);                            
}

void write_it(float range)
{
  if ((int)range < 25)
  {
    digitalWrite(leftVibe, HIGH); 
    digitalWrite(rightVibe, HIGH);
  }
  else
  {
    digitalWrite(leftVibe, LOW); 
    digitalWrite(rightVibe, LOW);
    Serial.print("here\n");
  }

//  if (range > 60)
//    return 0;
//  if (range > 50)
//    return 100;
//  if (range > 40)
//    return 110;
//  if (range > 30)
//    return 130;
//  if (range > 20)
//    return 150;
//  if (range > 18)
//    return 200;
//  return 255;

}








